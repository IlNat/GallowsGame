#include <iostream>
#pragma once

using namespace std;

class KnownLetters
{
private:
	char* knownLetters;
	const int sizeOfBuffer = 100;
	int pointer = 0;
	bool isFull;
public:
	KnownLetters();

	void addChar(char sign);
	bool checkChar(char sign);

	~KnownLetters();
};

