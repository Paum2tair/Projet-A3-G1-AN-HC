#include <stdio.h>

#include "consigne.h"
#include "regulation.h"
#include "visualisationC.h"
#include "visualisationT.h"


int main(void) {
  
  printf("Bonjour\n");

 temp_t temperature;
  temperature.interieure = 14.4;
  temperature.exterieure = 22.89;

  
  
  visualisationT(temperature);

  float cgsn = 0;
  cgsn = consigne(cgsn);
  
  
  
  return 0;
}