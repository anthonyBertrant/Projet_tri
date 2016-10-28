#ifndef TRIFUSION_H
#define TRIFUSION_H

#include <stdio.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

void Fusion(TABLEAU t, int debut, int pivot, int fin);

void TriFusionRecurs(TABLEAU t, int debut, int fin);

void TriFusion(TABLEAU t, size_t tabSize);

#endif
