#pragma once #include #include #include "RingBuffer.h"

class AudioWorker { public: AudioWorker(RingBuffer* outRing); ~AudioWorker(); void enqueue(const uint8_t* data, size_t len); void start(); void stop(); private: RingBuffer* outRing_; bool running_ = false; };