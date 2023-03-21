#include "visualisationC.h"
#include <math.h>
#include <stdio.h>
//#include <unistd.h>

void visualisationC(float puissance_f) {

  FILE *verrou;
  verrou = fopen(".verrouData", "wx");
  if (verrou != NULL) {

    // Récupération des températures

    FILE *datas_read;
    datas_read = fopen("data.txt", "r");

    char temp[6];
    float exte;
    float inte;

    fgets(temp, 6, datas_read);
    fscanf(datas_read, "%f", &exte);
    fscanf(datas_read, "%f", &inte);

    fclose(datas_read);

    // Réécriture du fichier
    FILE *etat_chauffage;
    etat_chauffage = fopen("data.txt", "w");

    // Cas où le chauffage doit être allumé
    if (puissance_f > 0) {
      fprintf(etat_chauffage, "true");
    }

    // Cas où le chauffage doit être éteint
    else {
      fprintf(etat_chauffage, "false");
    }

    // Réécriture des températures dans le ficher.

    fprintf(etat_chauffage, "\n%.2f", exte);
    fprintf(etat_chauffage, "\n%.2f", inte);

    fclose(etat_chauffage);
    fclose(verrou);
    remove(".verrouData");
  }
}
