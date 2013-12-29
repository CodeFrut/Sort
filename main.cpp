#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "cstdlib"
#include "time.h"
#include "math.h"
using namespace std;

void dispArray(int *mas, int n);
void BubbleSort(int *mas, int n);
void QuickSort(int *B, int from, int to);
void Merge(int *A, int, int,int);
void MergeSort(int *A, int, int);

int main()
{
    int n, start;
    int end;
    double time1, time2, time3;
    srand(time(NULL));

    cout <<"Enter number of array's elements"<<endl;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];

    for(int i=0; i<n; i++)
    {
        a[i] = 1 + rand() %(n);
        b[i] = a[i];
        c[i] = a[i];
    }

    cout <<"Unsorted array: "<<endl;
    if (n<100)
        dispArray(a,n);
        cout<<endl<<endl;

    start = clock();
    BubbleSort(a,n);
    end = clock();
    time1 = end - start;
    cout <<"Sorted array with bubble: "<<endl;
    if (n<100)
        dispArray(a,n);
        cout<<endl;

    start = clock();
    QuickSort(b, 0, n-1);
    end = clock();
    time2 = end - start;
    cout <<"Sorted array fast: "<<endl;
    if (n<100)
    dispArray(b,n);
    cout<<endl;

    start = clock();
    MergeSort(c, 0,n-1);
    end = clock();
    time3 = end - start;
    cout <<"Sorted array merge: "<<endl;
    if (n<100)
    dispArray(c,n);
    cout<<endl;

    cout<< "Time of Bubble: " << time1/CLOCKS_PER_SEC << endl;
	cout<< "Time of Quick: " << time2/CLOCKS_PER_SEC << endl;
    cout<< "Time of Merge: " << time3/CLOCKS_PER_SEC <<endl;

    return 0;
}

void dispArray(int *mas, int n)
{
    for(int i=0; i<n; i++)
    {
        cout <<mas[i]<<" ";
    }
    cout <<endl;
}


void Merge(int *A, int left, int right, int medium)
{
    int j = left;
    int k = medium + 1;
    int count = right - left + 1;

    if (count <= 1) return;

    int *TmpMas = new int[count];

    for (int i = 0; i < count; i++)
    {
        if (j <= medium && k <= right)
        {
            if (A[j] < A[k])
                TmpMas[i] = A[j++];
            else
                TmpMas[i] = A[k++];
        }
        else
        {
            if (j <= medium)
                TmpMas[i] = A[j++];
            else
                TmpMas[i] = A[k++];
        }
    }

    j = 0;
    for (int i = left; i <= right; i++)
    {
        A[i] = TmpMas[j++];
    }
    delete[] TmpMas;
}

void MergeSort(int *A, int l, int r)
{
    int m;

    // Условие выхода из рекурсии
    if(l >= r) return;

    m = (l + r) / 2;

    // Рекурсивная сортировка полученных массивов
    MergeSort(A, l, m);
    MergeSort(A, m + 1, r);
    Merge(A, l, r, m);
}



void BubbleSort(int *mas, int n)
{
    int t;

    for(int j=1; j<n; j++)
        for(int i=n-1; i>0; i--)
            if(mas[i]<mas[i-1])
            {
                t = mas[i];
                mas[i] = mas[i-1];
                mas[i-1] = t;
            }

}

void QuickSort(int *B, int from, int to)
{
   int x, i, j, temp;

   if (from>=to)
       return;

   i=from;
   j=to;
   x=B[(from+to)/2];

   while (i<=j)
   {
      while (B[i]<x) i++;
      while (B[j]>x) j--;

      if (i<=j)
      {
         temp = B[i];
         B[i] = B[j];
         B[j] = temp;

         i++;
         j--;
      }
   }
    QuickSort(B,from,j);
    QuickSort(B,i,to);
}
