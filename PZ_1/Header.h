#pragma once
#include <iostream>
#include <fstream>
using namespace std;


namespace solution
{
   double* inputFromFile(string title);
   unsigned int inputFromFile1(string title);


   class Matrix
   {
   private:
      unsigned int mSize;

   public:
      Matrix(unsigned int size);
      void Conn();
   };
}