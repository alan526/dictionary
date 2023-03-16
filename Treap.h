#ifndef _TREAP_H_
#define _TREAP_H_
#include "BinaryTree.h"

class Treap : public BinaryTree{

public:
	void insertNode(string newdata, int newkey);
	bool keyRepeat(int key);
	void inorderKey(TreeNode* current, int key, bool& flag);
	void inorder(TreeNode* current) const;
	void preorder(TreeNode* current) const;
	void display() const;
	void rotateToMinHeap(TreeNode* current);
	void rotateToDown(TreeNode* current);
	void rightRotate(TreeNode* current);
	void leftRotate(TreeNode* current);
	void deleteNode(string target);

private:

};

#endif // !_TREAP_H_
#pragma once
