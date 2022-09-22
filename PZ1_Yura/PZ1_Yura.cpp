#include <iostream>
#include <vector>
#include <stdio.h>         // для работы с файлами и безопасными функциям ввода-вывода
#include <stdlib.h>
#include <fstream>         // для опредения полу-ширины ленты
#include <string>
#include <math.h>

using namespace std;

FILE *stream;

void read(int &N, int &k, vector <vector<float>> &al, vector <vector<float>> &au, vector<float> &di)
{
   errno_t err = fopen_s(&stream, "input.txt", "r");
   if (err)
   {
      printf_s("Не удалость открыть файл\n");
   }
   else
   {
      fscanf_s(stream, "%d", &N);
      fscanf_s(stream, "%d", &k);
      al.resize(N);
      au.resize(N);
      di.resize(N);

      for (int i = 0; i < N; ++i)
      {
         al[i].resize(k);
         for (int j = 0; j < k; ++j)
         {
            fscanf_s(stream, "%f", &al[i][j]);
         }
      }

      for (int i = 0; i < N; ++i)
      {
         au[i].resize(k);
         for (int j = 0; j < k; ++j)
         {
            fscanf_s(stream, "%f", &au[i][j]);
         }
      }

      for (int i = 0; i < N; ++i)
      {
         fscanf_s(stream, "%f", &di[i]);
      }
   }
   fclose(stream);
}

void fact(int &N, int k, vector <vector<float>> &al, vector <vector<float>> &au, vector<float> &di)
{
   vector<int> p = {};
   for (int i = 0; i < k; ++i)      //p[] хранит количество элементов L и U в строках
      p.push_back(i);
   for (int i = k; i < N; ++i)
      p.push_back(k);

   for (int i = 0; i < N; i++)      //идём по строкам
   {

      float Dsum = 0;
      if (i >= 1)
      {
         for (int z = 0; z <= i - 1; z++)
         {
            if (abs(i - z) <= k)
               Dsum += al[i][k + z - i] * au[i][k + z - i];
         }
      }
      di[i] -= Dsum;

      if (p[N - 1 - i] > 0)         //если кол-во элементов U в строке больше нуля
      {
         for (int j = i + 1; j <= i + p[N - 1 - i]; j++)    //находим их
         {
            float Lsum = 0;                                    //ищем вспомогательную сумму
            if (i >= 1)
            {
               for (int z = 0; z <= i - 1; z++)
               {
                  if (abs(z - i) <= k && abs(z - j) <= k)
                     Lsum += al[i][k + z - i] * au[j][k + z - j];
               }
            }
            al[j][k + i - j] -= Lsum;
            al[j][k + i - j] /= di[i];
         }
      }

      if (i < N - 1)
      {
         for (int j = i + 1 - p[i + 1]; j <= i; j++)
         {
            float Usum = 0;
            if (j >= 1)
            {
               for (int z = 0; z <= j - 1; z++)
               {
                  if (abs(i + 1 - z) <= k && abs(z - j) <= k)
                     Usum += al[i + 1][k + z - i - 1] * au[j][k + z - j];
               }
            }
            au[i + 1][k + j - i - 1] -= Usum;
         }
      }
   }
}

void write(int &N, int k, vector <vector<float>> &al, vector <vector<float>> &au, vector<float> &di)
{
   fopen_s(&stream, "output.txt", "w+");
   for (int i = 0; i < N; ++i)
   {
      for (int j = 0; j < k; ++j)
      {
         fprintf_s(stream, "%f ", al[i][j]);
      }
      fprintf_s(stream, "%s", "\n");
   }

   for (int i = 0; i < N; ++i)
   {
      for (int j = 0; j < k; ++j)
      {
         fprintf_s(stream, "%f ", au[i][j]);
      }
      fprintf_s(stream, "%s", "\n");
   }

   for (int i = 0; i < N; ++i)
   {
      fprintf_s(stream, "%f ", di[i]);
   }

   fclose(stream);
}

int main()
{
   setlocale(LC_ALL, "");
   vector <vector<float>> al = {}, au = {};
   vector<float> di = {};
   //ifstream in("input.txt");
   //string line;
   //int k = 0;
   //getline(in, line);                          //полуширина ленты
   //in.close();

   int N = 0, k = 0;
   read(N, k, al, au, di);
   fact(N, k, al, au, di);
   write(N, k, al, au, di);
}
