//
//  quickSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "quickSort.hpp"

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    
    do
    {
        do
            i++;
        
        while(a[i]<v&&i<=u);
        
        do
            j--;
        while(v<a[j]);
        
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    
    a[l]=a[j];
    a[j]=v;
    
    return(j);
}

void quickSort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quickSort(a,l,j-1);
        quickSort(a,j+1,u);
    }
}

