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

int TestTri (int tabSize, t_flags &pf)
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
	-entrée: structure de pointeur sur fonction
	-sortie: fichier .csv contenant les résultats*/
{    
	int size = Ksizes[i];
	int result;

    for(int i = 0; i < 5; ++i){
		result = TestTri(Ksizes[i], pf);
		WriteResultInFile(result, size, pf.flag + ".csv");
    }    
}
