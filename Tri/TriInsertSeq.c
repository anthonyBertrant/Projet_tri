//
//  TriInsertSeq.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriInsertSeq.h"

void afficherListe(nodeList *list) {
    while (list)
    {
        printf("%d ", list->value);
        list = list->next;
    }
}

void addNodeInList(nodeList **list, int value) {
    nodeList *tmpList = *list;
    nodeList *tmpNode;

    nodeList *elem = malloc(sizeof(nodeList));
    elem->value = value;
    elem->next = NULL;

    if (!tmpList) {
        *list = elem;
        printf("1 seul element\n");
        return;
    }

    if (value < tmpList->value) {
        elem->next = tmpList;
        *list = elem;
        printf("insere avant\n");
        return;
    }
    else
    {
        tmpNode = tmpList->next;
        while (tmpNode)
        {
            if (value <= tmpNode->value) break;
            tmpNode = tmpList->next;
        }
        elem->next = tmpNode;
        tmpList->next = elem;
    }
    afficherListe(*list);
}

void TriInsertSeqFIFO(TABLEAU t, size_t tabSize)
{
    nodeList *list;
    for (int i = 0; i < tabSize; ++i)
        addNodeInList(&list, t[i]);
    afficherListe(list);
}

void TriInsertSeq(TABLEAU t, size_t tabSize)
{
    for(size_t i = 0; i < tabSize; ++i){
        int x = t[i];
        int j = i;

        while(j > 0 && t[j - 1] > x){
            t[j] = t[j - 1];
            j -=1;
        }
        t[j] = x;
    }
}

