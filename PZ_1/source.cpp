#include"Header.h"

using namespace solution;

int main()
{
   unsigned int size = 0;
   size = inputSize();
   double* inArr = new double(size),
      * inVec = new double(size);

   inputMatrix(inArr);
   inputVector(inVec);

   Matrix m(size);
   m.Conn();

   delete inArr, inVec;

   return 0;
}