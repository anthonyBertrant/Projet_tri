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

const int Ksizes[15] = {5, 500, 5000, 10000, 50000, 100000,
                        200000, 300000, 400000, 500000, 600000,
                        700000, 800000, 900000, 1000000};


void testTriRapide(TABLEAU t, int tabSize){
    //int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriRapide(t, 0, 16);
    
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}

void testTriSelecPerm(TABLEAU t, int tabSize){
    //int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriSelecPerm(t, 17);
    
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}

void testTriBulles(TABLEAU t, int tabSize){
    //int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriBulles(t, tabSize);
    for(int i = 0; i < tabSize; ++i){
        printf("%d \n", t[i]);
    }
}

void testTriInsertSeq(TABLEAU t, int tabSize){
    //int t[17] = {10, 100, 102, 109, 300, 3, 4, 5,6, 8, 307, 29, 30, 847, 32, 1, 9};
    TriInsertSeq(t, 17);
    for(int i = 0; i < 17; ++i){
        printf("%d \n", t[i]);
    }
}

void ExecuteBenchmark(void)
{
    TABLEAU t;
    /*for(int i = 0; i < 14; ++i){
        testTriInsertSeq(t, Ksizes[i]);
        testTriRapide(t, Ksizes[i]);
        testTriSelecPerm(t, Ksizes[i]);
    
    }*/
    GenerateRandTab(t, Ksizes[0]);
    testTriBulles(t, Ksizes[0]);
}
