#include <stdio.h>

#include "consigne.h"
#include "regulation.h"
#include "visualisationC.h"
#include "visualisationT.h"


int main(void) {
  
  printf("Bonjour\n");

 temp_t temperature;
  temperature.interieure = 21.79;
  temperature.exterieure = 10.84;

  
  
  visualisationT(temperature);

  float cgsn = 0;
  cgsn = consigne(cgsn);

  float puissance = regulation(1, temperature.interieure, cgsn);
  printf("%.2f", puissance);

  visualisationC(puissance);
  
  
  return 0;
}