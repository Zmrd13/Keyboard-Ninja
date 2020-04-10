#include <ctime>
#include <fstream>
#include <iostream>
const int size = 100;
long int time_lev;
int points;
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
  cout
      << "\n"
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
         "|                   | больше уровня  в 3 раза (Уровень *3).          "
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
// void array_test() {
// for (const auto &i : current_array) {

//  cout << i << endl;
// }
//}
void time_choose() {
  int key;
  cout << "Выбери свое время в секундах";
  cin >> key;
  time_lev = key;
}

int wr_check(const string &right) {
  string in;
  int tr = 0;
  while ((in != right) && (tr < 4)) {

    cin >> in;
    if (in == right) {
      cout << "\nВерно" << endl;
      return 1;
    } else {
      cout << "Не верно,заново пиши";
      tr++;
    }
  }
  cout << "\nСлишком много попыток";
  return 3;
}
int timer_check(long int start) {
  time_t timer1 = time(NULL);

  if (timer1 - start < time_lev) {

    return (time_lev - (timer1 - start));
  } else {

    return 0;
  }
}

int task() {
  time_t start = time(NULL);
  // cout << start << endl;
  string word = current_array[rand() % 100 - start % 100];

  cout << "Начали \n Пиши слово : " << word << endl;

  if (wr_check(word) != 3) {
    timer_check(start);
    if (timer_check(start) != 0) {
      cout << "Молодец" << endl;
      points += timer_check(start);
      cout << points;
      return 1;
    }
    if (wr_check(word) == 3) {
      cout << "\nПридется заново тебе все делать ";
    }

  } else
    cout << "\nЭх , но не успел\nПридется заново тебе все делать ";
  return 0;
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
  time_choose();
  task();

  // array_test();
}
