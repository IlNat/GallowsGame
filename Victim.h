#include <iostream>
#pragma once

using namespace std;

// Класс "Жертва".
// Необходим для основной графической и логической составляющей. Показ "Жертвы" и определения: закончилась игра или нет?
class Victim
{
private:
	const int maxStage = 6; // Максимальный этап.
	int currentStage; // Текущий этап.
public:

	// Конструктор класса. Текущий этап равняется "0".
	Victim()
	{
		currentStage = 0;
	};

	// Метод печати "Жертвы".
	void printVictim();

	// Метод увеличения(на 1) текущего этапа. Увеличивает этап, пока тот меньше максимального этапа.
	void increaseCurrentStage();

	// Метод, возвращающий текущий этап.
	int returnCurrentStage() { return currentStage; }
};

