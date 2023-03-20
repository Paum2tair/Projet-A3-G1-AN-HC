#include <stdio.h>
#include <stdlib.h>

#include "simulateur.h"
#include "consigne.h"
#include "regulation.h"
#include "visualisationC.h"
#include "visualisationT.h"

int main(){

	temp_t temperature;
	temperature.exterieure = 14.0;
	temperature.interieure = 15.0;
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
	int i=0; // increment de boucle
	float puissance = 70.0; // puissance de chauffage
	for(i=0;i< 30;i++){
		temperature=simCalc(puissance,monSimulateur_ps); // simulation de l'environnement
	}
	simDestruct(monSimulateur_ps); // destruction de simulateur

  printf("Bonjour\n");
  
  
  visualisationT(temperature);

  float cgsn = 0;
  cgsn = consigne(cgsn);

  puissance = regulation(1, temperature.interieure, cgsn);
  printf("%.2f", puissance);

  visualisationC(puissance);


  
	return EXIT_SUCCESS;
}
