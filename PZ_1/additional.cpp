#include "Header.h"

/**********************************************
                  source.cpp
**********************************************/

namespace solution
{
   unsigned int inputSize()
   {
      try
      {
         unsigned int n;
         string name = "inputSize.txt";
         ifstream input(name);
         input >> n;
         input.close();
         return n;
      }
      catch (const ios::failure &e)
      {
         cerr << e.what() << endl;
      }
   }

   vector<double> inputArr(string name)
   {
      try
      {
         ifstream input(name);
         vector<double> arr;
         int i = 0;
         double a = 0;

         while (input.good())
         {
            input >> a;
            arr.push_back(a);
            i++;
         }
         input.close();
         return arr;
      }
      catch (const ios::failure &e)
      {
         cerr << e.what() << endl;
      }
   }

   int width(int n, vector <double> arr)
   {
      int size = n - 1, k = 0, j = arr.size();
      while (n > 0)
      {
         j -= n;
         n--;
         k++;
      }
      return k;
   }

   void fill(vector <double> au, vector <double> al, vector <double> di, int n)
   {
      int k = width(n, al), m = 2 * k + 1;
      vector <vector <double>> A(m, vector <double>(n));
      for (int i = 0; i < k; i++)
         A[i].push_back(0);
      int o = k - 1;
      int p = 0;
      for (int i = 1; i < n; i++)
      {
         if (o > 0)
         {
            for (int j = k - 1; j >= o; j--)
            {
               A[i][j] = al.at(p);
               p++;
            }
            o--;
         }
         int q = 0;
         for (int j = k - 1; j >= o; j--)
         {
            A[i][j] = di.at(q);
            q++;
         }
      }
      for (int j = 0; j < n; j++)
      {
         A[k][j] = al.at(p);
         p++;
      }
   }

   void LU(vector <vector <double>> A, vector <vector <double>> &L,
      vector <vector <double>> &U, int n)
   {
      U = A;

      for (int i = 0; i < n; i++)
         for (int j = i; j < n; j++)
            L[j][i] = U[j][i] / U[i][i];

      for (int k = 1; k < n; k++)
      {
         for (int i = k - 1; i < n; i++)
            for (int j = i; j < n; j++)
               L[j][i] = U[j][i] / U[i][i];

         for (int i = k; i < n; i++)
            for (int j = k - 1; j < n; j++)
               U[i][j] = U[i][j] - L[i][k - 1] * U[k - 1][j];
      }

   }

   void proisv(vector <vector <double>> A, vector <vector <double>> B,
      vector <vector <double>> &R, int n)
   {
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
               R[i][j] += A[i][k] * B[k][j];
   }

   void show(vector <vector <double>> A, int n)
   {
      for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            cout << "\t" << A[i][j] << "\t";
         }
         cout << endl;
      }
   }




   /**********************************************
                     Header.h
   **********************************************/

   Matrix::Matrix(unsigned int size)
   {
      mSize = size;
   }

   void Matrix::Conn()
   {
      cout << "Created Matrix with the size of " << mSize << endl;
   }
}