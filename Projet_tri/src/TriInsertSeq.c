//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include <stdio.h>
#include "TriInsertSeq.h"


void TriInsertSeq(TABLEAU array)
{
  int i, p, x;
  
  for (i = 1; i < n; ++i)
  {
    p = 0;
    while (array[p] < array[i]) ++p;
    
    x = array[i];
    
    for (j = i-1; p <= j; j = j-1)
      array[j+1] = t[j];
      
    t[p] = x;
  }  
}

