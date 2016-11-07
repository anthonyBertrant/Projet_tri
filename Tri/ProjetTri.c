//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "util.h"
#include "TriInsertSeq.h"
#include "TriBulles.h"
#include "TriSelecPerm.h"
#include "TriRapide.h"
#include "TriInsertDicho.h"
#include "TriFusion.h"
#include "TriArbreBin.h"
#include "TriTas.h"

#define TAB_SIZE(x) (sizeof(x) / sizeof(x[0]))

const int Ksizes[15] = {5, 500, 5000, 10000, 50000, 100000,
                        200000, 300000, 400000, 500000, 600000,
                        700000, 800000, 900000, 1000000};

/* specification:
Execute la fonction de tri passé en parametre et renvoie le temps d'execution
en secondes.
	-en entree: Le tableau non trié, sa taille et le pointeur sur la fonction de tri.
	-en sortie: le temps d'execution de l'algorithme en seconde.
*/
float TestTri (TABLEAU t, size_t tabSize, pf algoTri)
{
    clock_t debut;
    clock_t fin;
    float result = 0.0;
    int i;

    printf("execution des tests\n");
    for(i = 0; i < 20; ++i) {
	GenerateRandTab(t, tabSize);
	
        debut = clock();
        (*algoTri)(t, tabSize);
        fin = clock();

        result += (fin - debut) * 1.0/CLOCKS_PER_SEC;

        if( result >= 300.0){
            printf("ARRET TEST: TIME OUT !\n");
            return result/i;
        }
        printf(". ");
    }
    return (result / i);
}

/* specification:
Lance les tests d'un algorithme de tri sur un tableau de valeurs aleatoires.
Et ce pour chaque taille définie dans Ksizes.
	-en entree: L'algorithme de tri.
	-en sortie: un fichier .csv contenant les résultats des tests.
*/
void ExecuteBenchmarks(t_flags algoTri)
{
    TABLEAU t;
    size_t size;
    float result;

    char filename[100] = "";
    strcat(filename, algoTri.flag);
    strcat(filename, ".csv");

    srand(time(NULL));

    printf("==> DEBUT %s\n\n", algoTri);
    for(size_t i = 0; i < 15; ++i){
        size = Ksizes[i];
        printf("- taille = %d\n", size);
        result = TestTri(t, size, algoTri.pf);
        printf("\n- fin pour taille %d\t\ttmps = %.2f\n\n", size, result);
        WriteResultInFile(result, size, filename);
        if(result >= 15.0) break;
    }
    printf("==> FIN %s\n\n", algoTri);
}

int main()
{
    t_flags functions[]= {
        //{"Tri par Insertion Sequentielle (FIFO)", &TriInsertSeqFIFO},
        //{"Tri Fusion", &TriFusion},
        //{"Tri Rapide", &TriRapide},
        //{"Tri a Bulles", &TriBulles},
        {"Tri par Arbre Binaire", &TriArbreBin},
        //{"Tri par Selection Permutation", &TriSelecPerm},
        //{"Tri par Insertion Dichotomique", &TriInsertDicho},
        //{"Tri par Insertion Sequentielle", &TriInsertSeq}
    };

    size_t i = 0;
	while (i < TAB_SIZE(functions))
	{
		ExecuteBenchmarks(functions[i]);
		++i;
	}
	
	return 0;
}
