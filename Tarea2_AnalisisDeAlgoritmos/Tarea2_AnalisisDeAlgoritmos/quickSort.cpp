//
//  quickSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "quickSort.hpp"

int partition(int *array, int lo, int hi) {
    int i,j;
    int v;
    int temp;
    
    v = array[lo];
    i = lo;
    j = hi;
    
    // Mientras no se cruzen los índices
    while (i < j) {
        while ((i < j) && (array[i] <= v)) {
            i++;
        }
        
        while (array[j] > v) {
            j--;
        }
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (i < j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[j];
    array[j] = array[lo];
    array[lo] = temp;
    // La nueva posición del pivot
    return j;
}


// Función recursiva para hacer el ordenamiento
void quickSort(int *array, int lo, int hi)
{
    
    int pivot;
    
    if (lo < hi) {
        pivot = partition(array, lo, hi);
        
        // Ordeno la lista de los menores
        quickSort(array, lo, pivot - 1);
        
        // Ordeno la lista de los mayores
        quickSort(array, pivot + 1, hi);
    }
}

