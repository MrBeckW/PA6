#pragma once

#include <iostream>
#include "BSTNode.hpp"

using std::cout;
using std::string;

class BST
{
public:
	BST();
	~BST();

	void insertNode(const char &newChar, const string& newMorseStr);
	string locateChar(const char character);

	string getMorseTranslation() const;

private:
	BSTNode* mRoot;
	string mMorseTranslation;//a place to store the string that was retrurned when searched

	void insertNode(const char& newChar, const string& newMorseStr, BSTNode* pTree);
	bool locateChar(BSTNode* pTree, char character);
	void destroyTree(BSTNode* pTree);

};