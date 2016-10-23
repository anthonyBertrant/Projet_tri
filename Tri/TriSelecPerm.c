//
//  TriSelecPerm.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriSelecPerm.h"

void TriSelecPerm(TABLEAU t, size_t tabSize){
    int i, min, j;
    int n = tabSize;
    i = 0;
    while(i < n-1){
        /*determination de min*/
        j = i + 1;
        min = i;

        while(j < n){
            if(t[j] < t[min]) min = j;
            j += 1;
        }
        /*permutation*/
        Swap(t, i, min);
        i += 1;
    }
}
