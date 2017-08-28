//
//  main.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "bubbleSort.h"
#include "quickSort.hpp"
#include "selectionSort.hpp"
#include "insertionSort.hpp"
#include "mergeSort.hpp"
#include "heapSort.hpp"
#include "cocktailSort.hpp"
#include "bucketSort.hpp"

using namespace std;

int main()
{
    
    int n = 10;
    int i;
    
    int diez[n];
    
    ifstream fileDiez("10.txt");
    if(fileDiez.is_open())
    {
        
        
        for(int i = 0; i < n; ++i)
        {
            fileDiez >> diez[i];
        }
    }
    
//    cout<<"Array 10 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<diez[i];
    
    
    clock_t startTime = clock();
    
    //bubbleSort(diez, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    cocktailSort(diez, n);
    //bucketSort(a, n);
    
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    
    cout<<"T-10: "<< duration/1000 <<" ms"<<endl;

    
    
    n = 100;
    int cien[n];
    ifstream fileCien("100.txt");
    if(fileCien.is_open())
    {
        
        
        for(int i = 0; i < n; ++i)
        {
            fileCien >> cien[i];
        }
    }
    
//    cout<<"Array 100 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<cien[i];
    
    startTime = clock();
    
    //bubbleSort(cien, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    cocktailSort(cien, n);
    //bucketSort(a, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-100: "<< duration/1000 <<" ms"<<endl;
    
    n = 1000;
    int mil[n];
    ifstream fileMil("1000.txt");
    if(fileMil.is_open())
    {
        
        
        for(i = 0; i < n; ++i)
        {
            fileMil >> mil[i];
        }
    }
    
//    cout<<"Array 1000 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<mil[i];
    
    startTime = clock();
    
    //bubbleSort(mil, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    cocktailSort(mil, n);
    //bucketSort(a, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-1,000: "<< duration/1000 <<" ms"<<endl;
    
    
    n = 10000;
    int diezMil[n];
    ifstream fileDiezMil("10000.txt");
    if(fileDiezMil.is_open())
    {
        
        
        for(i = 0; i < n; ++i)
        {
            fileDiezMil >> diezMil[i];
        }
    }
    
//    cout<<"Array 10000 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<diezMil[i];
    
    startTime = clock();
    
    //bubbleSort(diezMil, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    cocktailSort(diezMil, n);
    //bucketSort(a, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-10,000: "<< duration/1000 <<" ms"<<endl;
    
    n = 100000;
    int cienMil[n];
    ifstream fileCienMil("100000.txt");
    if(fileCienMil.is_open())
    {
        
        
        for(i = 0; i < n; ++i)
        {
            fileCienMil >> cienMil[i];
        }
    }
    
//    cout<<"Array 100000 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<cienMil[i];
    
    startTime = clock();
    
    //bubbleSort(cienMil, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    cocktailSort(cienMil, n);
    //bucketSort(a, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-100,000: "<< duration/1000 <<" ms"<<endl;
    
    
    n = 1000000;
    int millon[n];
    ifstream fileMillon("1000000.txt");
    if(fileMillon.is_open())
    {
        
        
        for(i = 0; i < n; ++i)
        {
            fileMillon >> millon[i];
        }
    }
    
//    cout<<"Array 1000000 before sort:";
//    for(i=0;i<n;++i)
//        cout<<" "<<millon[i];
    
    startTime = clock();
    
    //bubbleSort(diez, n);
    //quickSort(a, a[0], a[n-1]);
    //selectionSort(a, n);
    //insertionSort(a, n);
    //mergeSort(a, 0, n-1);
    //heapSort(a, n);
    //cocktailSort(a, n);
    //bucketSort(a, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-1,000,000: "<< duration/1000 <<" ms"<<endl;
    

    
    return 0;
}
