//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriInsertDicho.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void translation(int p, int i, TABLEAU t){
    int j;
    for(j = i-1; p <= j; j--){
        t[j+1] = t[j];
    }
}

int position_dicho(int i,TABLEAU t){
    int g,d,m;
    g = 0;
    d = i;
    while(g < d){
        m = (g + d) / 2;
        if(t[i] <= t[m]){
            d = m;
        }else{
            g = m+1;
        }
    }
    return g;
}

void TriInsertDicho(TABLEAU t, int tabSize){
    int i,p,x;
    for(i = 1; i < tabSize; i++){
        p = position_dicho(i,t);
        x = t[i];
        translation(p,i,t);
        t[p] = x;
    }

}
