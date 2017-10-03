//
//  main.cpp
//  Camionero
//
//  Created by JJ Santos on 10/1/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

// Juan Jose Santos Chavez
// A01022009


// COMPLEJIDAD: O(n) = n

#include <iostream>
using namespace std;

void camionero(int kms, int n, int *gas, int gasolineras){
    int i = 0;
    while(gasolineras > i){
        if(n-kms == (gas[i+1] - gas[i])|| n-1 == (gas[i+1] - gas[i])){
            cout << "Llenar tanque en gasolinera no. " << gas[i] << endl;
            kms = 0;
        }else{
            cout << "No es necesario parar. " << endl;
        }
        i++;
        kms++;
    }
}

int main(){
    
    int n = 5;
    int numGasolineras = 7;
    int gasolineras[7] = {1, 3, 5, 10, 11, 18, 22};
    
    camionero(0, n, gasolineras, numGasolineras);
    
    return 0;
}


