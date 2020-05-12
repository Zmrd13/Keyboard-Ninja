//
// Created by weders on 14.04.2020.
//

#ifndef KEYBOARD_NINJA_GAME_H
#define KEYBOARD_NINJA_GAME_H

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

extern int Flag;
extern int Points;
extern string currentArray[100];
extern int Token;
extern bool selectionLevel[5];
extern long int levelTime;
extern string levelOne[100], levelTwo[100], levelThree[100], levelFour[100], levelFive[100]; //Массив уровней

int InputCheck()
{
    int in = 0;

    while (!(cin >> in) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n')
            ;
        if (!(in = 'e'+'x'+'i'+'t')) {
            cout << "Буквы это не цифры" << endl;
        } else {
            exit(1);
        }
    }

    return in;
}

void SelectLevel()
{
    cout << endl;
    int key;
    key = InputCheck();

    Token = key;

    switch (key) {
        case 1:
            ArrayWrite(levelOne);
            break;
        case 2:
            ArrayWrite(levelTwo);
            break;
        case 3:
            ArrayWrite(levelThree);
            break;
        case 4:
            ArrayWrite(levelFour);
            break;
        case 5:
            ArrayWrite(levelFive);
            break;
        default:
            cout << "Уровни от 1 до 5 написано же было,еще раз введи\n";
            SelectLevel();
            break;
    }
}

void PrintGameMenu()
{
    cout <<
            "╔════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n"
            "║••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╔════════════════════════════════════════════════════════╗•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••║              Прогресс Прохождения Уровней              ║•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╟────────────────────────────────────────────────────────╢•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••║              0 - не пройдено 1 - пройдено              ║•••••••••••••••••••••••║\n"
            "║•••••••••••••••••••••••╚════════════════════════════════════════════════════════╝•••••••••••••••••••••••║\n"
            "║••••••••••••╔═══════════════╤═══════════════╤═══════════════╤═══════════════╤═══════════════╗•••••••••••║\n"
            "║••••••••••••║               │               │               │               │               ║•••••••••••║\n"
            "║••••••••••••║ Уровень 1 - "<< selectionLevel[0] <<" │ Уровень 2 - "<< selectionLevel[1] <<" │ Уровень 3 - "<< selectionLevel[2] <<" │ Уровень 4 - "<< selectionLevel[3] <<" │ Уровень 5 - "<< selectionLevel[5] <<" ║•••••••••••║\n"
            "║••••••••••••║               │               │               │               │               ║•••••••••••║\n"
            "║••••••••••••╚═══════════════╧═══════════════╧═══════════════╧═══════════════╧═══════════════╝•••••••••••║\n"
            "║••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••║\n"
            "╚════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n";
}

void TimeChoose()
{
    cout << "Выбери свое время в секундах\n";

    levelTime = InputCheck();

    cout << "Начали \n Пиши слово : ";
}

int WriteCheck(const string& right)
{
    string in;

    while ((in != right)) {
        cin >> in;
        if (in == right) {
            cout << "\nВерно" << endl;
            return 1;
        }
        if (in != right) {
            cout << "Не верно,заново пиши\n";
        }
    }
    return 0;
}

int TimerCheck(long int start)
{
    time_t timer1 = time(NULL);

    if (timer1 - start < levelTime) {
        return (levelTime - (timer1 - start));
    } else {
        return 0;
    }
}

int SetTask()
{
    time_t start = time(NULL);
    // cout << start << endl;
    string word = currentArray[start % 100];

    cout << "Пиши слово : " << word << endl;

    if (WriteCheck(word) != 3) {
        TimerCheck(start);
        if (TimerCheck(start) > 0) {
            cout << "Молодец" << endl;
            Points += TimerCheck(start);
            cout << "Очков=" << Points << endl;
            return 1;
        }
        cout << "Но не успел,все заново" << endl;
        Flag = 0;

    } else
        ;

    return 0;
}
void StartGame()
{
    selectionLevel[0] = false;
    selectionLevel[1] = false;
    selectionLevel[2] = false;
    selectionLevel[3] = false;
    selectionLevel[4] = false;
    int key = 'i';
    while (key != 99) {
        while (Points <= 400) {
            cout << "Выбор уровня 1 - 5";
            SelectLevel();

            TimeChoose();
            Flag = 1;
            while ((Flag != 0) && (Points <= 400)) {
                SetTask();
            }
        }
        selectionLevel[Token] = true;

        PrintGameMenu();
        cout << "Продолжишь или нет?Если да то введи любую кнопку ,если нет "
                "введи "
                "99\n";
        key = InputCheck();
        Points = 0;
    }
    cout << "GAME OVER\n";
    exit(1);
}

#endif // KEYBOARD_NINJA_GAME_H
