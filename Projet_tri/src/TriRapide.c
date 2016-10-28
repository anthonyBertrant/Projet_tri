//
//  TriRapide.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriRapide.h"

int partition(TABLEAU t, int left, int right){
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
    int j;
    if(left < right){
        j = partition(t, left, right);
        TriRapideRecurs(t, left, j-1);
        TriRapideRecurs(t, j+1, right);
    }
}

void TriRapide(TABLEAU t, size_t tabSize){
    TriRapideRecurs(t, 0, tabSize - 1);
}
