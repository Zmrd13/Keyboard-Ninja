#include <fstream>
#include <iostream>
using namespace std;
void _menu3() {}

void _read(const string &path, string *lev) {

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

void _menu1() {
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
    _menu1();
  } else
    ;
}
void _menu2() {
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
    cout << "Выберем сложность!\n";
    _menu3();
    break;
  case 2:
    _menu1();
  // case3:cin>>cheat;
  default:
    cout << "Видимо пропустил,еще раз посмотри ,что жать надо";
    _menu2();
  }
}
int main() {
  system("CLS");
  string first_lev[100], second_lev[100], third_lev[100], fourth_lev[100],
      fifth_lev[100];
  _read("1s.txt", first_lev);
  _read("2s.txt", second_lev);
  _read("3s.txt", third_lev);
  _read("4s.txt", fourth_lev);
  _read("5s.txt", fifth_lev);
  _menu1();
  _menu2();
}
