#include "regulation.h"
#include <stdio.h>
#include <stdlib.h>

float regulation(int regul, float Tmp_Int, float Tmp_cgsn, float *P, float *I,
                 float t) {

  float puissance = 0.;

  float Kp = 1.1;
  float Ki = 0.2;
  float Kd = 0.15;

  float e, D, PID;

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
    // PID
    if (*P == 0 || *I == 0) {
      *P = Kp * e;
      D = 0;
      *I = 0;
    } else {
      e = Tmp_cgsn - Tmp_Int;
      D = (*P - Kp * e) / 2;
      *P = Kp * e;
      *I = *I + (*P * t) / 2;
    }

    PID = *P + *I + D;

    puissance = PID;
    break;
  }
  return puissance;
}

float regulationTest(int regul, float consigne, float *tabT, int nT) {
  float *P, *I;
  

  float cmd = 100.0;
  switch (regul) {
  case 1:
    // TOR
    for (int i = 0; i < nT; i++) {
      cmd = regulation(1, tabT[i], consigne, P, I, 10);
    }
    break;
  case 2:
    for (int i = 0; i < nT; i++) {
      cmd = regulation(2, tabT[i], consigne, P, I, 10);
    }
    break;
  }

  return cmd;
}
