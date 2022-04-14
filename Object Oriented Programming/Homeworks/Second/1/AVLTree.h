#pragma once
#include "Node.h"

class AVLTree
{
private:
	Node* root;

	void initializeNode(Node* node, const char* key);
	Node* searchTreeHelper(Node* node, const char* key);
	Node* deleteNodeHelper(Node* node, const char* key);
	void updateBalance(Node* node);
	void rebalance(Node* node);

	void leftRotate(Node* x);
	void rightRotate(Node* x);

	Node* minimum(Node* node);
	Node* maximum(Node* node);

public:
	AVLTree();

	Node* searchTree(const char* key);
	void insert(const char* key);
	Node* deleteNode(char* data);
};