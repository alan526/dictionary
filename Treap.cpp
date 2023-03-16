#include "Treap.h"

bool Treap::keyRepeat(int key) {
	bool flag = false;
	inorderKey(root, key, flag);
	return(flag);
}

void Treap::inorderKey(TreeNode* current, int key, bool& flag) {
	
	if (current) {
		inorderKey(current->leftchild, key, flag);
		if (current->key == key) {
			flag = true;
		}
		inorderKey(current->rightchild, key, flag);
	}
}

void Treap::insertNode(string newdata, int newkey) {
	if (root == nullptr) {
		root = new TreeNode(newdata, newkey);
	}
	else {
		TreeNode *current = root;
		/* whether key exist and insert the key */
		while (true) {
			/* the key has existed */
			if (newdata == current->data) {
				//cout << "The word is exist" << endl;
				break;
			}
			/* key is bigger */
			else if (newdata > current->data) {
				if (current->rightchild == nullptr) {
					current->rightchild = new TreeNode(newdata, newkey);
					current->rightchild->parent = current;
					rotateToMinHeap(current->rightchild);
					//display();
					break;
				}
				else {
					current = current->rightchild;
					continue;
				}
			}
			/* key is smaller */
			else {
				if (current->leftchild == nullptr) {
					current->leftchild = new TreeNode(newdata, newkey);
					current->leftchild->parent = current;
					rotateToMinHeap(current->leftchild);
					//display();
					break;
				}
				else {
					current = current->leftchild;
					continue;
				}
			}
		}
	}
}

void Treap::inorder(TreeNode* current) const{
	if (current) {
		inorder(current->leftchild);
		cout << "(" << current->data << "," << current->key << ")";
		inorder(current->rightchild);
	}
}

void Treap::preorder(TreeNode* current) const {
	if (current) {
		cout << "(" << current->data << "," << current->key << ")";
		preorder(current->leftchild);
		preorder(current->rightchild);
	}
}

void Treap::display()const {
	if (root == nullptr) {
		cout << "The Treap is empty." << endl;
	}
	else {
		cout << "Preorder => ";
		preorder(root);
		cout << endl;
	}
}

void Treap::rotateToMinHeap(TreeNode* current) {
	while (current != root) {
		TreeNode* p = current->parent;
		int temp;
		bool direct;
		if (p->leftchild == nullptr) {
			temp = p->rightchild->key;
			direct = true;
		}
		else if (p->rightchild == nullptr) {
			temp = p->leftchild->key;
			direct = false;
		}
		else {
			if (p->leftchild->key > p->rightchild->key) {
				temp = p->rightchild->key;
				direct = true;
			}
			else {
				temp = p->leftchild->key;
				direct = false;
			}
		}
		if (p->key > temp) {
			if (direct) {
				leftRotate(current);
			}
			else {
				rightRotate(current);
			}
		}
		current = p;

	}
}

void Treap::leftRotate(TreeNode* current) {
	TreeNode* p = current->parent;
	p->rightchild = current->leftchild;
	if (current->leftchild != nullptr) {
		current->leftchild->parent = p;
	}
	current->parent = p->parent;
	if (p->parent == nullptr) {
		root = current;
	}
	else if (p == p->parent->leftchild) {
		p->parent->leftchild = current;
	}
	else {
		p->parent->rightchild = current;
	}
	current->leftchild = p;
	p->parent = current;
}

void Treap::rightRotate(TreeNode* current) {
	TreeNode* p = current->parent;
	p->leftchild = current->rightchild;
	if (current->rightchild != nullptr) {
		current->rightchild->parent = p;
	}
	current->parent = p->parent;
	if (p->parent == nullptr) {
		root = current;
	}
	else if (p == p->parent->leftchild) {
		p->parent->leftchild = current;
	}
	else {
		p->parent->rightchild = current;
	}
	current->rightchild = p;
	p->parent = current;
}

void Treap::rotateToDown(TreeNode* current) {
	bool flag = true;
	if (current->leftchild == nullptr&&current->rightchild == nullptr) {
		flag = false;
	}
	while (flag) {
		
		if (current->leftchild == nullptr) {
			leftRotate(current->rightchild);
		}
		else if (current->rightchild == nullptr) {
			rightRotate(current->leftchild);
		}
		else {
			if (current->leftchild->key > current->rightchild->key) {
				leftRotate(current->rightchild);
			}
			else {
				rightRotate(current->leftchild);
			}
		}
		if (current->leftchild == nullptr&&current->rightchild == nullptr) {
			flag = false;
		}
	}
}

void Treap::deleteNode(string target) {
	TreeNode* current = root;
	if (current == nullptr) {
		cout << "The Treap is empty " << endl;
	}
	else {
		while (current != nullptr && target != current->data) {
			if (target > current->data) {
				current = current->rightchild;
			}
			else {
				current = current->leftchild;
			}
		}
		/* The key has not been found */
		if (current == nullptr) {
			//cout << "The word is not exist " << endl;
		}
		/* delete the key */
		else if (current->data == target) {
			rotateToDown(current);
			if (current->parent == nullptr) {
				delete root;
				root = nullptr;
			}
			else {
				if (current->parent->leftchild == current) {
					current->parent->leftchild = nullptr;
				}
				else {
					current->parent->rightchild = nullptr;
				}
				delete current;
			}
			
		}
	}
}