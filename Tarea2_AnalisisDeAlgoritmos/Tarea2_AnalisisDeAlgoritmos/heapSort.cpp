//
//  heapSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "heapSort.hpp"
#include <iostream>

using namespace std;

void maxHeap(int a[], int i, int n)
{
    int l,r,largest,loc;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l]>a[i])
        largest=l;
    else
        largest=i;
    if((r<=n)&&(a[r]>a[largest]))
        largest=r;
    if(largest!=i)
    {
        loc=a[i];
        a[i]=a[largest];
        a[largest]=loc;
        maxHeap(a, largest,n);
    }
}
void bmaxHeap(int a[], int n)
{
    for(int k = n/2; k >= 1; k--)
    {
        maxHeap(a, k, n);
    }
}
void heapSort(int a[], int n)
{
    
    bmaxHeap(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeap(a, 1, i - 1);
    }
}
