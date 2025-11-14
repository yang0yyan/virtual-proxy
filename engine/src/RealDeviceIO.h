#pragma once #include #include

class RealDeviceIO { public: RealDeviceIO(); ~RealDeviceIO(); bool openByVidPid(uint16_t vid, uint16_t pid); size_t readInput(uint8_t* buf, size_t bufSize); bool writeOutput(const uint8_t* buf, size_t len); private: void* handle_; };