#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

void TriInsertDicho(TABLEAU t, int tabSize);

int position_dicho(int i,TABLEAU t);

void translation(int p, int i, TABLEAU t);


#endif
