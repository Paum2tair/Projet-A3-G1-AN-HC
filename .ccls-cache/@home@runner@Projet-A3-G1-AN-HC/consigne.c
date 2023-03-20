#include "consigne.h"

   float consigne(float csgn)
    {
      if (access(".verrouConsigne", 0) != 0) {
        FILE *consigne;
        if ((consigne = fopen("consigne.txt", "r")) == NULL){
          printf("Impossibe d'ouvrir le fichier consigne.txt\n");
          return 0;
        }
        /*while(fgets(cons, 8, consigne) != NULL){
              printf("%s", cons);
        }*/
        fscanf(consigne,"%f", &csgn);
        fclose(consigne);
      }
      return csgn;
      }
      
