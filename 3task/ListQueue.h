#pragma once
#include <assert.h>

#include "IQueue.h"
#include "ListNode.h"

template <typename T>
class ListQueue : public IQueue<T> {
private:
	ListNode<T>* front;
	ListNode<T>* back;
	unsigned int size;
public:
	ListQueue() {
		front = nullptr;
		back = nullptr;
		size = 0;
	}
	ListQueue(T data) {
		front = new ListNode<T>(data);
		back = front;
		size = 1;
	}
	void push(T data) {
		if (size == 0) {
			front = new ListNode<T>(data);
			back = front;
			size = 1;
			return;
		}
		ListNode<T>* prev = new ListNode<T>(data);
		front->setPrev(prev);
		front = prev;
		size++;
	}
	T pop() {
		assert(size > 0);
		if (size == 1) {
			T data = back->getData();
			delete back;
			front = nullptr;
			back = front;
			size = 0;
			return data;
		}
		T data = back->getData();
		ListNode<T>* newBack = back->getPrev();
		delete back;
		back = newBack;
		size--;
		return data;
	}
	bool isEmpty() {
		return size == 0;
	}
	unsigned int getSize() {
		return size;
	}
};