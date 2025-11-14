#include "RealDeviceIO.h" #include RealDeviceIO::RealDeviceIO() : handle_(nullptr) {} RealDeviceIO::~RealDeviceIO() {}

bool RealDeviceIO::openByVidPid(uint16_t vid, uint16_t pid) { std::cout << "[RealDeviceIO] open vid=0x" << std::hex << vid << " pid=0x" << pid << std::dec << "\n"; return true; }

size_t RealDeviceIO::readInput(uint8_t* buf, size_t bufSize) { (void)buf; (void)bufSize; return 0; }

bool RealDeviceIO::writeOutput(const uint8_t* buf, size_t len) { (void)buf; (void)len; return true; }