#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"


#include "consigne.h"
#include "regulation.h"
#include "simulateur.h"
#include "visualisationC.h"
#include "visualisationT.h"
#include "releve.h"
#include "autotests.h"

//#include "ftd2xx.h"

int main() {
  
    temp_t temperature;
    temperature.exterieure = 14.0;
    temperature.interieure = 15.0;
    struct simParam_s *monSimulateur_ps = simConstruct(
        temperature);       // creation du simulateur, puissance intialisée à 0%
    int i = 0;              // increment de boucle
    float puissance = 70.0; // puissance de chauffage
    for (i = 0; i < 300; i++) {

      visualisationT(temperature);
      float cgsn = consigne(cgsn);
      puissance = regulation(1, temperature.interieure, cgsn);
      visualisationC(puissance);

      temperature =
          simCalc(puissance, monSimulateur_ps); // simulation de l'environnement
    }
    simDestruct(monSimulateur_ps); // destruction de simulateur
  
  /*printf("Bonjour\n");
  float score = 0;
  score = testConsigne();
  float score2 = 0;
  score2 =testVisualisationT();
  float score3 = 0;
  score3 = testVisualisationC();
  float score4 = 0;
  score4 = testRegulationTOR();
  printf("\n test consigne %f", score);

  printf("\n test visuT %f", score2);
  printf("\n test visuC %f", score3);
  printf("\n test consigne %f", score4);*/

  /*float score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0;
  score1 = testVisualisationT();
  score2 = testConsigne();
  score3 = testVisualisationC();

  score4 = testRegulationTOR();
  score5 = testRegulationPID();
//  sleep(5);
  printf("----- Auto tests results: -----\n");
  printf("testVisualisationT\t:score=%g%%\n", score1 * 100);
  printf("testConsigne \t\t: score=%g %%\n", score2 * 100);
  printf("testVisualisationC\t:score=%g %%\n", score3 * 100);
  printf("testRegulationTOR\t:score=%g %%\n", score4 * 100);
  printf("testRegulationPID\t:score=%g %%\n", score5 * 100);*/

  return EXIT_SUCCESS;
}
