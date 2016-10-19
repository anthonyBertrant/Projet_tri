#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

/*
  Affiche le contenu trié d'un arbre binaire de recherche.
    -en entrée: l'arbre à afficher.
*/
void afficherArbre(node *tree);

/*
  Ajoute un noeud à un arbre binaire de recherche.
    -en entrée: un pointeur sur l'arbre et la valeur du noeud à ajouter.
    -en sortie: le noeud a été ajouté à l'arbre en respectant le principe de l'arbre binaire de recherche.
*/
void ajouterNoeud(node **tree, int value);

/*
  Construit un arbre binaire de recherche à partir d'un tableau.
    -en entrée: un tableau d'entier et sa taille.
    -en sortie: un pointeur sur la racine de l'arbre.
*/
node* construireArbre(TABLEAU t, int size);

/*
  Tri un tableau à l'aide d'un arbre binaire de recherche.
    -en entrée: le tableau à trier et sa taille.
*/
void TriArbreBin(TABLEAU t, int size);

#endif
