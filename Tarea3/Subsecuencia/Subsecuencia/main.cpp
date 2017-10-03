//
//  main.cpp
//  Subsecuencia
//
//  Created by JJ Santos on 10/1/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//



// COMPLEJIDAD: n*m

#include <string>
#include <iostream>
using namespace std;


int check(string texto, int i, string segundo, int j){
    int max = 0;
    while(texto[i] == segundo[j]){
        i++;
        j++;
        max++;
    }
    return max;
}

string textIaJ(string texto, int i, string segundo, int j){
    string max = " ";
    while(texto[i] == segundo[j]){
        max += texto[i];
        ++i;
        ++j;
    }
    return max;
}

string boyer(string texto, int n , string segundo, int m){
    //int j;
    string max;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(texto[i] == segundo[j]){
                if(check(texto, i, segundo, j) >= max.length()){
                    max = textIaJ(texto, i, segundo, j);
                }
            }
        }
    }
    if (max == ""){
        return "no hay ocurrencia";
    }else{
        return max;
    }
}


int main(){
    string nombre = "Daisy had a little lamb";
    string secuencia = "I am having lamb for dinner";
    cout << boyer(nombre, nombre.length(), secuencia, secuencia.length()) << endl;
    
    return 0;
}




