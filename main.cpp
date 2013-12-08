#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
using namespace std;

void dispArray(int *mas, int n);
void BubbleSort(int *mas, int n);
void QuickSort(int *B, int from, int to);
void Merge(int *A, int first, int last);
void MergeSort(int *A, int first, int last);

int main()
{
    int n, start, end;
    double time1, time2, time3;
    srand(time(NULL));

    cout <<"Enter number of array's elements"<<endl;
    cin >> n;

    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];

    for(int i=0; i<n; i++) // блок инициализации массива
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
    QuickSort(b, 0, n);
    end = clock();
    time2 = end - start;
    cout <<"Sorted array fast: "<<endl;
    if (n<100)
    dispArray(b,n);

    start = clock();
    MergeSort(c, 0, n);
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

void QuickSort(int *B, int from, int to )
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

void Merge(int *A, int first, int last)
{
    int middle, start, final, j;

    int *array=new int[100];

    middle=(first+last)/2; //делим массив
    start=first; //начало левой части
    final=middle+1; //начало правой части
    for(j=first; j<=last; j++) //от начала до конца

    if ((start<=middle) && ((final>last) || (A[start]<A[final])))
    {
        array[j]=A[start];
        start++;
    }
    else
    {
        array[j]=A[final];
        final++;
    }
  //возвращение результата в список
    for (j=first; j<=last; j++)
        A[j]=array[j];

}

void MergeSort(int *A, int first, int last)
{
    if (first<last)
    {
        MergeSort(A, first, (first+last)/2); //сортируем левую часть
        MergeSort(A, (first+last)/2+1, last); //сортируем правую часть
        Merge(A, first, last); //сливаем две части
    }
}
