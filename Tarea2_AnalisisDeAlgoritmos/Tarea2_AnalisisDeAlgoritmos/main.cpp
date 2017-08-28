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
#include "radixSort.hpp"
#include "shellSort.hpp"
#include "countingSort.hpp"
#include "binaryTreeSort.hpp"

using namespace std;


int main()
{
    
    int n = 10;
    int i;
    
    int diez[n];
    
    ifstream fileDiez("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/10.txt");
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
    
    bubbleSort(diez, n);
    //quickSort(diez, 0, n-1);
    //selectionSort(diez, n);
    //insertionSort(diez, n);
    //mergeSort(diez, 0, n-1);
    //heapSort(diez, n);
    //cocktailSort(diez, n);
    //bucketSort(diez, n);
    //radixSort(diez, n);
    //shellSort(diez, n);
    //countingSort(diez, n);
    //binary_treeSort(diez, n);
    
    clock_t endTime = clock();
    clock_t duration = endTime - startTime;
    
    cout<<"T-10: "<< duration/1000 <<" ms"<<endl;
    
    
    
    
    
    
    
    n = 100;
    int cien[n];
    ifstream fileCien("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/100.txt");
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
    
    bubbleSort(cien, n);
    //quickSort(cien, 0, n-1);
    //selectionSort(cien, n);
    //insertionSort(cien, n);
    //mergeSort(cien, 0, n-1);
    //heapSort(cien, n);
    //cocktailSort(cien, n);
    //bucketSort(cien, n);
    //radixSort(cien, n);
    //shellSort(cien, n);
    //countingSort(cien, n);
    //binary_treeSort(cien, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-100: "<< duration/1000 <<" ms"<<endl;
    
    
    
    
    
    n = 1000;
    int mil[n];
    ifstream fileMil("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/1000.txt");
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
    
    bubbleSort(mil, n);
    //quickSort(mil, 0, n-1);
    //selectionSort(mil, n);
    //insertionSort(mil, n);
    //mergeSort(mil, 0, n-1);
    //heapSort(mil, n);
    //cocktailSort(mil, n);
    //bucketSort(mil, n);
    //radixSort(mil, n);
    //shellSort(mil, n);
    //countingSort(mil, n);
    //binary_treeSort(mil, n);
    
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-1,000: "<< duration/1000 <<" ms"<<endl;
    
    
    
    
    n = 10000;
    int diezMil[n];
    ifstream fileDiezMil("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/10000.txt");
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
    
    bubbleSort(diezMil, n);
    //quickSort(diezMil, 0, n-1);
    //selectionSort(diezMil, n);
    //insertionSort(diezMil, n);
    //mergeSort(diezMil, 0, n-1);
    //heapSort(diezMil, n);
    //cocktailSort(diezMil, n);
    //bucketSort(diezMil, n);
    //radixSort(diezMil, n);
    //shellSort(diezMil, n);
    //countingSort(diezMil, n);
    //binary_treeSort(diezMil, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-10,000: "<< duration/1000 <<" ms"<<endl;
    
    n = 100000;
    int cienMil[n];
    ifstream fileCienMil("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/100000.txt");
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
    
    bubbleSort(cienMil, n);
    //quickSort(cienMil, 0, n-1);
    //selectionSort(cienMil, n);
    //insertionSort(cienMil, n);
    //mergeSort(cienMil, 0, n-1);
    //heapSort(cienMil, n);
    //cocktailSort(cienMil, n);
    //bucketSort(cienMil, n);
    //radixSort(cienMil, n);
    //shellSort(cienMil, n);
    //countingSort(cienMil, n);
    //binary_treeSort(cienMil, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-100,000: "<< duration/1000 <<" ms"<<endl;
    
    
    
    
    
//    n = 1000000;
//    int millon[n];
//    ifstream fileMillon("/Users/jj/Google Drive/ITC/7mo Semestre/Algoritmos/AnalisisYDisenoDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/Tarea2_AnalisisDeAlgoritmos/1000000.txt");
//    if(fileMillon.is_open())
//    {
//        
//        
//        for(i = 0; i < n; ++i)
//        {
//            fileMillon >> millon[i];
//        }
//    }
    
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
    //radixSort(millon, n);
    
    endTime = clock();
    duration = endTime - startTime;
    
    cout<<"T-1,000,000: "<< duration/1000 <<" ms"<<endl;
    

    
    return 0;
}
