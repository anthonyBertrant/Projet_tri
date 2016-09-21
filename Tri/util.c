//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util.h"

#define MAX 1000000
typedef int TABLEAU[MAX];


int * CreateRandTab(int Taille){
   
    TABLEAU t;
    
    return t;
}

void WriteResultInFile(int result, int taille, const char *filename){
    
    FILE* file = NULL;
    file = fopen(filename, "a");
    
    if(file != NULL){
        
        fprintf(file, "%d,%d \n",taille,result);
        fclose(file);
        
    }else {
        printf("Impossible d'ouvrir le fichier %s", filename);
    }
}

