#include "KnownLetters.h"

KnownLetters::KnownLetters()
{
	knownLetters = new char[sizeOfBuffer];
	for (int i = 0; i < sizeOfBuffer; i++)
		knownLetters[i] = ' ';
	isFull = false;
}

void KnownLetters::addChar(char sign)
{
	if (pointer < sizeOfBuffer)
	{
		knownLetters[pointer] = sign;
		pointer++;
	}
	else
		cout << "Переполнение!!!\n";
}

bool KnownLetters::checkChar(char sign)
{
	bool isKnown = false;
	for (int i = 0; i < sizeOfBuffer; i++)
	{
		if (knownLetters[i] == sign)
			isKnown = true;
	}
	return isKnown;
}

KnownLetters::~KnownLetters()
{
	if (knownLetters != nullptr)
		delete[] knownLetters;
}
