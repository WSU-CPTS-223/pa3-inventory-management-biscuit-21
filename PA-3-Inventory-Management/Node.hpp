#pragma once

#include "Data.hpp"

template <typename T>
class Node {
public:

	Node() {
		this->pData = nullptr;
		this->pNext = nullptr;
	}

	Node(T* newPData, Node<T>* newPNext) {
		this->pData = newPData;
		this->pNext = newPNext;
	}

	Node(const Node<T>& rhs) {
		if (rhs.pData != nullptr) {
			this->pData = new T(*rhs.pData);
		}
		else {
			this->pData = nullptr;
		}
		this->pNext = rhs.pNext;
	}

	Node<T>& operator=(const Node<T>& rhs) {
		if (this != &rhs) {
			delete this->pData;
			if (rhs.pData != nullptr) {
				pData = new T(*rhs.pData);
			}
			else{
				this->pData = nullptr;
			}
			this->pData = rhs.pData;
			this->pNext = rhs.pNext;
		}
		return *this;
	}

	~Node() {
		delete pData;
	}

	//setters
	void setPT(T* newPData) {
		this->pData = newPData;
	}
	void setPNext(Node<T>* newPNext) {
		this->pNext = newPNext;
	}

	//getters
	T* getPT() const {
		return this->pData;
	}
	Node<T>* getPNext() const {
		return this->pNext;
	}

private:
	T* pData;
	Node<T>* pNext;
};