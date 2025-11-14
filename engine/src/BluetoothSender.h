#pragma once #include "RingBuffer.h"

class BluetoothSender { public: BluetoothSender(RingBuffer* outRing); ~BluetoothSender(); void start(); void stop(); private: RingBuffer* outRing_; bool running_ = false; };