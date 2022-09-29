#include "Header.h"

namespace solution
{

   void Matrix::Readfile()
   {
      try
      {
         fstream infile("input.txt");

         infile >> n >> ht;

         if (ht * 2 + 1 > n)
            flag = true;
         else
         {
            F.resize(n);
            di.resize(n);
            al.resize(n);
            au.resize(n);
            if (!infile.eof())
            {
               for (int i = 0; i < n; i++)
               {
                  al[i].resize(ht);
                  for (int j = 0; j < ht; j++)
                     infile >> al[i][j];
               }
               for (int i = 0; i < n; i++)
               {
                  au[i].resize(ht);
                  for (int j = 0; j < ht; j++)
                     infile >> au[i][j];
               }
               for (int i = 0; i < n; i++)
                  infile >> di[i];
               for (int i = 0; i < n; i++)
                  infile >> F[i];
            }
            infile.close();
         }
      }
      catch (ios::failure e)
      {
         cerr << e.what() << endl;
      }
      catch (out_of_range err)
      {
         cerr << err.what();
      }
      catch (...)
      {
         cerr << "Непредвиденная ошибка при вводе из файла !!!";
      }
   }

   void Matrix::Writefile(string fileName)
   {
      try
      {
         ofstream outfile(fileName);

         //outfile << setprecision(5);

         for (int i = 0; i < n; i++)
         {
            for (int j = 0; j < n; j++)
            {
               if (fileName[fileName.size() - 1] == 'v')
               {
                  if (i == j)
                     outfile << di[i] << ";";
                  else if (j > i)
                  {
                     if (j - i <= ht)
                        outfile << au[j][ht - j + i] << ";";
                     else
                        outfile << 0 << ";";
                  }
                  else if (i > j)
                  {
                     if (i - j <= ht)
                        outfile << al[i][ht - i + j] << ";";
                     else
                        outfile << 0 << ";";
                  }
               }
               else
               {
                  if (i == j)
                     outfile << di[i] << " ";
                  else if (j > i)
                  {
                     if (j - i <= ht)
                        outfile << au[j][ht - j + i] << " ";
                     else
                        outfile << 0 << " ";
                  }
                  else if (i > j)
                  {
                     if (i - j <= ht)
                        outfile << al[i][ht - i + j] << " ";
                     else
                        outfile << 0 << " ";
                  }
               }
            }
            outfile << "\n";
         }

         outfile << "\n";

         for (int i = 0; i < n; i++)
         {
            if (fileName[fileName.size() - 1] == 'v')
               outfile << F[i] << ";";
            else
               outfile << F[i] << " ";
         }

         outfile.close();
      }
      catch (ios::failure e)
      {
         cerr << e.what() << endl;
      }
      catch (out_of_range err)
      {
         cerr << err.what();
      }
      catch (...)
      {
         cerr << "Непредвиденная ошибка при выводе в файл !!!";
      }
   }

   void Matrix::LU()
   {
      for (int i = 0; i < n; i++)
      {
         for (int k = 0; k < ht && k < i; k++)
         {
            if (i >= ht)
               di[i] -= al[i][k] * au[i][k];
            else
               di[i] -= al[i][ht - i + k] * au[i][ht - i + k];
         }
         for (int j = 0; j < ht && n - i - j>1; j++)
         {
            for (int k = 0; k < i && k < ht - j - 1; k++)
            {
               if (i >= ht - 1 || i + j >= ht - 1)
                  au[i + j + 1][ht - j - 1] -= al[i][k + j + 1] * au[i + j + 1][k];
               else
                  au[i + j + 1][ht - j - 1] -= al[i][ht - i + k] * au[i + j + 1][ht - i + k - j - 1];
            }
         }
         for (int j = 0; j < ht && n - i - j > 1; j++)
         {
            for (int k = 0; k < ht - j - 1 && k < i; k++)
            {
               if (i >= ht - 1 || i + j >= ht - 1)
                  al[j + i + 1][ht - j - 1] -= al[i + j + 1][k] * au[i][k + j + 1]; // добавим +1
               else
                  al[j + i + 1][ht - j - 1] -= al[i + j + 1][ht - i + k - 1 - j] * au[i][ht - i + k];
            }
            al[j + i + 1][ht - j - 1] /= di[i];
         }
      }
   }

   void Matrix::LyF()
   {
      for (int i = 0; i < n; i++)
         for (int j = 0; j < ht && j < i; j++)
            if (i < ht)
               F[i] -= al[i][ht - i + j] * F[j];
            else
               F[i] -= al[i][j] * F[i - ht + j];
   }

   void Matrix::Uxy()
   {

      for (int i = n - 1; i >= 0; i--)
      {
         for (int j = 0; j < ht && j < n - i - 1; j++)
            F[i] -= F[i + j + 1] * au[i + j + 1][ht - 1 - j];
         F[i] /= di[i];
      }
   }

   void Matrix::SLAU()
   {
      LU();
      LyF();
      Uxy();
   }

   void Matrix::number_obus_read()
   {
      try
      {
         double q = 1;
         fstream infile("in.txt");

         infile >> n >> ht;

         if (ht * 2 + 1 > n)
            flag = true;
         else
         {
            F.resize(n);
            di.resize(n);
            al.resize(n);
            au.resize(n);
            if (!infile.eof())
            {
               for (int i = 0; i < n; i++)
               {
                  al[i].resize(ht);
                  for (int j = 0; j < ht; j++)
                     infile >> al[i][j];
               }
               for (int i = 0; i < n; i++)
               {
                  au[i].resize(ht);
                  for (int j = 0; j < ht; j++)
                     infile >> au[i][j];
               }
               int m = ht;
               int h = 1;
               for (int i = 0; i < n; i++)
               {
                  int sum = 0;
                  if (i < n - 2)
                  {
                     for (int j = 0; j < ht; j++)
                     {
                        sum += al[i][j] + au[m][j];
                        m--;
                     }
                  }
                  else if (i == n - 2)
                  {
                     for (int j = 0; j < ht; j++)
                        sum += al[i][j];
                     sum += au[n - 1][ht - 1];
                  }
                  else
                  {
                     for (int j = 0; j < ht; j++)
                        sum += al[i][j];
                  }
                  di[i] = sum * (-1);
                  //if (i == 0)
                  //{
                  //   for (int u = 0; u < k; u++)
                  //      q /= 10;
                  //   di[i] += q;
                  //}
                  m = ht + i + 1;
               }
            }
            number_obus_multiplication(8);
            infile.close();
         }
      }
      catch (ios::failure e)
      {
         cerr << e.what() << endl;
      }
      catch (out_of_range err)
      {
         cerr << err.what();
      }
      catch (...)
      {
         cerr << "Непредвиденная ошибка при вводе из файла !!!";
      }
      //for (int i = 0; i < n; i++)
      //   cout << di[i] << ' ';
   }

   void Matrix::number_obus_multiplication(int k)
   {
         int m = ht,
            h = 1, 
            w = -1, 
            e = ht + 1;

         double q = 1.0;

         for (int i = 0; i < k; i++)
            q /= 10;
         di[0] += q;

         for (int i = 0; i < n; i++)
         {
            double mul = 0;

            if (i < n - 2)
            {
               for (int j = 0; j < ht; j++)
               {
                  mul += al[i][j] * w + au[m][j] * e;
                  e--;
                  w++;
                  m--;
               }
               mul += di[i] * (i + 1);
               w--;
               e += 3;
            }
            else if (i == n - 2)
            {
               for (int j = 0; j < ht; j++)
               {
                  mul += al[i][j] * w;
                  w++;
               }
               w--;
               mul += au[n - 1][ht - 1] * n;
               mul += di[i] * (i + 1);
            }
            else
            {
               for (int j = 0; j < ht; j++)
               {
                  mul += al[i][j] * w;
                  w++;
               }
               mul += di[i] * (i + 1);
            }
            F[i] = mul;
            m = ht + i + 1;
         }
         //for (int i = 0; i < n; i++)
         //   cout << F[i] << ' ';
         SLAU();
         Writefile("outPut.csv");
         //cout << "Посмотри значения!!!!" << endl;
         //cin.get();
 }

   void Matrix::createGilbertMatrix(int k)
   {
      di.clear();
      au.clear();
      al.clear();
      al.resize(k);
      for (int i = 0; i < k; i++)
         al[i].resize(k);
      for (int i = 0; i < k; i++)
         for (int j = 0; j < k; j++)
         {
            if (i == j)
               di.push_back((double)(1.0 / (2 * (i + 1) - 1)));
            else
            {
               if (i > j)
               {
                  for (int l = k - 1; l > i + 1; l--)
                     al[i][k - j - 1] = 0;
                  for (int l = i; l > 0; l--)
                     al[i][k - j - 1] = (double)(1.0 / (i + j + 1));
               }
            }
         }
      au = al;
   }
}