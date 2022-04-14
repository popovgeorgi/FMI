#pragma once
struct Node {
	const char* data; // holds the key
	Node* parent; // pointer to the parent
	Node* left; // pointer to left child
	Node* right; // pointer to right child
	int bf; // balance factor of the node
};
