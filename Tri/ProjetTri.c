//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//

#include "ExecuteBenchmark.h"
#include "util.h"

#define TAB_SIZE(x) (sizeof(x) / sizeof(x[0]))

int main()
{
	t_flags functions[]= {
	   {"TriBulles", &TriBulles},
	   {"TriInsertSeq", &TriInsertSeq}, 
	};

	int i = 0;
	while (i < TAB_SIZE(flags))
	{
		ExecuteBenchmark(functions[i]);
		i++;
	}
	
	return(0);
}
