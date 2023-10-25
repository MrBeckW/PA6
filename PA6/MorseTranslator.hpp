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
	void createBST();
	void translator();
	bool stringParser(string &s);

	std::ifstream minput;
	BST mTranslationTree;
};