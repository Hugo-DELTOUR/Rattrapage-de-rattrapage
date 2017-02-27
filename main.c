#include <stdio.h>
#include <stdlib.h>
#include "actions.h"

int main()
{
    int *tabAscenseurs=malloc(sizeof(tabAscenseurs)* NBASC);//alloue de la mémoire et cree un tableau tabAscenceur
    int i=0;
    int *etgAppel=malloc(sizeof(int));//alloue de la mémoire a etgAppel
    int *etgDest=malloc(sizeof(int));//alloue de la mémoire a etgDest
    for(;i<6;i++){
        tabAscenseurs[i]=0;
    }
    do{
        appel(etgAppel);
        if (etgAppel[0]!=100){
            deplacements(tabAscenseurs,etgAppel[0]);
        }
    }
    while(etgAppel[0]!=100);//le programme vérifie que le numéro appellé soit différent de 100 sinon le programme s'arrete
    printf("Arret des ascenceurs");
    free(tabAscenseurs);
}
