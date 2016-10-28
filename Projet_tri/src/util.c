//
//  util.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "util.h"

void afficherTableau(TABLEAU t, size_t tabSize){
    for(size_t i = 0; i < tabSize; ++i){
        printf(" %d ", t[i]);
    }
}

void GenerateRandTab(TABLEAU t, size_t tabSize){
    int x = tabSize + 300;
    srand(time(NULL));
    for(size_t i = 0; i < tabSize; ++i){
        t[i] = (rand() % x);
    }
}

void WriteResultInFile(float result, int size, const char *filename){
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        FILE* file = NULL;
        file = fopen(filename, "a");
        fprintf(file, "%d;%f \n", size, result);
        fclose(file);
    } else {
        // file doesn't exist
        FILE* file = NULL;
        file = fopen(filename, "a");

        if(file != NULL){
            fprintf(file, "%s","Taille; Resultat en seconde\n");
            fprintf(file, "%d;%f \n", size, result);
            fclose(file);

        }else {
            printf("Impossible d'ouvrir le fichier %s", filename);
        }
    }
}

void Swap(TABLEAU t, int index1, int index2){
    int tmp;
    tmp = t[index1];
    t[index1] = t[index2];
    t[index2] = tmp;
}



