#pragma once

template <class D>
class Node {
public:
	Node* nextNode = nullptr;
	Node* prevNode = nullptr;
	D data;
};
