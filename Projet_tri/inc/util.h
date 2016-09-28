
#ifndef HEADERFILE_H
#define HEADERFILE_H

void GenerateRandTab(TABLEAU t, int tabSize);
/* spécification: 
Rempli le tableau passé en paramètre avec des valeurs aléatoires.
	-en entrée: tabSize > 0.
	-en sortie: t[0..tabSize] rempli avec avec des entiers générés aléatoirement.
*/

void WriteResultInFile(int result, int size, const char *filename);
/* spécification: 

*/

void Swap(TABLEAU t, int x, int y);
/* spécification:
Echange les valeurs présentes dans le tableau passé en paramètre aux indices également passés en paramètre. 
	-en entrée: 0 <= x < n, 0 <= y < n avec n étant la taille de t.
	-en sortie: les deux valeurs aux indices x et y ont été échangées.
*/


#endif
