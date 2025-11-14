#include "BluetoothSender.h" #include #include

BluetoothSender::BluetoothSender(RingBuffer* outRing) : outRing_(outRing) {} BluetoothSender::~BluetoothSender() { stop(); }

void BluetoothSender::start() { running_ = true; std::thread(this{ while (running_) { std::this_thread::sleep_for(std::chrono::milliseconds(5)); } }).detach(); }

void BluetoothSender::stop() { running_ = false; }