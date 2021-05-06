#pragma once

template <typename T>
class ListNode {
private:
	T data;
	ListNode* prev;
public:
	ListNode() {
		this->data = NULL;
		prev = nullptr;
	}
	ListNode(T data) {
		this->data = data;
		prev = nullptr;
	}
	ListNode(T data, ListNode* prev) {
		this->data = data;
		this->prev = prev;
	}
	T getData() {
		return data;
	}
	void setData(T data) {
		this->data = data;
	}
	ListNode* getPrev() {
		return prev;
	}
	void setPrev(ListNode* prev) {
		this->prev = prev;
	}
	~ListNode() {}
};