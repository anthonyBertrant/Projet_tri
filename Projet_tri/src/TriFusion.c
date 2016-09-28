//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriFusion.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

void Fusion(TABLEAU t, int beg, int middle, int end){
    /*spec: entrée: 0 <= debut <= pivot < fin <= taille -1
                    t[debut...pivot] trié
                    t[pivot+1...fin] trié
     
            sortie: t[debut...fin] trié
     */
    int *tmp = (int*) malloc ((middle - beg + 1) * sizeof(int));
    int i;
    
    for (i = beg; i <= middle; ++i) tmp[i - beg] = t[i];
    
    int left = beg;
    int right = middle + 1;
    
    for (i = beg; i <= end; ++i)
    {
        if (left == middle + 1) break;
        if (right == end + 1 || tmp[left] <= t[right])
        {
            t[i] = tmp[left - beg];
            ++left;
        }
        else
        {
            t[i] = tmp[right];
            ++right;
        }
    }
}
     

void TriFusion(TABLEAU t, int debut, int fin){
    /*spec: réalise le tri par fusion de t[debut....fin]*/
    if(debut < fin){ /*t[debut...fin] >=2*/
        int m;
        m = (debut + fin) / 2;
        TriFusion(t, debut, m);
        TriFusion(t, m+1, fin);
        Fusion(t, debut, m, fin);
    }

}
