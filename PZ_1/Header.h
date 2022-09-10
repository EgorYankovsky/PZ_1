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
   template<typename T>
   T inputFromFile(string name);


   unsigned int inputSize();
   vector<double> inputArr(string name);

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