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
      int n, m, ht;
      void LU();
      void LyF();
      void Uxy();
   public:
      bool flag = false;
      void Readfile();
      void Writefile();
      void Multiplication();
      void SLAU();
      void createGilbertMatrix(int k);
   };
}