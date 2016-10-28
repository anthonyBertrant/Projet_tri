#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

typedef struct s_flags
{
   char *flag;
   void (*pf)(TABLEAU t, size_t tabSize);
} t_flags;

typedef void (*pf) (TABLEAU, size_t);

/* spécification:
Rempli le tableau passé en paramètre avec des valeurs aléatoires.
	-en entrée: tabSize > 0.
	-en sortie: t[0..tabSize] rempli avec avec des entiers générés aléatoirement.
*/
void GenerateRandTab(TABLEAU t, size_t tabSize);

/* spécification:
    Rempli le fichier *filename, avec le resultat du temps d'execution du tri
 en secondes, pour une taille de donnée.
    _Entrée: result, size > 0, *filename not null
*/
void WriteResultInFile(float result, int size, const char *filename);

/* spécification:
Echange les valeurs présentes dans le tableau passé en paramètre aux indices également passés en paramètre.
	-en entrée: 0 <= x < n, 0 <= y < n avec n étant la taille de t.
	-en sortie: les deux valeurs aux indices x et y ont été échangées.
*/
void Swap(TABLEAU t, int x, int y);

#endif
