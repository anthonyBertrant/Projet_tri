#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

void TriTas(TABLEAU t, int tabSize);
/*effectue le trie sur un tas. le tas est un tableau passer en parametre*/

void organiserTas(TABLEAU t, int n);
/*Organise le tas selon un tableau, chaque noeud est plus grand que
 ses feuilles*/

void descendre(TABLEAU t, int d, int f);
/*Descendre permet de réorganiser un tas dont la racine n'est pas à sa place.
 La racine se trouve à l'indice d. f est le depart de la descente
 Pour des explemes, voir TriTas tout en bas*/



#endif
