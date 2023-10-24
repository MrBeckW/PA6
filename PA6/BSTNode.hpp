#pragma once

#include <string>

using std::string;

class BSTNode
{
public:
	BSTNode(const char& newChar, const string& newMorseStr);

	char getChar() const;
	string getMorseStr() const;
	BSTNode* getpLeft() const;
	BSTNode* getpRight() const;

	void setpLeft(BSTNode* newNode);
	void setpRight(BSTNode* newNode);

private:
	string mMorseStr;
	char mEnglishChar;

	BSTNode* mLeftChild;
	BSTNode* mRightChild;
};