#include "TreeNode.h"

TreeNode::TreeNode() :leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(""), key(0) {

}

TreeNode::TreeNode(string newdata) : leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(newdata) {

}

TreeNode::TreeNode(string newdata, int newkey) : leftchild(nullptr), rightchild(nullptr), parent(nullptr), data(newdata), key(newkey) {

}