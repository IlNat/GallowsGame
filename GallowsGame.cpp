#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "Victim.h"
#include "Vocabulary.h"
#include "KnownLetters.h"

using namespace std;

// "Ничего" = "_"
enum { NOTHING = '_' };

// Нашёл в интернете(преобразовывает числовые переменные в string(для режима калькулятор)). 
template <typename T>
string toString(T val)
{
    ostringstream oss;
    oss << val;
    return oss.str();
}

// Нахождение символа в массиве со словом. 
// Перебор массива со словом, если введённый символ соответствует символу из массива со словом, то этот символ устанавливается в массиве для показа на той же позиции.
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

// Печать массива типа char. Есть возможность вставить специальный символ между символами массива.
void printCharArray(char* charArray, int sizeOfArray, char specSign)
{
    for (int i = 0; i < sizeOfArray; i++)
        cout << charArray[i] << specSign;
    cout << '\n';
}

// Возвращение количества символов(необходимо, например, чтобы выяснить - остались ли в слове символы, означающие ничего). 
// Перебирает массив и сравнивает символы массива с искомым символом.
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

// Заполняет массив символами "Ничего"(для массива, который показывают игроку).
// Перебирает массив и заполняет символами "Ничего".
void fillEmptyArray(char* emptyArray, int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
        emptyArray[i] = NOTHING;
}

// Показ математических операций(режим калькулятор; когда идёт основной цикл игры игроку необходимо напоминать об операции между первым и вторым числом).
// Принимает номер операции и выводит сообщение.
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

// Математический операции(режим калькулятор; получение результата на основе действий пользователя).
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

// Режим игры "Калькулятор".
void gameModeCalculator()
{
    Victim victim; // Объект "Жертва".
    KnownLetters knownLetters; // Известные символы.
    string stringFirstNumber, stringSecondNumber, stringResultNumber; // Первое число, второе число и результат. 
    char signToFind; // Символ для поиска.
    int amountOfAttempts = 0; // Текущая попытка.
    int maxAmountOfAttempts = 6; // Максимальное количество попыток.
    int numberOfMathOperation; // Номер математической операции.
    bool flag; // Флаг, был ли введён символ?

    stringResultNumber = toString(mathOperations(numberOfMathOperation, stringFirstNumber, stringSecondNumber));
    int sizeOfResult = stringResultNumber.size();

    char* arrayWithResult = new char[sizeOfResult];
    char* arrayToShow = new char[sizeOfResult];

    fillEmptyArray(arrayToShow, sizeOfResult);

    stringResultNumber.copy(arrayWithResult, sizeOfResult);

    // Символы "Минус" и разделительная точка у дробей показываются сразу.
    for (int i = 0; i < sizeOfResult; i++)
    {
        if (arrayWithResult[i] == '-')
            arrayToShow[i] = '-';
        if (arrayWithResult[i] == '.')
            arrayToShow[i] = '.';
    }

    // Цикл режима игры "Калькулятор".
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
        do {
            cout << "Введите символ для поиска: ";
            cin >> signToFind;
            signToFind = tolower((char)signToFind);
            flag = knownLetters.checkChar(signToFind);
            knownLetters.addChar(signToFind);
            if (flag)
                cout << "Символ уже был введён, повторите ввод.\n";
        } while (flag);
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

// Режим игры "Слова".
void gameModeWords()
{
    Victim victim; // Объект "Жертва".
    Vocabulary vocabulary; // Словарь.
    KnownLetters knownLetters; // Известные символы.
    char signToFind;  // Символ для поиска.
    int amountOfAttempts = 0; // Текущая попытка.
    int maxAmountOfAttempts = 6; // Максимальное количество попыток.
    bool flag; // Флаг, был ли введён символ?

    string result = vocabulary.returnRandomWord();
    int sizeOfResult = result.size();

    char* arrayWithResult = new char[sizeOfResult];
    char* arrayToShow = new char[sizeOfResult];

    fillEmptyArray(arrayToShow, sizeOfResult);

    result.copy(arrayWithResult, sizeOfResult);

    // Цикл режима игры "Слова".
    do
    {
        system("cls");
        victim.printVictim();
        cout << "Текущее количество попыток: " << amountOfAttempts << " из " << maxAmountOfAttempts << '\n';
        cout << "Ответ:\n";
        printCharArray(arrayToShow, sizeOfResult, ' ');
        do {
            cout << "Введите символ для поиска: ";
            cin >> signToFind;
            signToFind = tolower((char)signToFind);
            flag = knownLetters.checkChar(signToFind);
            knownLetters.addChar(signToFind);
            if (flag)
                cout << "Символ уже был введён, повторите ввод.\n";
        } while (flag);
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
        cout << "Было загадано слово: ";
        printCharArray(arrayWithResult, sizeOfResult, '\0');
    }
    else if (amountOfAttempts < maxAmountOfAttempts)
    {
        cout << "Вы отгадали слово: ";
        printCharArray(arrayWithResult, sizeOfResult, '\0');
    }

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //cout << "Hello World!\n";
    int choice = 0;
    cout << "Добро пожаловать в игру \"Виселица\".\n";
    do
    {
        cout << "Выберите команду:\n1 - режим игры \"Слова\";\n2 - режим игры \"Калькулятор\";\n3 - правила игры;\n4 - выйти из игры.\n";
        cin >> choice;
    
    
        switch (choice)
        {
        case 1:
        {
            cout << "Режим игры: \"Слова\"\n";
            gameModeWords();
            break;
        }
        case 2:
        {
            cout << "Режим игры: \"Калькулятор\"\n";
            gameModeCalculator();
            break;
        }
        case 3:
        {
            cout << "Правила игры:\nРежим игры \"Слова\":\n";
            cout << "Компьютер загадывает слово из словаря и предлагает его оттгадать. Всего дано 6 попыток.\n";  
            cout << "Если Вы отгадали слово, а Жертва осталась недорисованной, то Вы победили. \nЕсли Жертва повешена, а игрок не отгадал слово, то игрок проиграл.\n";
            cout << "Режим игры калькулятор:\n";
            cout << "Вы вводите два числа и решаете: какую математическую операцию совершить. После этого Вы должны будете отгадать(вычислить) результат.\nВсего дано 6 попыток.\n";
            cout << "Если Вы сможете отгадать(вычислить) результат раньше, чем жертву повесят, то Вы выиграли! Иначе, Вы проиграете.\n Удачи!\n";
            break;
        }
        case 4:
        {
            cout << "Выход из игры.\n";
            break;
        }
        default:
        {
            cout << "Такой команды нет, повторите ввод.\n";
            break;
        }
        } 
    } while (choice != 4);
}