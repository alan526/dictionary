#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "SplayTree.h"
#include "Treap.h"

using namespace std;

void searchDictionary(string filename, BinaryTree BT);
void searchDictionary(string filename, SplayTree& ST);
void searchDictionary(string filename, Treap T);
void displayTree(BinaryTree BT, SplayTree ST, Treap T);

int main(void) {

	ifstream fin;
	//fin.open("TesTFile1.txt");
	fin.open("TestFile2.txt");
	string word;
	//string searchFile[3] = { "TestFile11.txt", "TestFile12.txt" , "TestFile13.txt" };
	string searchFile[3] = { "TestFile21.txt", "TestFile22.txt" , "TestFile23.txt" };
	BinaryTree BT;
	SplayTree ST;
	Treap T;
	srand(time(NULL));

	while (fin >> word) {
		for (int i = word.length()-1; i >=0 ; i--) {

			if (islower(word[i]) != 0) {
				word[i] = toupper(word[i]);
			}
			if (int(word[i]) > 90 || int(word[i]) < 65) {
				word.erase(i, 1);
			}
		}
		if (!word.empty()) {
			BT.insertNode(word);
			ST.STinsertNode(word);
			int randomNum;
			do {
				randomNum = rand() % 5000;
			} while (T.keyRepeat(randomNum));
			T.insertNode(word, randomNum);
			
		}
		
	}
	fin.close();
	
	for (int i = 0; i < 3; i++) {
		cout << "The file name : " << searchFile[i] << endl;
		cout << "Binary search tree " << endl;
		searchDictionary(searchFile[i], BT);
		cout << endl << "Spaly tree " << endl;
		searchDictionary(searchFile[i], ST);
		cout << endl << "Treap " << endl;
		searchDictionary(searchFile[i], T);
		cout << endl << endl;
	}
	
	//string deData[10] = { "GAME" , "TOURNAMENT" , "STRAIGHT" , "THAILAND" , "MORE" , "CLAIMED" , "AT" , "AXELSEN" , "GAME" , "GAME" };
	string deData[10] = { "C" , "T" , "S" , "G" , "M" , "L" , "A" , "X" , "G" , "G" };
	displayTree(BT, ST, T);
	for (int i = 0; i < 10; i++) {
		BT.deleteNode(deData[i]);
		ST.STdeleteNode(deData[i]);
		T.deleteNode(deData[i]);
	}
	displayTree(BT, ST, T);
	
	system("pause");
	return(0);
}

void searchDictionary(string filename, BinaryTree BT) {

	clock_t start;
	ifstream fin;
	string word, temp;
	double success = 0, fail = 0;
	double accurracy;
	fin.open(filename);
	start = clock();
	while (fin >> word) {

		string temp = word;
		for (int i = temp.length() - 1; i >= 0; i--) {

			if (islower(temp[i]) != 0) {
				temp[i] = toupper(temp[i]);
			}
			if (int(temp[i]) > 90 || int(temp[i]) < 65) {
				temp.erase(i, 1);
			}
		}
		if (!temp.empty()) {

			if (BT.find(temp)) {
				//cout << "Find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				success += 1;
			}
			else {
				//cout << "Cannot find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				fail += 1;
			}
		}
		else {
			//cout << "The "<< word << " isn't letter" << endl << endl;
			fail += 1;
		}

	}
	cout << "Total search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
	accurracy = success / (success + fail) * 100;
	cout << "Accuracy => " << accurracy << "%" << endl;
	fin.close();
}

void searchDictionary(string filename, SplayTree& ST) {
	clock_t start;
	ifstream fin;
	string word, temp;
	double success = 0, fail = 0;
	double accurracy;
	fin.open(filename);
	start = clock();
	while (fin >> word) {

		string temp = word;
		for (int i = temp.length() - 1; i >= 0; i--) {

			if (islower(temp[i]) != 0) {
				temp[i] = toupper(temp[i]);
			}
			if (int(temp[i]) > 90 || int(temp[i]) < 65) {
				temp.erase(i, 1);
			}
		}
		if (!temp.empty()) {
			if (ST.STfind(temp)) {
				//cout << "Find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				success += 1;
			}
			else {
				//cout << "Cannot find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				fail += 1;
			}
		}
		else {
			//cout << "The "<< word << " isn't letter" << endl << endl;
			fail += 1;
		}

	}
	cout << "Total search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
	accurracy = success / (success + fail) * 100;
	cout << "Accuracy => " << accurracy << "%" << endl;
	fin.close();
}

void searchDictionary(string filename, Treap T) {
	clock_t start;
	ifstream fin;
	string word, temp;
	double success = 0, fail = 0;
	double accurracy;
	fin.open(filename);
	start = clock();
	while (fin >> word) {

		string temp = word;
		for (int i = temp.length() - 1; i >= 0; i--) {

			if (islower(temp[i]) != 0) {
				temp[i] = toupper(temp[i]);
			}
			if (int(temp[i]) > 90 || int(temp[i]) < 65) {
				temp.erase(i, 1);
			}
		}
		if (!temp.empty()) {

			if (T.find(temp)) {
				//cout << "Find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				success += 1;
			}
			else {
				//cout << "Cannot find => " << word << endl;
				//cout << "Search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl << endl;
				fail += 1;
			}
		}
		else {
			//cout << "The "<< word << " isn't letter" << endl << endl;
			fail += 1;
		}

	}
	cout << "Total search time => " << setiosflags(ios::showpoint) << setprecision(4) << (double)(clock() - start) / CLOCKS_PER_SEC << "s" << endl;
	accurracy = success / (success + fail) * 100;
	cout << "Accuracy => " << accurracy << "%" << endl;
	fin.close();
}

void displayTree(BinaryTree BT, SplayTree ST, Treap T) {
	cout << endl << "Binary Tree ";
	BT.display();
	cout << endl << "Splay Tree ";
	ST.display();
	cout << endl << "Treap" << endl;
	T.display();
}