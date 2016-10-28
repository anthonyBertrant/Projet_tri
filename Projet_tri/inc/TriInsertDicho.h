#ifndef TRIINSERTDICHO_H
#define TRIINSERTDICHO_H

#include <stdio.h>

#define MAX 100000
typedef int TABLEAU[MAX];

void TriInsertDicho(TABLEAU t, size_t tabSize);

int position_dicho(int i,TABLEAU t);

void translation(int p, int i, TABLEAU t);


#endif
