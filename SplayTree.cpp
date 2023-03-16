#include "SplayTree.h"

void SplayTree::STinsertNode(string key){

	if (root == nullptr) {
		root = new TreeNode(key);
	}
	else {
		TreeNode *current = root;
		/* whether key exist and insert the key */
		while (true) {
			/* the key has existed */
			if (key == current->data) {
				//cout << "The word is exist" << endl;
				break;

			}
			/* key is bigger */
			else if (key > current->data) {
				if (current->rightchild == nullptr) {
					current->rightchild = new TreeNode(key);
					current->rightchild->parent = current;
					rotate(current->rightchild);
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
					current->leftchild = new TreeNode(key);
					current->leftchild->parent = current;
					rotate(current->leftchild);
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

void SplayTree::rotate(TreeNode* current){
	while (current->parent != nullptr) {
		/* rotate one time*/
		if (current->parent->parent==nullptr) {
			if (current == current->parent->leftchild) {
				rightRotate(current->parent);
			}
			else {
				leftRotate(current->parent);
			}
		}
		/* rotate two time*/
		else {
			/* left left */
			if (current->parent->leftchild == current && current->parent->parent->leftchild == current->parent) {
				rightRotate(current->parent->parent);
				rightRotate(current->parent);

			}
			/* right left */
			else if (current->parent->leftchild == current && current->parent->parent->rightchild == current->parent) {
				rightRotate(current->parent);
				leftRotate(current->parent);
			}
			/* right right */
			else if (current->parent->rightchild == current && current->parent->parent->rightchild == current->parent) {
				leftRotate(current->parent->parent);
				leftRotate(current->parent);

			}
			/* left right */
			else if (current->parent->rightchild == current && current->parent->parent->leftchild == current->parent) {
				leftRotate(current->parent);
				rightRotate(current->parent);
			}
		}
	}
	/*
	bool flag = true;
	hasParent(flag, root);
	if (!flag) {
		cout << "parent error" << endl;
	}
	*/
}

void SplayTree::leftRotate(TreeNode* par) {
	/* current is node rotate to root  */
	TreeNode* current = par->rightchild;
	/* move current child to parent child */
	par->rightchild = current->leftchild;
	if (current->leftchild != nullptr) {
		current->leftchild->parent = par;
	}
	/* link current to its parent */
	current->parent = par->parent;
	/* link current's parent to current */
	if (current->parent == nullptr) {
		root = current;
	}
	else {

		if (current->parent->leftchild != nullptr) {

			if (par->data == current->parent->leftchild->data) {
				current->parent->leftchild = current;
			}
			else {
				current->parent->rightchild = current;
			}
		}
		else {
			current->parent->rightchild = current;
		}
	}
	/* rotate */
	current->leftchild = par;
	par->parent = current;
	
	
}

void SplayTree::rightRotate(TreeNode* par) {
	
	/* current is node rotate to root  */
	TreeNode* current = par->leftchild;
	/* move current child to parent child */
	par->leftchild = current->rightchild;
	if (current->rightchild != nullptr) {
		current->rightchild->parent = par;
	}
	/* link current to its parent */
	current->parent = par->parent;
	/* link current's parent to current */
	if (current->parent == nullptr) {
		root = current;
	}
	else {

		if (current->parent->leftchild != nullptr) {

			if (par->data == current->parent->leftchild->data) {
				current->parent->leftchild = current;
			}
			else {
				current->parent->rightchild = current;
			}
		}
		else {
			current->parent->rightchild = current;
		}
	}
	/* rotate */
	current->rightchild = par;
	par->parent = current;
	
}

bool SplayTree::STfind(string key){
	TreeNode *current = root;
	if (root == nullptr) {
		//cout << "The tree is empty." << endl;
		return(false);
	}
	else {
		while (current != nullptr && key != current->data) {
			if (key > current->data) {
				current = current->rightchild;
			}
			else {
				current = current->leftchild;
			}
		}
		if (current == nullptr) {
			return(false);
		}
		else if (current->data == key) {
			rotate(current);
			//display();
			return(true);
		}
		else {
			return(false);
		}
	}
}

void SplayTree::STdeleteNode(string key) {

	TreeNode *current = new TreeNode();
	current = root;
	if (current == nullptr) {
		cout << "The Splay tree is empty " << endl;
	}
	else {
		while (current != nullptr && key != current->data) {
			if (key > current->data) {
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
		else if (current->data == key) {
			/* rotate current to the root */
			rotate(current);
			if (current->leftchild == nullptr&&current->rightchild == nullptr) {
				delete current;
				root = nullptr;
			}
			else if (current->rightchild == nullptr) {
				current->leftchild->parent = nullptr;
				root = current->leftchild;
				delete current;
			}
			else if (current->leftchild == nullptr) {
				current->rightchild->parent = nullptr;
				root = current->rightchild;
				delete current;
			}
			else {
				TreeNode* newRoot = successor(current->rightchild);
				string temp = newRoot->data;
				if (current->rightchild->data == temp) {
					current->data = temp;
					current->rightchild = newRoot->rightchild;
					if (newRoot->rightchild != nullptr) {
						newRoot->rightchild->parent = current;
					}
					delete newRoot;
				}
				else {
					newRoot->parent->leftchild = newRoot->rightchild;
					if (newRoot->rightchild != nullptr) {
						newRoot->rightchild->parent = newRoot->parent;
					}
					current->data = temp;
					delete newRoot;
				}
			}
			/*
			bool flag = true;
			hasParent(flag, root);
			if (!flag) {
				cout << "parent error" << endl;
			}
			*/
		}
	}
}

void SplayTree::hasParent(bool& flag, TreeNode* current) {
	if (flag == true) {
		if (current) {
			if (current != root) {
				if (current->parent == nullptr) {
					flag = false;
				}
			}
			hasParent(flag, current->leftchild);
			hasParent(flag, current->rightchild);
		}
	}
}

void SplayTree::display() const{
	if (root == nullptr) {
		cout << "The Splay tree is empty." << endl;
	}
	else {
		TreeNode *current = root;
		cout << endl << "Preorder => ";
		preorder(root);
		cout << endl;

	}
}