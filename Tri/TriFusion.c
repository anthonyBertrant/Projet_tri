//
//  TriFusion.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "TriFusion.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void Fusion (TABLEAU t, int g, int m, int d){
    /*spec: entrée: 0 <= debut <= pivot < fin <= taille -1
                    t[debut...pivot] trié
                    t[pivot+1...fin] trié
     
            sortie: t[debut...fin] trié
     */
    int *tmp = (int*) malloc((m - g + 1)*sizeof(int));
    int i;
    
    int left = g;
    int right = m + 1;
    
    for (i = g; i <= m; ++i){
        tmp[i-g] = t[i];
    }
    for (i = g; i <= d; ++i){
        if (left == m + 1){
            break;
            
        }else if (right == d+1 || tmp[left-g] < t[right]){
            t[i] = tmp[left - g];
            ++left;
        
        }else{
            t[i] = t[right]; //t[i] = tmp[rigth]
            ++right;
        }
    }
    free(tmp);
}
     

void TriFusionRecurs(TABLEAU t, int debut, int fin){
    /*spec: réalise le tri par fusion de t[debut....fin]*/
    if(debut < fin){ /*t[debut...fin] >=2*/
        int m;
        m = (debut + fin)/2;
        TriFusion(t, debut, m);
        TriFusion(t, m+1, fin);
        Fusion(t, debut, m, fin);
    }
}

void TriFusion(TABLEAU t, int tabSize) {
	TriFusionRecurs(t, 0, tabSize);
}
