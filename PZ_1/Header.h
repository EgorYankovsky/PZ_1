#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//unsigned int inputSize();
//void inputMatrix(double* arr);
//void inputVector(double* vec);


namespace solution
{
   unsigned int inputSize();
   void inputMatrix(double* arr);
   void inputVector(double* vec);


   class Matrix
   {
   private:
      unsigned int mSize;

   public:
      Matrix(unsigned int size);
      void Conn();
   };
}