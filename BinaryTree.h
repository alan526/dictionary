#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "TreeNode.h"
#include <iostream>
#include <string>

using namespace std;

class BinaryTree {
public :
	BinaryTree();
	void display() const;
	void inorder(TreeNode* current) const;
	void preorder(TreeNode* current) const;
	void insertNode(string key);
	void deleteNode(string key);
	bool find(string key) const;
	int rank(string key, TreeNode* current) const;
	TreeNode* successor(TreeNode* current) const;
protected:
	TreeNode *root;
};
#endif // !BinaryTree
#pragma once
