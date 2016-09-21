//
//  util.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "util.h"


int * CreateRandTab(int Taille){
   /*Specification: la fonction renvoie un tableau rempli d'entier aleatoires spour taille 
    <Taille> donnée et renvoie le tableau nouvellement crée. */
    int t[Taille];
    
    return t;
}

void WriteResultInFile(int result, int taille, const char *filename){
    /*Specification: La fonction ecris dans un fichier .csv les informations <result> et
     <taille> pour un fichier <filename> donné. Si le fichier existe deja, il est complété
     sinon, il est crée.*/
    
    FILE* file = NULL;
    file = fopen(filename, "a");
    
    if(file != NULL){
        
        fprintf(file, "%d;%d \n",taille,result);
        fclose(file);
        
    }else {
        printf("Impossible d'ouvrir le fichier %s", filename);
    }
}

