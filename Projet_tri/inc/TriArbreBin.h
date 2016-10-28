#ifndef TRIARBREBIN_H
#define TRIARBREBIN_H

#include <stdio.h>

#define MAX 100000
typedef int TABLEAU[MAX];

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

/*
  Affiche le contenu tri� d'un arbre binaire de recherche.
    -en entr�e: l'arbre � afficher.
*/
void afficherArbre(node *tree);

/*
  Ajoute un noeud � un arbre binaire de recherche.
    -en entr�e: un pointeur sur l'arbre et la valeur du noeud � ajouter.
    -en sortie: le noeud a �t� ajout� � l'arbre en respectant le principe de l'arbre binaire de recherche.
*/
void ajouterNoeud(node **tree, int value);

/*
  Construit un arbre binaire de recherche � partir d'un tableau.
    -en entr�e: un tableau d'entier et sa taille.
    -en sortie: un pointeur sur la racine de l'arbre.
*/
node* construireArbre(TABLEAU t, size_t size);

/*
  Tri un tableau � l'aide d'un arbre binaire de recherche.
    -en entr�e: le tableau � trier et sa taille.
*/
void TriArbreBin(TABLEAU t, size_t tabSize);

#endif
