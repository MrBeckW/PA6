#pragma once

#include <fstream>
#include "BST.hpp"


class MorseTranslator
{
public:
	MorseTranslator();
	~MorseTranslator();

	void runApp();
	
private:
	void printTranslationTree();
	void createBST();
	void translator();
	bool stringParser(string &s);

	std::ifstream minputCode;
	std::ifstream mImputConvert;
	BST mTranslationTree;
};