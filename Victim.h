#include <iostream>
#pragma once

using namespace std;

class Victim
{
private:
	const int maxStage = 6;
	int currentStage;
public:
	Victim()
	{
		currentStage = 0;
	};

	void printVictim();

	void increaseCurrentStage();
	int returnCurrentStage() { return currentStage; }
};

