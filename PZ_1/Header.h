#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//unsigned int inputSize();
//void inputMatrix(double* arr);
//void inputVector(double* vec);


namespace solution
{
   unsigned int inputSize();
   void inputDi(vector <double> arr);
   void inputAu(vector <double> arr);
   void inputAl(vector <double> arr);
   int width(int n, vector <double> arr);
   void fill(vector <double> au, vector <double> al, vector <double> di, int n);


   class Matrix
   {
   private:
      unsigned int mSize;

   public:
      Matrix(unsigned int size);
      void Conn();
   };
}