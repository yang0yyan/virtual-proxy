#pragma once
#include
#include
#include

class RingBuffer { public: explicit RingBuffer(size_t capacity) : buf_(capacity), capacity_(capacity), head_(0), tail_(0) {}

	bool push(const uint8_t* data, size_t len) {
		size_t tail = tail_.load(std::memory_order_relaxed);
		size_t head = head_.load(std::memory_order_acquire);
		size_t free = capacity_ - (tail - head);
		if (len > free) return false;
		size_t idx = tail % capacity_;
		if (idx + len <= capacity_) {
			memcpy(&buf_[idx], data, len);
		} else {
			size_t first = capacity_ - idx;
			memcpy(&buf_[idx], data, first);
			memcpy(&buf_[0], data + first, len - first);
		}
		tail_.store(tail + len, std::memory_order_release);
		return true;
	}


	bool pop(uint8_t* out, size_t len) {
		size_t head = head_.load(std::memory_order_relaxed);
		size_t tail = tail_.load(std::memory_order_acquire);
		size_t used = tail - head;
		if (len > used) return false;
		size_t idx = head % capacity_;
		if (idx + len <= capacity_) {
			memcpy(out, &buf_[idx], len);
		} else {
			size_t first = capacity_ - idx;
			memcpy(out, &buf_[idx], first);
			memcpy(out + first, &buf_[0], len - first);
		}
		head_.store(head + len, std::memory_order_release);
		return true;
	}

	private: std::vector<uint8_t> buf_; size_t capacity_; std::atomic<size_t> head_; std::atomic<size_t> tail_; 
};