#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#pragma once

using namespace std;

class Vocabulary
{
private:
	string* words;
	string pathToVocabularyFile = "vocabulary.txt";
	ifstream vocabularyFile;
	int sizeOfVocabulary = 100;
public:

	Vocabulary();	

	string returnRandomWord();	
};

