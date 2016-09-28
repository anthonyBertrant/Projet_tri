//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000
typedef int TABLEAU[MAX];

void TriRapide(int t){
    printf("rapide\n");
}
    

void TriFusion(int t){
	printf("fusion\n");
}


typedef void (*p)(); // pointeur sur fonction retournant un int et en prenant 2 en parametres.
 

#define TAB_SIZE(x) (sizeof(x) / sizeof(x[0]))

int main()
{
	p flags[]= {
	   &TriFusion,
	   &TriRapide,   
	};

	// on parcours notre tableau jusqu'a trouver la bonnne fonction. ici appeleras la fonction is_i
	int i = 0;
	while (i < TAB_SIZE(flags))
	{
		flags[i](0);
		i++;
	}
	
	return(0);
}
