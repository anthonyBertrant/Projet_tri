#ifndef TRIRAPIDE_H
#define TRIRAPIDE_H

#include <stdio.h>

#define MAX 100000
typedef int TABLEAU[MAX];

void TriRapideRecurs(TABLEAU t, int begin, int end);
/*spec: prend en entrée un tableau t a trié, un indice de debut de tri et un
 indice de fin de trie.
 sortie: void (tableau trié)
 */

int partition(TABLEAU t, int left, int right);
/*spec: placer un élément du tableau (appelé pivot) à sa place définitive, en permutant
 tous les éléments de telle sorte que tous ceux qui sont inférieurs
 au pivot soient à sa gauche et que tous ceux qui sont supérieurs au pivot soient à sa droite. */

void TriRapide(TABLEAU t, size_t tabSize);

#endif
