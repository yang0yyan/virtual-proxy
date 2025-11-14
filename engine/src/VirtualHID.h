#pragma once
#include
#include

class VirtualHID { public: VirtualHID(); ~VirtualHID(); bool create(const std::string& name); bool writeInputReport(const uint8_t* buf, size_t len); bool readOutputReport(std::vector<uint8_t>& out); private: void* driverHandle_; };