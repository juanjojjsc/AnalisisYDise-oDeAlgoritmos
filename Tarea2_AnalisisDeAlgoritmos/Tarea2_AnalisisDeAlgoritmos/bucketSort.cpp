//
//  bucketSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "bucketSort.hpp"

void bucketSort(int sarray[], int array_size) {
    const int max = array_size;
    // use bucket[x][max] to hold the current count
    int bucket[10][max+1];
    // init bucket counters
    for(int x=0;x<10;x++){
        bucket[x][max] = 0;
    }
    // main loop for each digit position
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        // array to bucket
        for(int i = 0; i < max; i++) {
            // get the digit 0-9
            int dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
        }
    }
}
