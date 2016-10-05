#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

void Fusion(TABLEAU t, int debut, int pivot, int fin);
void TriFusionRecurs(TABLEAU t, int debut, int fin);

void TriFusion(TABLEAU t, int tabSize);

#endif
