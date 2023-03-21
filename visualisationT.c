#include "visualisationT.h"

void visualisationT(temp_t myTemp) {

  FILE *verrou;
  verrou = fopen(".verrouData", "wx");
  if ( verrou == NULL ) {

    // lecture de la première ligne du fichier
    FILE *datas_read;
    datas_read = fopen("data.txt", "r");

    char etat_chauffage[5];

    fgets(etat_chauffage, 5, datas_read);

    fclose(datas_read);

    //écriture dans le fichier
    FILE *datas_write;
    datas_write = fopen("data.txt", "w");

    fprintf(datas_write, "%s", etat_chauffage);
    fprintf(datas_write, "\n%.2f", myTemp.exterieure);
    fprintf(datas_write, "\n%.2f", myTemp.interieure);

    fclose(datas_write);
    fclose(verrou)
    remove(".verrouData");
  }
}
