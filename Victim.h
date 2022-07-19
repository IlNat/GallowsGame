#include <iostream>
#pragma once

using namespace std;

// ����� "������".
// ��������� ��� �������� ����������� � ���������� ������������. ����� "������" � �����������: ����������� ���� ��� ���?
class Victim
{
private:
	const int maxStage = 6; // ������������ ����.
	int currentStage; // ������� ����.
public:

	// ����������� ������. ������� ���� ��������� "0".
	Victim()
	{
		currentStage = 0;
	};

	// ����� ������ "������".
	void printVictim();

	// ����� ����������(�� 1) �������� �����. ����������� ����, ���� ��� ������ ������������� �����.
	void increaseCurrentStage();

	// �����, ������������ ������� ����.
	int returnCurrentStage() { return currentStage; }
};

