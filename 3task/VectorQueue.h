#pragma once
#include <assert.h>
#include "IQueue.h"

#define ARRAY_SIZE 100

template <typename T>
class VectorQueue : public IQueue<T> {
private:
	T* arr;
	unsigned int front;
	unsigned int back;
	unsigned int size;
	void resize(const unsigned int new_size) {
		assert(new_size >= size);
		T* new_arr = new T[new_size];
		if (front > back) {
			for (int i = back; i < front; i++) {
				new_arr[i] = arr[i];
			}
		}
		else {
			for (int i = 0; i < front; i++) {
				new_arr[i] = arr[i];
			}
			for (int i = back; i < size; i++) {
				new_arr[new_size - (size - i)] = arr[i];
			}
			back = new_size - (size - back);
		}
		delete[] arr;
		arr = new_arr;
		size = new_size;
	}
public:
	VectorQueue() {
		arr = new T[ARRAY_SIZE];
		size = ARRAY_SIZE;
		front = 0;
		back = 0;
	}
	void push(T data) {
		if (size - getSize() > 1) {
			arr[front] = data;
			front = (front + 1) % size;
		}
		else {
			resize(size + ARRAY_SIZE);
			push(data);
		}
	}
	T pop() {
		assert(!isEmpty());
		T data = arr[back];
		back = (back + 1) % size;
		return data;
	}
	unsigned int getSize() {
		if (back > front) {
			return size - back + front;
		}
		else {
			return front - back;
		}
	}
	bool isEmpty() {
		return front == back;
	}
};