#include "Victim.h"

// ����� ������ "������".
void Victim::printVictim()
{
    if (currentStage > -1)
    {
        cout << "________________________________\n";
        cout << "||||||| ";

        if (currentStage > 0)
            cout << "                       |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                      __|__";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                     /     \\";
        cout << '\n';

        cout << "|||||||";
        if (currentStage > 0)
            cout << "                    / -- -- \\";
        cout << '\n';

        cout << "|||||||";
            
        if (currentStage > 0)
            cout << "                    |   |   |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                    \\   _   /";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 0)
            cout << "                     \\_____/";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 1)
            cout << "                        |"; 
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 3)
            cout << "                     ___|___";
        else if (currentStage > 2)
            cout << "                     ___|";
        else if (currentStage > 1)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 3)
            cout << "                    /   |   \\";
        else if (currentStage > 2)
            cout << "                    /   |";
        else if (currentStage > 1)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||"

            ; 
        if (currentStage > 3)
            cout << "                   /    |    \\";
        else if (currentStage > 2)
            cout << "                   /    |";
        else if (currentStage > 1)
            cout << "                        |";
        cout << '\n';
        
        cout << "|||||||";

        if (currentStage > 3)
            cout << "                  /     |     \\";
        else if (currentStage > 2)
            cout << "                  /     |";
        else if (currentStage > 1)
            cout << "                        |";
        cout << '\n'; 

        cout << "|||||||";

        if (currentStage > 3)
            cout << "                 /      |      \\";
        else if (currentStage > 2)
            cout << "                 /      |";
        else if (currentStage > 1)
            cout << "                        |";
        cout << '\n';
         
        cout << "|||||||";

        if (currentStage > 1)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 1)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";
            
        if (currentStage > 1)
            cout << "                        |";
        cout << '\n';

        cout << "|||||||";
            
        if (currentStage > 5)
            cout << "                       / \\";
        else if (currentStage > 4)
            cout << "                       /";
        cout << '\n';

        cout << "|||||||";
             
        if (currentStage > 5)
            cout << "                      /   \\";
        else if (currentStage > 4)
            cout << "                      /";
        cout << '\n';

        cout << "|||||||";
             
        if (currentStage > 5)
            cout << "                     /     \\";
        else if (currentStage > 4)
            cout << "                     /";
        cout << '\n';

        cout << "|||||||";
        
        if (currentStage > 5)
            cout << "                    /       \\";
        else if (currentStage > 4)
            cout << "                    /";
        cout << '\n';

        cout << "|||||||";

        if (currentStage > 5)
            cout << "                   /         \\";
        else if (currentStage > 4)
            cout << "                   /";
        cout << '\n';

        cout << "|||||||";
            
        if (currentStage > 5)
            cout << "                  /           \\";
        else if (currentStage > 4)
            cout << "                  /";
        cout << '\n';

        cout << "|||||||\n"; 
        cout << "|||||||\n"; 
        cout << "|||||||\n"; 
        cout << "|||||||\n"; 
        cout << "|||||||_________________________________\n"; 
    }
}

// ����� ����������(�� 1) �������� �����. ����������� ����, ���� ��� ������ ������������� �����.
void Victim::increaseCurrentStage()
{
    if (currentStage < maxStage)
        currentStage++;
}
