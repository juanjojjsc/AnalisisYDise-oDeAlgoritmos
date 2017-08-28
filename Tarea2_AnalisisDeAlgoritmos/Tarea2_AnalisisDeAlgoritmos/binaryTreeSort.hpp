//
//  binaryTreeSort.hpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#ifndef binaryTreeSort_hpp
#define binaryTreeSort_hpp

#include <iostream>
using namespace std;

//struct Node;

struct Node *newNode(int item);

void guardar_Inorden(Node *root, int arr[], int &i);

Node* create_Tree(Node* node, int data);

void binary_treeSort(int arr[], int n);


#endif /* binaryTreeSort_hpp */
