#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Victim.h"

using namespace std;

enum {NOTHING = '_'};

template <typename T>
string toString(T val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}

bool findSignInContentArray(char sign, char* arrayToShow, char* arrayWithHiddenContent, int sizeOfArray)
{
    bool isFind = false;
    for (int i = 0; i < sizeOfArray; i++)
    {
        if (arrayWithHiddenContent[i] == sign) 
        {
            arrayToShow[i] = sign;
            isFind = true;
        }
    }
    return isFind;
}

void printCharArray(char* charArray, int sizeOfArray, char specSign)
{
    for (int i = 0; i < sizeOfArray; i++)
        cout << charArray[i] << specSign;
    cout << '\n';
}

int returnAmountOfSign(char sign, char* array, int sizeOfArray)
{
    int amountOfSign = 0;
    for (int i = 0; i < sizeOfArray; i++) 
    {
        if (array[i] == sign)
            amountOfSign++;
    }
    return amountOfSign;
}

void fillEmptyArray(char* emptyArray, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
        emptyArray[i] = NOTHING;
}

void showMathOperation(int numberOfOperation)
{
    if (numberOfOperation == 1)
        cout << "сложение.\n";

    if (numberOfOperation == 2)
        cout << "вычитание.\n";

    if (numberOfOperation == 3)
        cout << "умножение.\n";

    if (numberOfOperation == 4)
        cout << "деление.\n";
}

double mathOperations(int& numberOfOperation, string& stringFirstNumber, string& stringSecondNumber)
{
    double doubleFirstNumber, doubleSecondNumber, doubleResultNumber;

    cout << "Введите первое число математической операции: ";
    cin >> doubleFirstNumber;
    stringFirstNumber = toString(doubleFirstNumber);
    cout << "\nПервое число: " << doubleFirstNumber << "\n\n";

    cout << "Введите второе число математической операции: ";
    cin >> doubleSecondNumber;
    stringSecondNumber = toString(doubleSecondNumber);

    system("cls");
    cout << "\nПервое число: " << doubleFirstNumber << "\n\n";
    cout << "\nВторое число: " << doubleSecondNumber << "\n\n";

    do
    {
        cout << "Математические операции:\n1 - сложить;\n2 - вычесть;\n3 - умножить;\n4 - разделить:\n";
        cin >> numberOfOperation;
        if (numberOfOperation != 1 && numberOfOperation != 2 && numberOfOperation != 3 && numberOfOperation != 4)
            cout << "Такой математической операции нет, повторите ввод.\n";
    } while (numberOfOperation != 1 && numberOfOperation != 2 && numberOfOperation != 3 && numberOfOperation != 4);

    if (numberOfOperation == 1)
        doubleResultNumber = doubleFirstNumber + doubleSecondNumber;

    if (numberOfOperation == 2)
        doubleResultNumber = doubleFirstNumber - doubleSecondNumber;

    if (numberOfOperation == 3)
        doubleResultNumber = doubleFirstNumber * doubleSecondNumber;

    if (numberOfOperation == 4)
        doubleResultNumber = doubleFirstNumber / doubleSecondNumber;

    return doubleResultNumber;
}

void gameModeCalculator()
{
    Victim victim;
    string stringFirstNumber, stringSecondNumber, stringResultNumber;
    char signToFind;
    int amountOfAttempts = 0;
    int maxAmountOfAttempts = 6;
    int numberOfMathOperation;

    stringResultNumber = toString(mathOperations(numberOfMathOperation, stringFirstNumber, stringSecondNumber));
    int sizeOfResult = stringResultNumber.size();
    
    char* arrayWithResult = new char[sizeOfResult];
    char* arrayToShow = new char[sizeOfResult];

    fillEmptyArray(arrayToShow, sizeOfResult);

    stringResultNumber.copy(arrayWithResult, sizeOfResult);

    for (int i = 0; i < sizeOfResult; i++)
    {
        if (arrayWithResult[i] == '-')
            arrayToShow[i] = '-';
        if (arrayWithResult[i] == '.')
            arrayToShow[i] = '.';
    }

    do
    {
        system("cls");
        victim.printVictim();
        cout << "Первое число: " << stringFirstNumber << '\n';
        cout << "Второе число: " << stringSecondNumber << '\n';
        cout << "Операция: ";
        showMathOperation(numberOfMathOperation);
        cout << "Текущее количество попыток: " << amountOfAttempts << " из " << maxAmountOfAttempts << '\n';
        cout << "Ответ:\n";
        printCharArray(arrayToShow, sizeOfResult, ' ');
        cout << "Введите символ для поиска: ";
        cin >> signToFind;
        if (findSignInContentArray(signToFind, arrayToShow, arrayWithResult, sizeOfResult) == false) 
        {
            cout << "Символ не найден.\n";
            victim.increaseCurrentStage();
        }
        amountOfAttempts = victim.returnCurrentStage();
    } while (amountOfAttempts != maxAmountOfAttempts && returnAmountOfSign(NOTHING, arrayToShow, sizeOfResult) != 0);
    victim.printVictim();
    if (amountOfAttempts == maxAmountOfAttempts)
    {
        cout << "Вы проиграли.\n";
        cout << "Результат: ";
        printCharArray(arrayWithResult, sizeOfResult, '\0');
    }
    else if (amountOfAttempts < maxAmountOfAttempts) 
    {
        cout << "Вы отгадали результат: ";
        printCharArray(arrayWithResult, sizeOfResult, '\0');
    }
}

void gameModeWords()
{

}
/*
bool gameOver()
{

}
*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //cout << "Hello World!\n";
    int choice = 0;
    cout << "Добро пожаловать в игру \"Виселица\".\n";
    do
    {
        cout << "Выберите, в какой режим игры будете играть?\n1 - \"Слова\"; 2 - \"Калькулятор\.\n";
        cin >> choice;
        if (choice != 1 && choice != 2)
            cout << "Неправильные введённые данные, повторите ввод.\n";
    } while (choice != 1 && choice != 2);
    switch (choice)
    {
    case 1:
    {
        cout << "Режим игры: \"Слова\".\n";
        gameModeWords();
        break;
    }
    case 2:
    {
        cout << "Режим игры: \"Калькулятор\".\n";
        gameModeCalculator();
        break;
    }
    case 3:
    {
        cout << "Правила игры:\n";
        break;
    }
    case 4:
    {
        cout << "Выход из программы.\n";
        break;
    }
    default:
    {
        cout << "Такой команды нет, повторите ввод.\n";
        break;
    }
    }
    
    //victim.printVictim();
}

