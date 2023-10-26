#include <iostream>
#include <cctype>
#include "MorseTranslator.hpp"

using std::cin;
using std::endl;

/// <summary>
/// defualt constuctor  
/// </summary>
MorseTranslator::MorseTranslator()
{
	minputCode.open("MorseTable.txt");
	mImputConvert.open("Convert.txt");
}

/// <summary>
/// destructor 
/// </summary>
MorseTranslator::~MorseTranslator()
{
	minputCode.close();
	mImputConvert.close();
}

/// <summary>
/// executes the code to run the translation app
/// </summary>
void MorseTranslator::runApp()
{
	if (minputCode.is_open() && mImputConvert.is_open())
	{
		createBST();
		printTranslationTree();
		translator();
	}
	else
	{
		cout << "File failed to open\n";
	}
}

/// <summary>
/// displays key for the printed tree then calls the printTree function
/// </summary>
void MorseTranslator::printTranslationTree()
{
	cout << "Tree Print Key\n"
		<< "-------------------------------------\n"
		<< "x < y | Traverse left from x to y\n"
		<< "x > y | Traverse right from x to y\n"
		<< "  ^   | Traverse up the tree\n"
		<< "-------------------------------------\n\n";
	mTranslationTree.printTree();
	cout << "\n\n";
}

/// <summary>
/// creates the BST that contains the code tranlations
/// </summary>
void MorseTranslator::createBST()
{
	string buffer;
	char character;
	while (getline(minputCode, buffer))
	{
		character = buffer[0];
		buffer.erase(0, 1);//deletes first element of the string buffer leaving behind just the morse code
		mTranslationTree.insertNode(character, buffer);
	}
}

/// <summary>
/// the code that translates the english text into morse code
/// </summary>
void MorseTranslator::translator()
{
	string s;
	int lineCount = 1;// counter to keep track of any lines that have non translatable characters
	while (getline(mImputConvert, s)) 
	{
		if (stringParser(s) == false)//checks if the line has untanslatable characters 
		{
			cout << "\n---ERROR--- line " << lineCount <<" untranslatable\n";
		}
		else
		{
			for (int i = 0; i < s.length(); i++)
			{
				if ((int)s[i] == 32)//space
				{
					cout << "   ";
				}
				else
				{
					mTranslationTree.locateChar(s[i]);
					cout << mTranslationTree.getMorseTranslation() << " ";
				}
			}
			cout << endl;
		}
		lineCount++;
	}
}

/// <summary>
/// validates if the given string contains only characters within translatable ascii ranges. then it changes lowercase letters to uppercase.
/// </summary>
/// <param name="s">reference to the string that will be parsed</param>
/// <returns>true if string contains only translatable characters</returns>
bool MorseTranslator::stringParser(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!((int)s[i] <= 90 && (int)s[i] >= 65) && !((int)s[i] <= 57 && (int)s[i] >= 48) && !((int)s[i] == 44) && !((int)s[i] == 46) && !((int)s[i] == 63) && !((int)s[i] <= 122 && (int)s[i] >= 97) && !((int)s[i] == 32))//checks if input string characters are outside of acceptable ranges
		{
			return false;
		}
		else if (((int)s[i] <= 122 && (int)s[i] >= 97))
		{
			s[i] = (char)toupper(s[i]);//changes lowercase letter to upper case
			
		}
	}
	return true;
}
