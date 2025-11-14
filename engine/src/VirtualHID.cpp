#include "VirtualHID.h" #include

VirtualHID::VirtualHID() : driverHandle_(nullptr) {} VirtualHID::~VirtualHID() {}

bool VirtualHID::create(const std::string& name) { std::cout << "[VirtualHID] create: " << name << "\n"; return true; }

bool VirtualHID::writeInputReport(const uint8_t* buf, size_t len) { (void)buf; (void)len; return true; }

bool VirtualHID::readOutputReport(std::vector<uint8_t>& out) { return false; }