//
//  cocktailSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//
#include <algorithm>
#include "cocktailSort.hpp"

using namespace std;

void cocktailSort(int a[], int n) {
    bool swapped = true;
    int start = 0;
    int end = n-1;
    
    while (swapped){
        swapped = false;
        
        for (int i = start; i < end; ++i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        
        if (!swapped)
            break;
        
        swapped = false;
        
        --end;
        
        for (int i = end - 1; i >= start; --i){
            if (a[i] > a[i + 1]){
                swap(a[i], a[i+1]);
                swapped = true;
            }
        }
        ++start;
    }
}
