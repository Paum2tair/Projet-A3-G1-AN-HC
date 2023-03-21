#ifndef REGULATION_H
#define REGULATION_H

#include "define.h"
#include <stdio.h>
#include <stdlib.h>

float regulation(int regul, float Tmp_Int, float Tmp_cgsn, float *P, float *I, float t);

float regulationTest(int regul, float consigne, float *tabT, int nT);

#endif