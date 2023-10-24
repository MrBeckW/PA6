#include "BST.hpp"

//////////
//Public member-funcitons

/// <summary>
/// defualt constructor for BST
/// </summary>
BST::BST()
{
	mRoot = nullptr;
	mMorseTranslation = "";
	mInput.open("MorseTable.txt");

}

/// <summary>
/// destructor for BST
/// </summary>
BST::~BST()
{
	mInput.close();
}

void BST::insertNode(const char& newChar, const string& newMorseStr)
{
	insertNode(newChar, newMorseStr, mRoot);
}

void BST::locateCharPreOrder(char character)
{
	locateCharPreOrder(mRoot, character);
}

string BST::getMorseTranslation() const
{
	return mMorseTranslation;
}


///////////
//Private member-functions

void BST::insertNode(const char& newChar, const string& newMorseStr, BSTNode* pTree)
{
	if (pTree == nullptr)
	{
		this->mRoot = new BSTNode(newChar, newMorseStr);
	}
	else
	{
		if (pTree->getChar() < newChar)//newChar has higher ascii, goes into right subtree
		{
			if (pTree->getpRight() == nullptr)
			{
				pTree->setpRight(new BSTNode(newChar, newMorseStr));//sets node
			}
			else
			{
				insertNode(newChar, newMorseStr, pTree->getpRight());//traverses to right child
			}
		}
		else if (pTree->getChar() > newChar)//newChar has lower ascii, goes into left subtree
		{
			if (pTree->getpLeft() == nullptr)
			{
				pTree->setpLeft(new BSTNode(newChar, newMorseStr));//sets node
			}
			else
			{
				insertNode(newChar, newMorseStr, pTree->getpLeft());//traverses to left child
			}
		}
		else
		{
			cout << "Entry " << newChar << " is a duplicate.\n";
		}
	}

}

void BST::locateCharPreOrder(BSTNode* pTree, char character) //p, l, r
{
	if (pTree != nullptr)
	{
		if (pTree->getChar() == character)
		{
			this->mMorseTranslation = pTree->getMorseStr();
		}
		else 
		{
			locateCharPreOrder(pTree->getpLeft(), character);
			locateCharPreOrder(pTree->getpRight(), character);
		}
		
	}
}
