//
//  TriTas.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriTas.h"
#include "util.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void descendre(TABLEAU t, int d, int f){
    int fg, fd, fm;
    if(d*2+1 < f) {
        fg = 2*d+1;
        fd = 2*d+2;
        if(fd>=f) fm = fg;
        else
            if (t[fg] > t[fd]) fm = fg; else fm = fd;
        if( t[d] > t[fm]) return;
        else{
            Swap(t,d,fm);
            descendre( t, fm, f);
        }
    }
}

/*void organiserTas(TABLEAU t, int n ){
    for(int i = 2; i < n; ++i){
        int k = i + 1;
        while(k != 1){
            if(t[k-1] > t[k/2-1]){
                Swap(t, (k/2 - 1), (k-1));
            }
            k = k/2;
        }
    }
}*/

void organiserTas(TABLEAU t, int tabSize){
    for(int i = tabSize/2;  i>= 0; --i)
        descendre(t, i, tabSize);
}

void TriTas(TABLEAU t, int tabSize){
    organiserTas( t, tabSize);
    for( int i = tabSize-1; i != 0; --i ){
        Swap(t,0, i);
        descendre(t, 0, i);
    }    
}
