// ChyrunSofialab7.3.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_07_3.cpp
// < Чирун Софія >
// Лабораторна робота № 7.3.2
// Опрацювання динамічних багатовимірних масивів рекурсивним способом
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int b, amaxcount = 0, ncol = 0, maxncol = 0, k_max = 0, maxxa = 0, kkmaxx = 0, kmax = 0;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int Part1_Count(int** a, const int rowCount, const int colCount, int& k_zero, int i, int j);
void Part2_Count(int** a, const int rowCount, const int colCount, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int rowCount, colCount, k_zero = 0;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << " k_zero = " << Part1_Count(a, rowCount, colCount, k_zero, 0, 0) << endl;
	cout << endl;
	Part2_Count(a, rowCount, colCount, 0, 0);
	cout << endl;
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	    delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
	   Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
		   Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
	   Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
		   cout << endl;
		   Print(a, rowCount, colCount, i + 1, 0);
		}
		else
		   cout << endl << endl;
}

int Part1_Count(int** a, const int rowCount, const int colCount, int& k_zero, int i, int j)
{
	if (j <= colCount - 1 && i <= rowCount - 1)
	{
		if (a[i][j] == 0)
		{
		   k_zero++;
		   return Part1_Count(a, rowCount, colCount, k_zero, i + 1, 0);
		}
		else return Part1_Count(a, rowCount, colCount, k_zero, i, j + 1);
	}
	else
	{
		if (i <= rowCount - 1)
		   return Part1_Count(a, rowCount, colCount, k_zero, i + 1, 0);
		else return k_zero;
	}
}

void Part2_Count(int** a, const int rowCount, const int colCount, int i, int j)
{
	int count;
	if (i <= rowCount - 1)
	{
	   b = a[i][j];
	   count = 0;
	   k_max = 0;
	   for (int l = i + 1; l < rowCount; l++)
		   if (b == a[l][j]) count++;
	   if (k_max < count)
	   {
		  k_max = count;
		  amaxcount = b;
		  ncol = j;
	   }
	   Part2_Count(a, rowCount, colCount, i + 1, j);
	}
	else
		if (j <= colCount - 1)
		{
		   i = 0;
		   if (maxncol < ncol)
		   {
			  maxncol = ncol;
			  maxxa = amaxcount;
			  kmax = 0;
			  for (int l = 0; l < rowCount; l++)
				  if (maxxa == a[l][maxncol]) kmax++;
			  kkmaxx = kmax;
		   }
		   Part2_Count(a, rowCount, colCount, i, j + 1);
		}
		else
		   cout << " k_max [" << maxncol + 1 << "] = " << maxxa << " - " << kkmaxx << " times";
}



























/*int Calc(int** a, const int rowCount, const int colCount, int &k, int i, int j)
{
	int b;
	if (j < colCount - 1) {
		if (a[i][j] % 2 != 0 && (a[i][j] > 0)) {
			k++;
			b = a[i][j];
			a[i][j] = 0;
			return b + Calc(a, rowCount, colCount, k, i, j + 1);

			
		}
		else return Calc(a, rowCount, colCount, k, i, j + 1);
	}

	else
		if (i < rowCount - 1) {
			if (a[i][j] % 2 != 0 && (a[i][j] > 0)) {
				k++;
				b = a[i][j];
				a[i][j] = 0;
				return b +  Calc(a, rowCount, colCount, k, i + 1, 0);

				//a[i][j] = 0;
			}
			else return Calc(a, rowCount, colCount, k, i + 1, 0);
		}
		else
			return a[i][j];
}

*/

/*void Part2_Count(int** a, const int rowCount, const int colCount)
{
	//bool result = false;
	///count = 0;
	int b, amaxcount = 0, ncol = 0, maxncol = 0, k_max = 0, count, maxxa = 0, kkmaxx = 0, kmax = 0;
	for (int j = 0; j < colCount; j++)
	{
		for (int i = 0; i < rowCount; i++)
		{
			b = a[i][j];
			count = 0;
			k_max = 0;
			for (int l = i + 1; l < rowCount; l++)
				if (b == a[l][j]) count++;
			if (k_max < count)
			{
				k_max = count;
				amaxcount = b;
				ncol = j;
				//	kmax = count;
			}
		}
		if (maxncol < ncol)
		{
			maxncol = ncol;
			maxxa = amaxcount;
			kmax = 0;
			for (int l = 0; l < rowCount; l++)
				if (maxxa == a[l][maxncol]) kmax++;
			kkmaxx = kmax;


		}
	}
	cout << " k_max [" << maxncol + 1 << "] = " << maxxa << " - " << kkmaxx << " times";
	//{
		//k_zero = 0;
	//for (int j = 0; j < colCount; j++)
	//	if (a[i][j] == 0)
	//	{
			//	result = true;
		//	k_zero++;
			//j= colCount;
		//	break;
	//	}
//if (k_zero > 0)
//{
	//for (int i = 0; i < rowCount; i++)
	//	if (a[i][j] > 0)
	//		count++;
//}
//}

	//return k_zero;
}
*/


bool IsMaxInRowN(int** a, const int n, const int k, const int colCount)
{
	for (int j = 0; j < colCount; j++)
		if (a[n][j] > a[n][k])
		{
			return false;
		}
	return true;
}
bool IsMinInColK(int** a, const int n, const int k, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		if (a[i][k] < a[n][k])
		{
			return false;
		}
	return true;
}
void Part2_SaddlePoint(int** a, const int rowCount, const int colCount)
{
	cout << "Saddle points: max in row & min in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	for (int n = 0; n < rowCount; n++)
		for (int k = 0; k < colCount; k++)
			if (IsMaxInRowN(a, n, k, colCount) && IsMinInColK(a, n, k, rowCount))
			{
				cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
			}
}