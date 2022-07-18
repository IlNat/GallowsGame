#include "Vocabulary.h"

Vocabulary::Vocabulary()
{
	
	vocabularyFile.open(pathToVocabularyFile, ios::in);

	if (!vocabularyFile.is_open())
		cout << "Невозможно открыть файл со словарём!\n";

	else
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		words = new string[sizeOfVocabulary];
		for (int i = 0; i < sizeOfVocabulary; i++)
			vocabularyFile >> words[i];
	}

}

string Vocabulary::returnRandomWord()
{
	srand(time(0));
	int randomWord = rand() % 100;
	return words[randomWord];
}

Vocabulary::~Vocabulary()
{
	if (words != nullptr)
		delete[] words;
}
