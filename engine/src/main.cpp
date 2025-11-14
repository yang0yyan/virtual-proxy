#include #include #include "RingBuffer.h" #include "VirtualHID.h" #include "RealDeviceIO.h" #include "AudioWorker.h" #include "BluetoothSender.h"

int main() { std::cout << "DualSense Proxy Engine starting...\n";

VirtualHID virtualDev;
if (!virtualDev.create("DualSense Virtual")) {
    std::cerr << "Failed create virtual device\n";
    return -1;
}


RealDeviceIO realDev;
realDev.openByVidPid(0x054C, 0x0CE6);


RingBuffer outRing(1024*1024);
RingBuffer inRing(64*1024);


AudioWorker audioWorker(&outRing);
audioWorker.start();


BluetoothSender btSender(&outRing);
btSender.start();


std::thread inputThread([&](){
    uint8_t buf[512];
    while (true) {
        size_t len = realDev.readInput(buf, sizeof(buf));
        if (len>0) {
            virtualDev.writeInputReport(buf, len);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
});


std::thread outputThread([&](){
    while (true) {
        std::vector<uint8_t> out;
        if (virtualDev.readOutputReport(out)) {
            if (!out.empty()) {
                audioWorker.enqueue(out.data(), out.size());
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
});


inputThread.join();
outputThread.join();


return 0;

}