//
//  insertionSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "insertionSort.hpp"

void insertionSort(int arr[], int length) {
    
    int j, temp;
    
    for (int i = 0; i < length; i++){
        j = i;
        
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}
