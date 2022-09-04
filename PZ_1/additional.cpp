#include "Header.h"

/**********************************************
                  source.cpp
**********************************************/

namespace solution
{
   unsigned int inputSize()
   {
      unsigned int n;
      string name = "inputSize.txt";
      ifstream input(name);

      if (!input.is_open())
      {
         cout << "File " << name << " doesn't exist\n";
         exit(0);
      }

      input >> n;
      input.close();
      cout << "Size inserted\n";
      return n;
   }

   void inputMatrix(double* arr)
   {
      string name = "inputMatrix.txt";
      ifstream input(name);
      int i = 0;

      if (!input.is_open())
      {
         cout << "File " << name << " doesn't exist\n";
         exit(0);
      }

      while (!EOF)
      {
         input >> arr[i];
         i++;
      }
      input.close();
      cout << "Matrix inserted\n";
   }

   void inputVector(double* vec)
   {
      string name = "InputVector.txt";
      ifstream input(name);
      int i = 0;

      if (!input.is_open())
      {
         cout << "File " << name << " doesn't exist\n";
         exit(0);
      }

      while (!EOF)
      {
         input >> vec[i];
         i++;
      }
      input.close();
      cout << "Vector inserted\n";
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