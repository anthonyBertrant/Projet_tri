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

const int KnSize = 15;
const int Ksizes[KnSize] = {5, 500, 5000, 10000, 50000, 100000,
                        	200000, 300000, 400000, 500000, 600000,
                        	700000, 800000, 900000, 1000000};

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
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        if( result >= 300000){
            result = 300000;
            break;
        }
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
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        if( result >= 300000){
            result = 300000;
            break;
        }
        
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
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        if( result >= 300000){
            result = 300000;
            break;
        }
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
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        if( result >= 300000){
            result = 300000;
            break;
        }
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
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        if( result >= 300000){
            result = 300000;
            break;
        }
        printf("fin test N°%d\n", i+1);
    }
    
    result = (result / 20);
    printf("fin test pour taille %d\n", tabSize);
    
    WriteResultInFile(result, tabSize, "TriInsertSeq.csv");
}

int TestTri (int tabSize, &pf)
/* spec: test une fonction de tri pour une taille donnée.
	-entrée: taille du tableau à tester
			 pointeur sur la fonction de tri
	-sortie: nombre de secondes écoulées	
			 0 si tempds de tri > 5 minutes	 		 
*/
{
	TABLEAU t;
    clock_t debut;
    clock_t fin;
    float result = 0.0;

    for(int i = 0; i < 20; ++i) {
        GenerateRandTab(t, tabSize);
        debut = clock();
        pf.p(t, tabSize);
        fin = clock();
        
        /*si le resultat total excède 5minutes, le test est coupé*/
        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;
        if( result >= 300000) {
            return 0;
        }
        printf("fin test N°%d\n", i+1);
    }

    printf("fin test pour taille %d\n", tabSize);
	return (result / 20);
}


void ExecuteBenchmark(t_flags &pf)
/* spec: execute le test sur la fonction passée en paramètre pour chaque taille et écrit le résultat renvoyé dans un fichier csv.
	entrée: */
{    
	int size = Ksizes[i];
	int result;

    for(int i = 0; i < 5; ++i){
		result = TestTri(Ksizes[i], pf);
		WriteResultInFile(result, size, pf.flag + ".csv");
    }    
}
