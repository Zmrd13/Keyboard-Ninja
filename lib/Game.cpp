//
// Created by weders on 14.04.2020.
//

#include "Game.h"
#include <ctime>
#include "ArrProc.h"
#include <string>
#include <iostream>
using namespace std;
extern int Flag ;
extern int Points;
extern string currentArray[100];
extern int Token;
extern bool selectionLevel[5];
extern long int levelTime;
extern string levelOne[100], levelTwo[100], levelThree[100],
    levelFour[100], levelFive[100]; //Массив уровней
void getLevel() {
  cout << endl;
  int key;
  key = inputCheck();

  Token = key;

  switch (key) {
  case 1:
    arrayWrite(levelOne);
    break;
  case 2:
    arrayWrite(levelTwo);
    break;
  case 3:
    arrayWrite(levelThree);
    break;
  case 4:
    arrayWrite(levelFour);
    break;
  case 5:
    arrayWrite(levelFive);
    break;
  default:
    cout << "Уровни от 1 до 5 написано же было,еще раз введи\n";
    getLevel();
    break;
  }
}

void setGameMenu() {
  cout << "\n+---------------------------------------------------------+\n"
          "|                         |Читкоды заблокированы          |\n"
          "| 1Уровень- "
       << selectionLevel[0]
       << "             |                               |\n"
          "|                         |                               |\n"
          "| 2Уровень- "
       << selectionLevel[1]
       << "             +-------------------------------+\n"
          "|                                                         |\n"
          "| 3Уровень- "
       << selectionLevel[2]
       << "                                             |\n"
          "|                                                         |\n"
          "| 4Уровень- "
       << selectionLevel[3]
       << "                                             |\n"
          "|                                                         |\n"
          "| 5Уровень- "
       << selectionLevel[4]
       << "                                             |\n"
          "|                                                         |\n"
          "+---------------------------------------------------------+\n";
}


void timeChoose() {

  cout << "Выбери свое время в секундах\n";

  levelTime = inputCheck();

  cout << "Начали \n Пиши слово : ";
}

int writeCheck(const string &right) {
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

int timerCheck(long int start) {
  time_t timer1 = time(NULL);

  if (timer1 - start < levelTime) {

    return (levelTime - (timer1 - start));
  } else {

    return 0;
  }
}

int setTask() {

  time_t start = time(NULL);
  // cout << start << endl;
  string word = currentArray[start % 100];

  cout << "Пиши слово : " << word << endl;

  if (writeCheck(word) != 3) {
    timerCheck(start);
    if (timerCheck(start) > 0) {

      cout << "Молодец" << endl;
      Points += timerCheck(start);
      cout << "Очков=" << Points << endl;
      return 1;
    }
    cout << "Но не успел,все заново" << endl;
    Flag = 0;

  } else
    ;

  return 0;
}
void startGame() {
  selectionLevel[0] = false;
  selectionLevel[1] = false;
  selectionLevel[2] = false;
  selectionLevel[3] = false;
  selectionLevel[4] = false;
  int key = 'i';
  while (key != 99) {
    while (Points <= 400) {
      cout << "Выбор уровня 1 - 5";
      getLevel();

      timeChoose();
      Flag = 1;
      while ((Flag != 0) && (Points <= 400)) {

        setTask();
      }
    }
    selectionLevel[Token] = true;

    setGameMenu();
    cout << "Продолжишь или нет?Если да то введи любую кнопку ,если нет введи "
            "99\n";
    key = inputCheck();
    Points = 0;
  }
  cout << "GAME OVER\n";
  exit(1);
}

int inputCheck() {
  int in=0;

  while (!(cin >> in) || (cin.peek() != '\n')) {
    cin.clear();
    while (cin.get() != '\n')
      ;  if(in ='exit')
      {
          exit(1);
      }
    cout << "Буквы это не цифры" << endl;
  }


  return in;
}