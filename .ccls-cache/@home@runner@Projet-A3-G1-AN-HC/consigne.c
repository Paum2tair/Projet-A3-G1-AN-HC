#include "consigne.h"

float consigne(float csgn) {
  FILE *verrou;
  verrou = fopen(".verrouConsigne", "wx");
  if (verrou != NULL) {
    FILE *consigne;
    if ((consigne = fopen("consigne.txt", "r")) == NULL) {
      printf("Impossibe d'ouvrir le fichier consigne.txt\n");
      return 0;
    }
    /*while(fgets(cons, 8, consigne) != NULL){
          printf("%s", cons);
    }*/
    fscanf(consigne, "%f", &csgn);
    fclose(consigne);
    // Fermeture et suppression du verrou
    fclose(verrou);
    remove(".verrouConsigne");
  }
  return csgn;
}
