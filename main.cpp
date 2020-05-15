

#include "lib/ArrProc.h"
#include "lib/GameMenu.h"
#include "lib/Game.h"
#include <iostream>
#include <string>

using namespace std;

//Список переменных
const int SIZE_MASSIVE = 100; //Константа, размер массивов для выборки слов из текстовых файлов
long int levelTime; //Время для уровней
int Points;
bool selectionLevel[5]; //Флаг проидености уровня.
int Token;
int Flag = 1;
string currentArray[SIZE_MASSIVE];
string levelOne[SIZE_MASSIVE], levelTwo[SIZE_MASSIVE], levelThree[SIZE_MASSIVE],
        levelFour[SIZE_MASSIVE], levelFive[SIZE_MASSIVE]; //Массив уровней

int main()
{

    ReadLevelFile("build/bin/1s.txt", levelOne);
    ReadLevelFile("build/bin/2s.txt", levelTwo);
    ReadLevelFile("build/bin/3s.txt", levelThree);
    ReadLevelFile("build/bin/4s.txt", levelFour);
    ReadLevelFile("build/bin/5s.txt", levelFive);
    GameMenuOne();
    GameMenuTwo();
    PrintGameMenu();
    StartGame();
    system("PAUSE");
}

