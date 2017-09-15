//
//  main.cpp
//  ArbolB
//
//  Created by JJ Santos on 9/13/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include <iostream>
#include <time.h>
#include "ArbolB.h"

#include <ctime>
#include <chrono>

int main(int argc, const char * argv[]) {
    
    int orden = 3;
    srand((int)time(NULL));
    
    ArbolB<int> * arbol = new ArbolB<int>(orden);
    
    
    for(int i = 0; i< 100000;i++){
        arbol->Insertar(rand()%10000);
    }
    
    
    clock_t t;
    for (int i = 0; i < 10;i++){
        
        t = clock();
        arbol->Buscar(rand() % 1000);
        
        t = clock() - t;
        t = ((float)t)*1000;
        std::cout << "Busqueda " << i+1 << ": " << (((float)t)/ CLOCKS_PER_SEC) << endl;
    }
    
    //    Imprime:
    //    arbol->printAsc();
    //    arbol->printDesc();
    
    
    
    
    return 0;
    
}
