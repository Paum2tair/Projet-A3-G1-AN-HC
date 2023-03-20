#include "regulation.h"
#include <stdio.h>
#include <stdlib.h>

float regulation(int regul, float Tmp_Int, float Tmp_cgsn) {

  float puissance = 0.;
  switch (regul) {
  case 1:
    // Tout ou rien
    if (Tmp_Int >= Tmp_cgsn) {
      puissance = 0;
    } else if (Tmp_Int < Tmp_cgsn) {
      puissance = 50.0;
    }
    break;
  case 2:
    break;

    // PID
  }
  return puissance;
}

float regulationTest(int regul, float consigne, float *tabT, int nT) {
  float cmd = 100.0;

  return cmd;
}
