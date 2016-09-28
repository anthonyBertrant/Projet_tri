
#ifndef HEADERFILE_H
#define HEADERFILE_H

#define MAX 1000000
typedef int TABLEAU[MAX];

void GenerateRandTab(TABLEAU t, int tabSize);

void WriteResultInFile(int result, int taille, const char *filename);

void Swap(TABLEAU t, int indice1, int indice2);

#endif
