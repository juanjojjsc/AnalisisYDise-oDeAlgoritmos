//
//  binaryTreeSort.cpp
//  Tarea2_AnalisisDeAlgoritmos
//
//  Created by JJ Santos on 8/28/17.
//  Copyright © 2017 JJ Santos. All rights reserved.
//

#include "binaryTreeSort.hpp"

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int item) //Creación de un nodo con struct
{
    struct Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void guardar_Inorden(Node *root, int arr[], int &i){ //Función que reccorre el arbol en inorden
    //y que guarda cada elemento recorrido en el arreglo arr
    if (root != NULL)
    {
        guardar_Inorden(root->left, arr, i);
        arr[i++] = root->data;
        guardar_Inorden(root->right, arr, i);
    }
}

Node* create_Tree(Node* node, int data) //Inserta un elemento en el BST.
{
    if (node == NULL) {
        return newNode(data); //Si el arbol (ramificación) está vacío, crea el nuevo nodo
    }
    
    //En caso de que el nodo ya esté creado, este se recorre al hijo izquierdo o derecho
    if (data < node->data)
        node->left  = create_Tree(node->left, data);
    else if (data > node->data)
        node->right = create_Tree(node->right, data);
    
    return node;
}

void binary_treeSort(int arr[], int n) //Función que transforma el arreglo arr en un BST
{
    struct Node *root = NULL;
    
    root = create_Tree(root, arr[0]);
    for (int i=1; i<n; i++)
        create_Tree(root, arr[i]);
    
    int i = 0; //El valor de i se iniciliza a 0 para ordenar el arreglo con el arbol
    guardar_Inorden(root, arr, i);
}
