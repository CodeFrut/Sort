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
void Merge(int *A, int first, int last);
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
    MergeSort(c, 0,n);
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

void MergeSort(int *A, int low, int high)
{
      int i = low;
      int j = high;
      int x = A[(low+high)/2];
      do {
          while(A[i] < x) ++i;
          while(A[j] > x) --j;
          if(i <= j)
            {
              int temp = A[i];
              A[i] = A[j];
              A[j] = temp;
              i++; j--;
            }
      }
      while(i < j);

      if(low < j)
        MergeSort(A, low, j);
      if(i < high)
        MergeSort(A, i, high);
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
