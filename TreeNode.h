#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <string>

using namespace std;

class TreeNode {

public:
	TreeNode();
	TreeNode(string newdata);
	TreeNode(string newdata, int newkey);
private:
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode *parent;
	string data;
	int key;

	friend class BinaryTree;
	friend class SplayTree;
	friend class Treap;
};
#endif // !TreeNode
#pragma once
