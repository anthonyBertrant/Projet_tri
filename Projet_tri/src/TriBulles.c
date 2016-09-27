//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "util.h"
#include "TriBulles.h"

#define MAX 1000000
typedef int TABLEAU[MAX];


void TriBulles(TABLEAU t, int tabSize){
    int i, j;
    i = 0;
    while(i < tabSize - 1){
        j = tabSize - 1;
        while(j > i){
            if(t[j] < t[j - 1])
                Swap(t, j, j-1);
            j = j - 1;
        }
        ++i;
    }

}
