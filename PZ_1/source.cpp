#include"Header.h"

using namespace solution;

int main()
{
   string matrixTitle = "inputMatrix.txt",
      vectorTitle = "inputVector.txt",
      sizeTitle = "inputSize.txt";

   unsigned int size = 0;

   double* inArr = new double(size),
      * inVec = new double(size);

   size = inputSize();
   
   //inArr = inputFromFile(matrixTitle);
   //inVec = inputFromFile(vectorTitle);

   Matrix m(size);
   m.Conn();
   delete inArr, inVec;

   return 0;
}