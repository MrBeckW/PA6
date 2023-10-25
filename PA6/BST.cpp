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
	

}

/// <summary>
/// destructor for BST
/// </summary>
BST::~BST()
{
	destroyTree(this->mRoot);
}

void BST::insertNode(const char& newChar, const string& newMorseStr)
{
	insertNode(newChar, newMorseStr, mRoot);
}

string BST::locateChar(const char character)
{
	if (locateChar(mRoot, character))
	{
		return mMorseTranslation;
	}
	
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

bool BST::locateChar(BSTNode* pTree, char character) //p, l, r
{
	bool success = true;
	if (pTree != nullptr)
	{
		if (pTree->getChar() < character)//traverse right
		{
			locateChar(pTree->getpRight(), character);
		}
		else if (pTree->getChar() > character)//traverse left
		{
			locateChar(pTree->getpLeft(), character);
		}
		else if(pTree->getChar() == character)
		{
			mMorseTranslation = pTree->getMorseStr();
		}
		else
		{
			cout << "Character not found\n";
			success = false;
		}
	}
	else
	{
		cout << "Tree does not exist\n";
		success = false;
	}
	return success;
}

void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getpLeft());
		destroyTree(pTree->getpRight());
		delete pTree;
	}
}
