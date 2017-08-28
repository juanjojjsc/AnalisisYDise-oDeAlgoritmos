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

void maxHeapify(int a[], int i, int n)
{
    std::cout << "Si 2" << endl;
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
        maxHeapify(a, largest,n);
    }
}

void buildMaxHeap(int a[], int n)
{
    std::cout << "Si 1" << endl;
    for(int k = n/2; k >= 1; k--)
    {
        maxHeapify(a, k, n);
    }
}

void heapSort(int a[], int n)
{
    
    buildMaxHeap(a,n);
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeapify(a, 1, i - 1);
    }
}
