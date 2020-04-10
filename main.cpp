#include <fstream>
#include <iostream>
const int size = 100;
using namespace std;
string current_array[size];
string first_lev[size], second_lev[size], third_lev[size], fourth_lev[size],
    fifth_lev[size];
void array_writer(string *lev) {
  for (int i = 0; i < size; i++) {
    current_array[i] = lev[i];
  }
}
void level_changer() {
  int key;
  cin >> key;
  switch (key) {
  case 1:
    array_writer(first_lev);
    break;
  case 2:
    array_writer(second_lev);
    break;
  case 3:
    array_writer(third_lev);
    break;
  case 4:
    array_writer(fourth_lev);
    break;
  case 5:
    array_writer(fifth_lev);
    break;
  default:
    cout << "Уровни от 1 до 5 написано же было,еще раз введи";
    level_changer();
    break;
  }
}

void read(const string &path, string *lev) {

  ifstream file(path);

  string str;

  int i = 0;
  while (getline(file, str, '\n')) {

    lev[i] = str;
    i++;
  }
  cout << endl;
  cout << "done";
  cout << endl;

  cout << endl;
  cout << "2-done" << endl;
}

void menu1() {
  int key;
  cout << "+-------------------------------------------------------------------"
          "---------------+\n"
          "|   Keyboard        "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
          "|           Ninja   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
          "|                   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
          "|                   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|\n"
          "+-------------------------------------------------------------------"
          "---------------+\n"
          "| /                  |                                              "
          "            \\  |\n"
          "|                    |  Тут есть 5 уровней сложности .              "
          "               |\n"
          "|                    |  Они регулируют длину слов.                  "
          "               |\n"
          "| \\                  |  Время выбирает сам ниндзя в секундах.      "
          "             /  |\n"
          "+-------------------+-----------------------------------------------"
          "---------------+\n";
  cout << "Введите 1 если все понятно\n";
  cin >> key;
  if (key != 1) {
    cout << "Повторим!\n";
    menu1();
  } else
    ;
}
void menu2() {
  int key;
  cout << "\n"
          "\n"
          "\n"
          "\n"
          "+-------------------------------------------------------------------"
          "----------------+\n"
          "|   Keyboard        "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
          "|           Ninja   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
          "|                   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
          "|                   "
          "|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX |\n"
          "+-------------------------------------------------------------------"
          "----------------+\n"
          "|                   | Ваша задача : написать слово до того как "
          "выйдет время.        |\n"
          "|                   | Каждая оставшаяся секунда записывается в доп "
          "баллы,           |\n"
          "|                   | из этого следует ,что минимальный балл это 0. "
          "                |\n"
          "|                   | Уровень будет считаться проиденным если балл "
          "за прохождение   |\n"
          "|                   | больше уровня в 3 раза (Уровень *3).          "
          "                |\n"
          "|                   | Читкоды-(Devlog,RandOff).                     "
          "                |\n"
          "|                   |                                               "
          "                |\n"
          "|                   |                                               "
          "                |\n"
          "+-------------------+-----------------------------------------------"
          "----------------+\n";
  cout << "Введите 1 если все понятно(вернуть 1 окно : 2,читы :3)\n";
  cin >> key;
  switch (key) {
  case 1:
    cout << "Выберем сложность!(введите два раза тот же уровень чтобы "
            "подтвердить,считывается последний ваш вариант)\n";
    level_changer();
    break;
  case 2:
    menu1();
  // case3:cin>>cheat;
  default:
    cout << "Видимо пропустил,еще раз посмотри ,что жать надо";
    menu2();
  }
}
void array_test() {
  for (const auto &i : current_array) {

    cout << i << endl;
  }
}

int main() {

  system("CLS");

  read("1s.txt", first_lev);
  read("2s.txt", second_lev);
  read("3s.txt", third_lev);
  read("4s.txt", fourth_lev);
  read("5s.txt", fifth_lev);
  menu1();
  menu2();
  level_changer();
  array_test();
}
