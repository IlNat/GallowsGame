#include "KnownLetters.h"

// Конструктор класса. Заполняет изначально массив известных букв пробелами(т.к. ничего ещё не известно).
KnownLetters::KnownLetters()
{
	knownLetters = new char[sizeOfBuffer];
	for (int i = 0; i < sizeOfBuffer; i++)
		knownLetters[i] = ' ';
	isFull = false;
}

// Добавить элемент типа "char". Позволяет добавить элемент, пока указатель на конец меньше размера массива.
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

// Проверить наличие элемента в массиве. Перебирает массив с известными символами и ищет(сравнивает их с искомым) элемент.
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

// Деструктор класса.
KnownLetters::~KnownLetters()
{
	if (knownLetters != nullptr)
		delete[] knownLetters;
}
