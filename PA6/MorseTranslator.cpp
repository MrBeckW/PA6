#include <iostream>
#include <cctype>
#include "MorseTranslator.hpp"

using std::cin;

MorseTranslator::MorseTranslator()
{
	minput.open("MorseTable.txt");
}

MorseTranslator::~MorseTranslator()
{
	minput.close();
}

void MorseTranslator::runApp()
{
	if (minput.is_open())
	{
		createBST();
		translator();
	}
}

void MorseTranslator::createBST()
{
	string buffer;
	char character;
	while (getline(minput, buffer))
	{
		character = buffer[0];
		buffer.erase(0, 1);//deletes first element of the string buffer leaving behind just the morse code
		mTranslationTree.insertNode(character, buffer);
	}
}

void MorseTranslator::translator()
{
	string s;

	cout << "Enter the string you would like to translate.\n>";
	getline(cin, s);
	
	while(stringParser(s) == false)
	{
		cout << "\n---ERROR---\ninput untranslatable, try again.\n";
		cout << "Enter the string you would like to translate.\n>";
		getline(cin, s);
	}
	
	cout << "New String: " << s << std::endl;

}

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
