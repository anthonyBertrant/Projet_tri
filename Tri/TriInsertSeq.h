#ifndef TRIINSERTSEQ_H
#define TRIINSERTSEQ_H

#include <stdio.h>

#define MAX 100000
typedef int TABLEAU[MAX];

typedef struct node {
    int value;
    struct node *next;
} node;

void TriInsertSeqFIFO(TABLEAU t, size_t tabSize);
void TriInsertSeq(TABLEAU t, size_t tabSize);

#endif
