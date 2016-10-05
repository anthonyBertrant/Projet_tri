
#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

struct s_flags
{
   char  flag;
   void   (*p)(TABLEAU t, int tabSize);
};
typedef struct s_flags t_flags;

void GenerateRandTab(TABLEAU t, int tabSize);
/* spécification: 
Rempli le tableau passé en paramètre avec des valeurs aléatoires.
	-en entrée: tabSize > 0.
	-en sortie: t[0..tabSize] rempli avec avec des entiers générés aléatoirement.
*/

void WriteResultInFile(float result, int size, const char *filename);
/* spécification: 
    Rempli le fichier *filename, avec le resultat du temps d'execution du tri 
 en secondes, pour une taille de donnée.
    _Entrée: result, size > 0, *filename not null
*/

void Swap(TABLEAU t, int x, int y);
/* spécification:
Echange les valeurs présentes dans le tableau passé en paramètre aux indices également passés en paramètre. 
	-en entrée: 0 <= x < n, 0 <= y < n avec n étant la taille de t.
	-en sortie: les deux valeurs aux indices x et y ont été échangées.
*/

void afficherTableau(TABLEAU t, int tabSize);

#endif
