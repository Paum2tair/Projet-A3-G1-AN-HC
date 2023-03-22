#include "regulation.h"
#include <stdio.h>
#include <stdlib.h>

float regulation(int regul, float Tmp_Int, float Tmp_cgsn, int itteration,
                 float *Iancien, float *Pancien, float *Eancien, int t) {

  float puissance = 0.0;
  // Création des coefficient
  float Kp = 1.1;
  float Ki = 0.2;
  float Kd = 0.15;

  // valeures temporaires
  float P, I, D, e;

  // Différenciation des deux types de régulation
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
    // erreur
    e = Tmp_cgsn - Tmp_Int;

    // Calcul de P
    P = Kp * e;

    if (itteration == 0) {
      // première itteration
      puissance = P;

    } else {
      // autres ittérations

      // calcul de I
      I = *Iancien + Ki * ((e * t) - ((e - *Eancien) * t / 2));

      // calcul de D
      D = Kd * ((e - *Eancien) / t);

      puissance = P + I + D;

      // Mise à jour de l'ancien I
      *Iancien = I;
    }
    // Mise à jour des anciens P et e
    *Pancien = P;
    *Eancien = e;
    break;

    // Filtre pour éviter des valeurs incohérentes
  }
  if (puissance < 0) {
    puissance = 0;
  } else if (puissance > 100) {
    puissance = 100;
  }
  printf(" \nP: %f  I: %f   D : %f", P, I, D);
  return puissance;
}

// Fonction regulationTest

float regulationTest(int regul, float consigne, float *tabT, int nT) {

  float *Iancien = (float *)malloc(sizeof(float));
  *Iancien = 0;
  float *Pancien = (float *)malloc(sizeof(float));
  *Pancien = 0;
  float *Eancien = (float *)malloc(sizeof(float));
  *Eancien = 0;

  float cmd = 100.0;
  switch (regul) {
  case 1:
    // TOR
    for (int i = 0; i < nT; i++) {
      cmd = regulation(1, tabT[i], consigne, i, Iancien, Pancien, Eancien, 10);
    }
    break;
  case 2:
    // PID
    for (int i = 0; i < nT; i++) {
      cmd = regulation(2, tabT[i], consigne, i, Iancien, Pancien, Eancien, 10);
    }
    break;
  }

  free(Pancien);
  free(Iancien);
  free(Eancien);

  return cmd;
}
