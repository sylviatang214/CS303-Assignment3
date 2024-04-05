#pragma once

#include <iostream>

#include "Node.h"

using namespace std;




template <class D>
class queue {
private:
	Node<D>* head;
	Node<D>* tail;
public:

	queue() { 
		head = nullptr; 
		tail = nullptr; 
	}

	D front() {
		return tail->data;
	}


	bool empty() { 
		if (head == nullptr)
			return true;
		else
			return false;
	}


	void push(D data) { //pushing to front of queue
		Node<D>* tempNode = new Node<D>;
		tempNode->data = data;

		if (empty()) {
			head = tempNode;
			tail = tempNode;
		}
		else {
			tempNode->nextNode = head;
			head->prevNode = tempNode;
			head = tempNode;
		}

	}


	void pop() { //popping from the back of queue

		Node<D>* tempPtr = head;


		if (head == tail) {
			head = nullptr; 
			tail = nullptr; 
			cout << tempPtr->data;
			delete tempPtr;
			return; 
		}

		while (tempPtr->nextNode != tail) {
			tempPtr = tempPtr->nextNode;
		}

		Node<D>* delPtr = tempPtr->nextNode;
		tail = tempPtr;
		tail->nextNode = nullptr;

		cout << delPtr->data;
		delete delPtr;
	}


	int size() { //return size of the queue
		if (empty()) { 
			return 0; 
		}

		int i = 0;
		Node<D>* tempPtr = head;

		while (tempPtr != nullptr) { 
			tempPtr = tempPtr->nextNode;
			i++;
		}
		return i;
	}



	void move_to_rear() {
		if (empty() || (head == tail)) { 
			return; 
		} // if there is 0 or 1 item in the queue

		Node<D>* tempPtr = head;

		while (tempPtr->nextNode != tail) { //move tempPtr to be second to last node in the queue
			tempPtr = tempPtr->nextNode;
		}
		Node<D>* rear = tempPtr->nextNode;
		tail = tempPtr;
		tail->nextNode = nullptr;

		rear->nextNode = head;
		head = rear;

		cout << rear->data << " is moved to rear." << endl;
	}

	void insertion_sort() {
		int i, j, key;
		bool insertionNeeded = false;

		Node<int>* tempPtr = head->nextNode;

		j = 1;
		while (tempPtr != nullptr) {

			key = tempPtr->data;
			insertionNeeded = false;

			for (i = j - 1; i >= 0; i--) {
				if (key < tempPtr->prevNode->data) {
					tempPtr->data = tempPtr->prevNode->data;
					insertionNeeded = true;
				}
				else
					break;
			}

			if (insertionNeeded)
				tempPtr->prevNode->data = key;

			tempPtr = tempPtr->nextNode;
			j++;
		}

	}
};


