//
//  shellSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "shellSort.hpp"


#include<iostream>

using namespace std;


void shellSort(int arr[], int n)
{
    int gap, i, j, temp; //g es el gap a implementar inicialmente
    
    for(gap = n/2; gap > 0; gap = gap/2)
    {
        for(i = gap; i < n; i++)
        {
            for(j = i-gap; j >= 0; j = j-gap)
            {
                if(arr[j+gap] >= arr[j])
                    break; //Si el valor en una posición arriba de k es mayor al de la posición k en el arreglo, se rompe el ciclo
                else
                {			//
                    temp = arr[j];
                    arr[j] = arr[j+gap];
                    arr[j+gap] = temp;
                }
            }
        }
    }
}
