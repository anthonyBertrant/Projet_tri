//
//  TriInsertSeq.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//
#include "TriInsertSeq.h"

void TriInsertSeqFIFO(TABLEAU t, size_t tabSize)
{

}

void TriInsertSeq(TABLEAU t, size_t tabSize)
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

