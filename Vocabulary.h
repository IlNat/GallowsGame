#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <Windows.h>
#pragma once

using namespace std;

// Класс "Словарь".
// Необходим для выбора случайно слова из словаря(по умолчанию ёмкость словаря - 100 слов).
class Vocabulary
{
private:
	string* words; // Массив слов;
	string pathToVocabularyFile = "vocabulary.txt"; // Путь к файлу со словарём.
	ifstream vocabularyFile; // Файл словаря.
	const int sizeOfVocabulary = 100; // Размер словаря.
public:

	// Конструктор класса.
	Vocabulary();	

	// Метод, возвращающий случайное слово.
	string returnRandomWord();
	
	// Деструктор класса.
	~Vocabulary();
};

