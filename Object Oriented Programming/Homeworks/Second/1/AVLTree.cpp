#include "AVLTree.h"
#include <algorithm>

using namespace std;

void AVLTree::initializeNode(Node* node, const char* key)
{
	node->data = key;
	node->parent = nullptr;
	node->left = nullptr;
	node->right = nullptr;
	node->bf = 0;
}
Node* AVLTree::searchTreeHelper(Node* node, const char* key)
{
	if (node == nullptr || key == node->data) {
		return node;
	}

	if (key < node->data) {
		return searchTreeHelper(node->left, key);
	}
	return searchTreeHelper(node->right, key);
}
Node* AVLTree::minimum(Node* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}
Node* AVLTree::maximum(Node* node) {
	while (node->right != nullptr) {
		node = node->right;
	}
	return node;
}

Node* AVLTree::deleteNodeHelper(Node* node, const const const char* key)
{
	if (node == nullptr) return node;
	else if (key < node->data) node->left = deleteNodeHelper(node->left, key);
	else if (key > node->data) node->right = deleteNodeHelper(node->right, key);
	else {
		// the key has been found, now delete it

		// case 1: node is a leaf node
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}

		// case 2: node has only one child
		else if (node->left == nullptr) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}

		else if (node->right == nullptr) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}

		// case 3: has both children
		else {
			Node* temp = minimum(node->right);
			node->data = temp->data;
			node->right = deleteNodeHelper(node->right, temp->data);
		}

	}

	// Write the update balance logic here 
	// YOUR CODE HERE

	return node;
}// this is not implemented
void AVLTree::updateBalance(Node* node)
{
	if (node->bf < -1 || node->bf > 1) {
		rebalance(node);
		return;
	}

	if (node->parent != nullptr) {
		if (node == node->parent->left) {
			node->parent->bf -= 1;
		}

		if (node == node->parent->right) {
			node->parent->bf += 1;
		}

		if (node->parent->bf != 0) {
			updateBalance(node->parent);
		}
	}
}
void AVLTree::rebalance(Node* node)
{
	if (node->bf > 0) {
		if (node->right->bf < 0) {
			rightRotate(node->right);
			leftRotate(node);
		}
		else {
			leftRotate(node);
		}
	}
	else if (node->bf < 0) {
		if (node->left->bf > 0) {
			leftRotate(node->left);
			rightRotate(node);
		}
		else {
			rightRotate(node);
		}
	}
}

void AVLTree::leftRotate(Node* x)
{
	Node* y = x->right;
	x->right = y->left;
	if (y->left != nullptr) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;

	// update the balance factor
	x->bf = x->bf - 1 - max(0, y->bf);
	y->bf = y->bf - 1 + min(0, x->bf);
}
void AVLTree::rightRotate(Node* x)
{
	Node* y = x->left;
	x->left = y->right;
	if (y->right != nullptr) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nullptr) {
		this->root = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	else {
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;

	// update the balance factor
	x->bf = x->bf + 1 - min(0, y->bf);
	y->bf = y->bf + 1 + max(0, x->bf);
}


AVLTree::AVLTree()
{
	root = nullptr;
}

Node* AVLTree::searchTree(const char* key) 
{
	return searchTreeHelper(this->root, key);
}
void AVLTree::insert(const const char* key)
{
	Node* node = new Node;
	node->parent = nullptr;
	node->left = nullptr;
	node->right = nullptr;
	node->data = key;
	node->bf = 0;
	Node* y = nullptr;
	Node* x = this->root;

	while (x != nullptr) {
		y = x;
		if (node->data < x->data) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	// y is parent of x
	node->parent = y;
	if (y == nullptr) {
		root = node;
	}
	else if (node->data < y->data) {
		y->left = node;
	}
	else {
		y->right = node;
	}

	// PART 2: re-balance the node if necessary
	updateBalance(node);
}
Node* AVLTree::deleteNode(char* data)
{
	Node* deletedNode = deleteNodeHelper(this->root, data);
	return deletedNode;
}