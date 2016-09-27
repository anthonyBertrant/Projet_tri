//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriRapide.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void swap(TABLEAU t, int a, int b){
    int tmp = t[a];
    t[a] = t[b];
    t[b] = tmp;
}

int partition(TABLEAU t, int left, int right){
    int pivot,i, j, k;
    pivot = t[left];
    i = left; j = right+1;
    
    while(1){
        do ++i; while(t[i] <= pivot && i <= right);
        do --j; while(t[j] > pivot);
        
        if(i >= j) break;
        
        k = t[i]; t[i] = t[j]; t[j] = k;
    }
    k = t[left]; t[left] = t[j]; t[j] = k;

    return j;
}

void TriRapide(TABLEAU t, int left, int right){
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
