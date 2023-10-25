#include "BSTNode.hpp"

/// <summary>
/// Defulat constructor for BSTNode
/// </summary>
/// <param name="newChar">character to be translated</param>
/// <param name="newMorseStr">corrisponding morse code translation</param>
BSTNode::BSTNode(const char& newChar, const string& newMorseStr)
{
	mEnglishChar = newChar;
	mMorseStr = newMorseStr;

	mLeftChild = nullptr;
	mRightChild = nullptr;
}

char BSTNode::getChar() const
{
	return mEnglishChar;
}

string BSTNode::getMorseStr() const 
{
	return mMorseStr;
}

BSTNode* BSTNode::getpLeft() const
{
	return mLeftChild;
}

BSTNode* BSTNode::getpRight() const
{
	return mRightChild;
}

void BSTNode::setpLeft(BSTNode* newNode)
{
	mLeftChild = newNode;
}

void BSTNode::setpRight(BSTNode* newNode)
{
	mRightChild = newNode;
}
