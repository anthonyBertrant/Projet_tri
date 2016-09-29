#include "util.h"
#include <stdio.h>
#include "TriInsertSeq.h"
#include "TriBulles.h"
#include "TriSelecPerm.h"
#include "TriRapide.h"
#include "ExecuteBenchmark.h"
#include "TriInsertDicho.h"
#include "TriFusion.h"
#include "TriArbreBin.h"
#include "TriTas.h"
#include "time.h"

const int Ksizes[15] = {5, 500, 5000, 10000, 50000, 100000,
                        200000, 300000, 400000, 500000, 600000,
                        700000, 800000, 900000, 1000000};

void afficherTableau(TABLEAU t, int tabSize){
    /*Spec: affiche le contenu d'un tableau passé en parametre avec sa taille */
    for(int i = 0; i < tabSize; ++i){
        printf(" %d ", t[i]);
    }
}

void testTriRapide(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    printf("debut test algo rapide pr taille %d\n", tabSize);

    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriRapide(t, 0, tabSize-1);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);
        
    }
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);

    
    WriteResultInFile(result, tabSize, "TriRapide.csv");
}

void testTriSelecPerm(TABLEAU t, int tabSize){
    /*spec: fais 20fois le test de trie de l'algorithme, puis ecris la moyenne d'execution*/
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    printf("debut test algo selec perm pr taille %d\n", tabSize);

    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriSelecPerm(t, tabSize);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);
        
    }
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);
    
    WriteResultInFile(result, tabSize, "TriSelecPerm.csv");
}

void testTriBulles(TABLEAU t, int tabSize){
    /*spec: fais 20fois le test de trie de l'algorithme, puis ecris la moyenne d'execution*/
    printf("debut test algo bulles pr taille %d\n", tabSize);

    clock_t debut;
    clock_t fin;
    float result = 0.0;

    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriBulles(t, tabSize);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);

    }
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);

    WriteResultInFile(result, tabSize, "TriBulles.csv");
}

void testTriInsertSeq(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    printf("debut test algo insertion seq pr taille %d\n", tabSize);

    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriInsertSeq(t, tabSize);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);
        
    }
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);
    
    WriteResultInFile(result, tabSize, "TriInsertSeq.csv");
}

void testTriInsertDicho(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    printf("debut test algo insertion seq pr taille %d\n", tabSize);
    
    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriInsertDicho(t, tabSize);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);
        
    }
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);
    
    WriteResultInFile(result, tabSize, "TriInsertSeq.csv");
}

void testTriFusion(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    printf("debut test algo Fusion pr taille %d\n", tabSize);

    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriFusion(t, 0, tabSize-1);
        fin = clock();
        
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        
        printf("fin test N°%d\n", i+1);
        
    }

    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);
    
    WriteResultInFile(result, tabSize, "TriFusion.csv");
}


void ExecuteBenchmark(void)
{
    TABLEAU t;
    
    for(int i = 0; i < 5; ++i){
        GenerateRandTab(t, Ksizes[i]);
        
        testTriFusion(t, Ksizes[i]);
        testTriInsertDicho(t, Ksizes[i]);
        testTriInsertSeq(t, Ksizes[i]);
        testTriRapide(t,Ksizes[i]);
        testTriSelecPerm(t, Ksizes[i]);
        testTriFusion(t, Ksizes[i]);
    }

    
}
