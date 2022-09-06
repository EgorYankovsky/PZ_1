#include "Header.h"

/**********************************************
                  source.cpp
**********************************************/

namespace solution
{
   double* inputFromFile(string title)
   {
      try
      {
         ifstream input(title);
         int i = 0;
         double* arr = new double();

         while (!EOF)
         {
            input >> arr[i];
            i++;
         }
         input.close();
         cout << "Array inserted\n";
         return arr;
      }
      catch (ios::failure &e)
      {
         cerr << "Exception: " << e.what() << endl;
      }
   }

   unsigned int inputFromFile1(string title)
   {
      try {
         ifstream input(title);
         unsigned int elem;
         input >> elem;
         input.close();
         cout << "Size inserted\n";
         return elem;
      }
      catch (ios::failure &e)
      {
         cerr << "Exception: " << e.what() << endl;
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