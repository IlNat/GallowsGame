#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <Windows.h>
#pragma once

using namespace std;

class Vocabulary
{
private:
	string* words;
	string pathToVocabularyFile = "vocabulary.txt";
	ifstream vocabularyFile;
	const int sizeOfVocabulary = 100;
public:

	Vocabulary();	

	string returnRandomWord();
	
	~Vocabulary();
};

