//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriBulles.h"

#include "TriSelecPerm.h"
#include "TriRapide.h"
#include "ExecuteBenchmark.h"
#include "TriInsertSeq.h"
#include "TriInsertDicho.h"
#include "TriFusion.h"
#include "TriArbreBin.h"
#include "TriTas.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

void testTriRapide(){
    int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriRapide(t, 0, 16);
    
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}

void testTriSelecPerm(){
    int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriSelecPerm(t, 17);
    
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}

void testTriBulles(){
    int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriBulles(t, 17);
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}


int main()
{
    //testTriRapide(); //TriRapide OK
    //testTriSelecPerm(); //TriSelecPerm OK
    //testTriBulles(); //TriBulles OK
    
	return(0);
}
