#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

namespace solution
{
   class Matrix
   {
   private:
      vector<vector<double>> al, au;
      vector<double> di, F;
      int n, k, ht;
      void LU();
      void LyF();
      void Uxy();
   public:
      bool flag = false;
      void Readfile();
      void Writefile(string fileName);
      void SLAU();
      void number_obus_read();
      void number_obus_multiplication(int k);
      void createGilbertMatrix(int k);
   };
}