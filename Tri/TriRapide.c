//
//  TriRapide.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "util.h"
#include "TriRapide.h"

#define MAX 1000000
typedef int TABLEAU[MAX];


int partition(TABLEAU t, int left, int right){
    /*spec: placer un élément du tableau (appelé pivot) à sa place définitive, en permutant 
     tous les éléments de telle sorte que tous ceux qui sont inférieurs 
     au pivot soient à sa gauche et que tous ceux qui sont supérieurs au pivot soient à sa droite. */
    int pivot, i, j;
    pivot = t[left];
    i = left; j = right+1;
    
    while(1){
        do ++i; while(t[i] <= pivot && i <= right);
        do --j; while(t[j] > pivot);
        
        if(i >= j) break;
        
        Swap(t, i, j);
    }
    Swap(t, left, j);

    return j;
}

void TriRapideRecurs(TABLEAU t, int left, int right){
    /*spec: prend en entrée un tableau t a trié, un indice de debut de tri et un 
     indice de fin de trie.
     sortie: void (tableau trié)
     */
    
    int j;
    
    if(left < right){
        //divide and conquier
        j = partition(t, left, right);
        TriRapide(t, left, j-1);
        TriRapide(t, j+1, right);
    }   
}

void TriRapide(TABLEAU t, int tabSize){
	TriRapideRecurs(t, 0, tabSize);
}
