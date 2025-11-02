#pragma once

#include "Node.hpp"

template <typename T>
class List {
public:

	List() {
		this->pHead = nullptr;
		this->pTail = nullptr;
	}

	List(Node<T>* newPHead, Node<T>* newPTail) {
		this->pHead = newPHead;
		this->pTail = newPTail;
	}

	List(const List<T>& rhs) {
		this->pHead = nullptr;
		this->pTail = nullptr;
		Node<T>* pCur = rhs.pHead;
		// deep copies the List of rhs
		while (pCur != nullptr) {
			this->enqueue(new T(*pCur->getPT()));
			pCur = pCur->getPNext();
		}
	}	

	List<T>& operator=(const List<T>& rhs) {
		if (this != &rhs) {
			while (!isEmpty()) {
				delete dequeue();
			}
			Node<T>* pCur = rhs.pHead;
			//deep copies the queue of rhs
			while (pCur != nullptr) {
				this->enqueue(new T(*pCur->getPT()));
				pCur = pCur->getPNext();
			}
		}
		return *this;
	}

	~List() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	bool isEmpty() const {
		if (this->pHead == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	bool enqueue(T* newData) {
		Node<T>* newNode = new Node<T>(newData, nullptr);
		if (isEmpty()) {
			this->pHead = newNode;
			this->pTail = newNode;
		}
		else {
			this->pTail->setPNext(newNode);
			this->pTail = newNode;
		}
		return true;
	}

	//precondition: call isEmpty()
	T* dequeue() {
		if (isEmpty()) {
			return nullptr;
		}
		Node<T>* temp = this->pHead;
		T* data = this->pHead->getPT();
		this->pHead = this->pHead->getPNext();
		if (this->pHead == nullptr) {
			this->pTail = nullptr;
		}
		delete temp;
		return data;
	}

	//setters
	void setPHead(Node<T>* newPHead) {
		this->pHead = newPHead;
	}
	void setPTail(Node<T>* newPTail) {
		this->pTail = newPTail;
	}

	//getters
	Node<T>* getPHead() const {
		return this->pHead;
	}
	Node<T>* getPTail() const {
		return this->pTail;
	}

private:
	Node<T> *pHead,
		*pTail;
};