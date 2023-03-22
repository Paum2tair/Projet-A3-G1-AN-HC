#ifndef REGULATION_H
#define REGULATION_H

#include "define.h"
#include <stdio.h>
#include <stdlib.h>

float regulation(int regul, float Tmp_Int, float Tmp_cgsn, int itteration, float *Iancien, float *Pancien, float *Eancien, int t);

float regulationTest(int regul, float consigne, float *tabT, int nT);

#endif