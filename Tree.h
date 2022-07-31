#pragma once
#include "LinkedList.h"
#include <iostream>

class TreeNode {
private:
	LinkedList<TreeNode*>* child = new LinkedList<TreeNode*>();
public:
	void addChild(TreeNode* newNode);
	LinkedList<TreeNode*>* getChild();
	TreeNode* getChild(int nthChild);
	void deleteChild(TreeNode* node);
	void deleteChild(int nthChild);
};

inline void TreeNode::addChild(TreeNode* newNode) {
	this->child->push(newNode);
}

inline LinkedList<TreeNode*>* TreeNode::getChild() {
	return this->child;
}

inline TreeNode* TreeNode::getChild(int nthChild) {
	if (this->getChild()->length > 0) {
		return *this->getChild()->get(nthChild);
	}
	return nullptr;
}

inline void TreeNode::deleteChild(TreeNode* node) {
	if (this->child->length > 0) {
		TreeNode** tarr = nullptr;
		for (int i = 0; i < this->child->length; i++) {
			if (node == getChild(i)) {
				tarr = getChild()->get(i);
				break;
			}
		}
		this->child->remove(tarr);
	}
}

inline void TreeNode::deleteChild(int nthChild) {
	if (this->child->length > 0) {
		auto child = getChild(nthChild);
		this->child->remove(&child);
	}
}

class Tree {
public:
	TreeNode* root = nullptr;
public:
	Tree();
	~Tree();
};

inline Tree::Tree() {

}

inline Tree::~Tree() {

}