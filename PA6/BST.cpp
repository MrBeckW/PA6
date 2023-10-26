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

/// <summary>
/// public version of insertNode, calls the private version
/// </summary>
/// <param name="newChar">a character</param>
/// <param name="newMorseStr">morse code translation of character</param>
void BST::insertNode(const char& newChar, const string& newMorseStr)
{
	insertNode(newChar, newMorseStr, mRoot);
}

/// <summary>
/// public version of locateChar
/// </summary>
/// <param name="character">character to be located</param>
/// <returns>translated character</returns>
string BST::locateChar(const char character)
{
	if (locateChar(mRoot, character))
	{
		return mMorseTranslation;
	}
}

/// <summary>
/// getter for mMoreseTranslation
/// </summary>
/// <returns></returns>
string BST::getMorseTranslation() const
{
	return mMorseTranslation;
}

/// <summary>
/// public version of printTree, calls private version.
/// </summary>
void BST::printTree() const
{
	printTree(mRoot);
}


///////////
//Private member-functions

/// <summary>
/// private version of insertNode. 
/// </summary>
/// <param name="newChar">a character</param>
/// <param name="newMorseStr">morse code translation of character</param>
/// <param name="pTree">pointer to a BSTNode</param>
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

/// <summary>
/// private version of locateChar
/// </summary>
/// <param name="pTree">pointer to a BSTNode</param>
/// <param name="character">the character to be located</param>
/// <returns>true if character is found</returns>
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
		else if(pTree->getChar() == character)//character found updates mMorseTranslation with the corriponding translation
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

/// <summary>
/// deallocates all the nodes in the tree using postorderTraversal
/// </summary>
/// <param name="pTree"></param>
void BST::destroyTree(BSTNode* pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getpLeft());
		destroyTree(pTree->getpRight());
		delete pTree;
	}
}

/// <summary>
/// prints out the tree with directional arrows to show the structure of the tree in an easily readable way.
/// </summary>
/// <param name="pTree"></param>
void BST::printTree(BSTNode* pTree) const
{
	//preorder traversal
	if (pTree != nullptr)
	{
		cout << pTree->getChar();
		if (pTree->getpLeft() != nullptr)
		{
			cout << " < ";
			
		}
		printTree(pTree->getpLeft());
		if (pTree->getpRight() != nullptr)
		{
			cout << " > ";
			
		}
		printTree(pTree->getpRight());
		cout << " ^";
		
	}
}
