//
//  TriArbreBin.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriArbreBin.h"

void afficherArbre(node *tree)
{
    if(!tree) return;
    if (tree->left) afficherArbre(tree->left);
    printf("Cle = %d\n", tree->value);
    if (tree->right) afficherArbre(tree->right);
}

void remplirTabAvecArbre(node *tree, TABLEAU t, int *index)
{
    if(!tree) return;
    if (tree->left) remplirTabAvecArbre(tree->left, t, index);
    t[*index] = tree->value;
    (*index)++;
    if (tree->right) remplirTabAvecArbre(tree->right, t, index);
}

void addNode(node **tree, int value)
{
    node *tmpTree = *tree;
    node *tmpNode;

    node *elem = malloc(sizeof(node));
    elem->value = value;
    elem->left = NULL;
    elem->right = NULL;

    if (tmpTree == NULL)
    {
        *tree = elem;
    }
    else
        while (tmpTree)
        {
        tmpNode = tmpTree;
        if(value > tmpTree->value )
        {
            tmpTree = tmpTree->right;
            if(!tmpTree) tmpNode->right = elem;
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) tmpNode->left = elem;
        }
    }
}

node* construireArbre(TABLEAU t, size_t size)
{
    node *arbre = NULL;

    for (size_t i = 0; i < size; ++i)
        addNode(&arbre, t[i]);

    return arbre;
}

void TriArbreBin(TABLEAU t, size_t tabSize)
{
    node *arbre = construireArbre(t, tabSize);
    int index = 0;
    remplirTabAvecArbre(arbre, t, &index);
}
