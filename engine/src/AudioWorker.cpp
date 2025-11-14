#include "AudioWorker.h" #include #include

AudioWorker::AudioWorker(RingBuffer* outRing) : outRing_(outRing) {} AudioWorker::~AudioWorker() { stop(); }

void AudioWorker::enqueue(const uint8_t* data, size_t len) { (void)data; (void)len; }

void AudioWorker::start() { running_ = true; std::thread(this{ while (running_) { std::this_thread::sleep_for(std::chrono::milliseconds(10)); } }).detach(); }

void AudioWorker::stop() { running_ = false; }