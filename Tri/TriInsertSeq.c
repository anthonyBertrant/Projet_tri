//
//  TriInsertSeq.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriInsertSeq.h"

#include <stdlib.h>

void afficherListe(nodeList *list) {
    while (list)
    {
        printf("%d ", list->value);
        list = list->next;
    }
}

void addNodeInList(nodeList **list, const int value) {
    nodeList *tmpList = *list;
    nodeList *tmpNode;

    nodeList *elem = malloc(sizeof(nodeList));
    elem->value = value;
    elem->next = NULL;

    if (!tmpList) {
        *list = elem;
        return;
    }

    if (value < tmpList->value) {
        elem->next = tmpList;
        *list = elem;
        return;
    }
    else
    {
        tmpNode = tmpList;
        tmpList = tmpList->next;
        while (tmpList)
        {
            if (value <= tmpList->value) break;
            tmpNode = tmpList;
            tmpList = tmpList->next;
        }
        elem->next = tmpList;
        tmpNode->next = elem;
    }

}

void remplirTableau(TABLEAU t, nodeList *list) {
    for (int i = 0; list; ++i) {
        t[i] = list->value;
        list = list->next;
    }
}

void TriInsertSeqFIFO(TABLEAU t, const size_t tabSize)
{
    nodeList *list;
    for (int i = 0; i < tabSize; ++i) {
        addNodeInList(&list, t[i]);
    }
    remplirTableau(t, list);
}

void TriInsertSeq(TABLEAU t, const size_t tabSize)
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


