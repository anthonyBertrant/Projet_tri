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


void testTriRapide(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    
    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriRapide(t, tabSize);
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

void testTriFusion(TABLEAU t, int tabSize){
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    
    for(int i = 0; i < 20; ++i){
        GenerateRandTab(t, tabSize);
        debut = clock();
        TriFusion(t, tabSize);
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
    float result = 0.0;
    
    for(int i = 0; i < 4; ++i){
        GenerateRandTab(t, Ksizes[i]);
        testTriBulles(t, Ksizes[i]);
        
    }
    
}
