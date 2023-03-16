#ifndef _SPLAYTREE_H_
#define _SPLAYTREE_H_
#include "BinaryTree.h"

class SplayTree :public BinaryTree {

public:
	void STinsertNode(string key);
	/* rotate current to root */
	void rotate(TreeNode* current);
	void rightRotate(TreeNode* par);
	void leftRotate(TreeNode* par);
	bool STfind(string key);
	void STdeleteNode(string key);
	void hasParent(bool& flag, TreeNode* current);
	void display() const;
private:

};


#endif // !_SPLAYTREE_H_
#pragma once
