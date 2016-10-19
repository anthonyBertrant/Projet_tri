//
//  TriArbreBin.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriArbreBin.h"

#define MAX 1000000
typedef int TABLEAU[MAX];

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

void afficherArbre(node *tree)
{
  if(!tree) return;
  if (tree->left)  afficherArbre(tree->left);
  printf("Cle = %d\n", tree->value);
  if (tree->right) afficherArbre(tree->right);
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

node* construireArbre(TABLEAU t, int size)
{
  node *arbre = NULL;
  
  int i;
  for (i = 0; i < size; ++i) 
    addNode(&arbre, t[i]);
  
  return arbre;
}

void TriArbreBin(TABLEAU t, int size)
{
  node *arbre = construireArbre(t, size);
  afficherArbre(arbre);
}

