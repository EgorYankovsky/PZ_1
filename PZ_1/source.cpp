#include"Header.h"

using namespace solution;

int main()
{
   string AU_Title = "inputAU.txt",
      AI_Title = "inputAI.txt",
      Di_Title = "inputDi.txt",
      vectorTitle = "inputVector.txt";

   unsigned int size = 0;
   vector<double> matrAl, matrAU, matrDi, matrVec;


   size = inputSize();
   matrAl = inputArr(AI_Title);
   matrAU = inputArr(AU_Title);
   matrDi = inputArr(Di_Title);
   matrVec = inputArr(vectorTitle);
   
   Matrix m(size);
   m.Conn();

   return 0;
}