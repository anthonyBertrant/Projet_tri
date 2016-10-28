//
//  TriInsertDicho.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriInsertDicho.h"

void translation(int p, int i, TABLEAU t){
    /*spec: translation de t[p...i-1] vers t[p+1...i] */
    int j;
    for(j = i-1; p <= j; j--){
        t[j+1] = t[j];
    }
}

int position_dicho(int i,TABLEAU t){
    /*spec: calcul de la position par dichotomie*/
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

void TriInsertDicho(TABLEAU t, size_t tabSize){
    /*spec: tri du tableau t par insertion dichotomique */
    int i,p,x;
    for(i = 1; i < tabSize; i++){
        p = position_dicho(i,t);
        x = t[i];
        translation(p,i,t);
        t[p] = x;
    }

}
