
#include "lib/ArrProc.h"
#include "lib/Game.h"
#include <iostream>
#include <string>

//Список переменных
const int SIZE_MASSIVE
        = 100; //Константа, размер массивов для выборки слов из текстовых файлов
long int levelTime; //Время для уровней
int Points;
bool selectionLevel[5]; //Флаг проидености уровня.
int Token;
int Flag = 1;
using namespace std;

string currentArray[SIZE_MASSIVE];
string levelOne[SIZE_MASSIVE], levelTwo[SIZE_MASSIVE], levelThree[SIZE_MASSIVE],
        levelFour[SIZE_MASSIVE], levelFive[SIZE_MASSIVE]; //Массив уровней

//Методы

void menu1()
{
    int key;
    cout << "+-----------------------------------------------------------------"
            "--"
            "---------------+\n"
            "|   Keyboard        "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|           Ninja   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
            "+-----------------------------------------------------------------"
            "--"
            "---------------+\n"
            "| /                  | Выход  :введите exit                       "
            "  "
            "            \\  |\n"
            "|                    |  Тут есть 5 уровней сложности .            "
            "  "
            "               |\n"
            "|                    |  Они регулируют длину слов.                "
            "  "
            "               |\n"
            "| \\                  |  Время выбирает сам ниндзя в секундах.    "
            "  "
            "             /  |\n"
            "+-------------------+---------------------------------------------"
            "--"
            "---------------+\n";
    cout << "Введите 1 если все понятно\n";
    key = inputCheck();
    if (key != 1) {
        cout << "Повторим!\n";
        menu1();
    } else
        ;
}
void menu2()
{
    int key;
    cout << "\n"
            "\n"
            "\n"
            "\n"
            "+-----------------------------------------------------------------"
            "--"
            "----------------+\n"
            "|   Keyboard        "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX "
            "|\n"
            "|           Ninja   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX "
            "|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX "
            "|\n"
            "|                   "
            "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX "
            "|\n"
            "+-----------------------------------------------------------------"
            "--"
            "----------------+\n"
            "|                   | Ваша задача : написать слово до того как "
            "выйдет время.        |\n"
            "|                   | Каждая оставшаяся секунда записывается в "
            "доп "
            "баллы,           |\n"
            "|                   | из этого следует ,что минимальный балл это "
            "0. "
            "                |\n"
            "|                   | Уровень будет считаться проиденным если "
            "балл "
            "за прохождение   |\n"
            "|                   | больше 400.         "
            "                |\n"
            "|                   | Читкоды-(Devlog,RandOff).                   "
            "  "
            "                |\n"
            "|                   |                                             "
            "  "
            "                |\n"
            "|                   |                                             "
            "  "
            "                |\n"
            "+-------------------+---------------------------------------------"
            "--"
            "----------------+\n";
    cout << "Введите 1 если все понятно(вернуть 1 окно : 2,читы :3)\n";
    key = inputCheck();

    switch (key) {
    case 1:
        break;
    case 2:
        menu1();
        // case3:cin>>cheat;
    default:
        cout << "Видимо пропустил,еще раз посмотри ,что жать надо\n";
        menu2();
    }
}
// void array_test() {
// for (const auto &i : currentArray) {

//  cout << i << endl;
// }
//}

int main()
{
    readLevelFile("build/bin/1s.txt", levelOne);
    readLevelFile("build/bin/2s.txt", levelTwo);
    readLevelFile("build/bin/3s.txt", levelThree);
    readLevelFile("build/bin/4s.txt", levelFour);
    readLevelFile("build/bin/5s.txt", levelFive);
    menu1();
    menu2();
    setGameMenu();
    startGame();
    system("PAUSE");
    // array_test();
}
