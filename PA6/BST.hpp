#pragma once

#include <iostream>
#include <fstream>
#include "BSTNode.hpp"

using std::ifstream;
using std::cout;
using std::string;

class BST
{
public:
	BST();
	~BST();

	void insertNode(const char &newChar, const string& newMorseStr);
	void locateCharPreOrder(char character);

	string getMorseTranslation() const;

private:
	BSTNode* mRoot;
	ifstream mInput;
	string mMorseTranslation;//a place to store the string that was retrurned when searched

	void insertNode(const char& newChar, const string& newMorseStr, BSTNode* pTree);
	void locateCharPreOrder(BSTNode* pTree, char character);
};