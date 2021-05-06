#pragma once

template <typename T>
class IQueue {
public:
	virtual void push(T element) = 0;
	virtual T pop() = 0;
	virtual bool isEmpty() = 0;
	virtual unsigned int getSize() = 0;
};