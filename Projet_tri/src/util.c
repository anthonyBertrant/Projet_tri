//
//  util.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "util.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX 1000000
typedef int TABLEAU[MAX];


void GenerateRandTab(TABLEAU t, int tabSize){
   /*Specification: la fonction rempli le tableau d'entier aléatoire pour 
    une taille donnée*/
    int x = tabSize * 2;
    srand(time(NULL));
    for(int i = 0; i < tabSize; ++i){
        t[i] = (rand() % x);
    }
}

void WriteResultInFile(float result, int taille, const char *filename){
    /*Specification: La fonction ecris dans un fichier .csv les informations <result> et
     <taille> pour un fichier <filename> donné. Si le fichier existe deja, il est complété
     sinon, il est crée.*/
    
    /*FILE* file = NULL;
    file = fopen(filename, "a");
    
    if(file != NULL){
        
        fprintf(file, "%d;%f \n",taille,result);
        fclose(file);
        
    }else {
        printf("Impossible d'ouvrir le fichier %s", filename);
    }*/
    
    if( access( filename, F_OK ) != -1 ) {
        // file exists
        FILE* file = NULL;
        file = fopen(filename, "a");
        fprintf(file, "%d;%f \n",taille,result);
        fclose(file);
    } else {
        // file doesn't exist
        FILE* file = NULL;
        file = fopen(filename, "a");
        
        if(file != NULL){
            fprintf(file, "%s","Taille; Resultat en seconde\n");
            fprintf(file, "%d;%f \n",taille,result);
            fclose(file);
        
        }else {
            printf("Impossible d'ouvrir le fichier %s", filename);
        }
    }
}

void Swap(TABLEAU t, int index1, int index2){
    /*spec: la fonction permet de permutter deux elements d'un tableau*/
    
    int tmp;
    tmp = t[index1];
    t[index1] = t[index2];
    t[index2] = tmp;
}

void GenererFichierResultat(void){
    
}



