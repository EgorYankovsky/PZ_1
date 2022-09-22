#include "Header.h"

using namespace solution;

void showmenu()
{
   cout << "1 - Разложение LU и нахождение вектора x" << endl
      << "2 - Создать матрицу Гильберта" << endl
      << "Не целочисленное значение - выход" << endl;
}

int main()
{
   setlocale(LC_ALL, "Russian");
   Matrix object;
   int command = 0;

   showmenu();

   cout << endl << "> ";
   while (cin >> command)
   {
      switch (command)
      {
      case 1:
      {
         object.Readfile();
         if (object.flag == true) {
            cout << "ОШИБКА: Ширина ленты больше самой матрицы ";
            exit(EXIT_FAILURE);
         }
         object.SLAU();
         object.Writefile();
         cin.get();
         break;
      }
      case 2:
      {
         int _k = 0;
         cout << "Введите требуемый размер: ";
         cin >> _k;
         object.createGilbertMatrix(_k);
         object.SLAU();
         object.Writefile();
         cin.get();
      }
      default:
      {
         cout << "???" << endl;
         break;
      }
      }
      cout << "> ";
   }
   return 0;
}