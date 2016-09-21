//
//  ProjetTri.c
//  Tri
//
//  Created by Anthony Bertrant on 21/09/2016.
//  Copyright © 2016 AnthonyBertrant_BriceMaussang. All rights reserved.
//


#include <stdlib.h>
#include "ExecuteBenchmark.h"

#include "TriInsertSeq.h"
#include "TriInsertDicho.h"
#include "TriSelecPerm.h"
#include "TriBulles.h"
#include "TriFusion.h"
#include "TriRapide.h"
#include "TriArbreBin.h"
#include "TriTas.h"
#include "util.h"

const int Tailles[15] = {100, 500, 5000, 10000, 50000, 100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
=======
#include <stdlib.h>
#include "ExecBenchmark.h";
>>>>>>> master


int main(){

    WriteResultInFile(187, 5000, "test2.csv");
	return(0);
}
