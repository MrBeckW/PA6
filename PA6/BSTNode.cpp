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

/// <summary>
/// getter for mEnglishChar
/// </summary>
/// <returns>mEnglishChar</returns>
char BSTNode::getChar() const
{
	return mEnglishChar;
}

/// <summary>
/// getter for mMorseStr
/// </summary>
/// <returns>mMorseStr</returns>
string BSTNode::getMorseStr() const 
{
	return mMorseStr;
}

/// <summary>
/// getter for pLeft
/// </summary>
/// <returns>mLeftChild</returns>
BSTNode* BSTNode::getpLeft() const
{
	return mLeftChild;
}

/// <summary>
/// getter for mRightChild
/// </summary>
/// <returns>mRightChild</returns>
BSTNode* BSTNode::getpRight() const
{
	return mRightChild;
}

/// <summary>
/// setter for mLeftChild
/// </summary>
/// <param name="newNode">pointer to the new node</param>
void BSTNode::setpLeft(BSTNode* newNode)
{
	mLeftChild = newNode;
}

/// <summary>
/// setter for mRightChild
/// </summary>
/// <param name="newNode">pointer to new node</param>
void BSTNode::setpRight(BSTNode* newNode)
{
	mRightChild = newNode;
}
