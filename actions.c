#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "actions.h"

void appel(int *etg){
    int break1=0;//initialise le break1 à 0
    while(break1!=1){
        printf("A quel etage etes-vous? de -5 a 15. Tapez 100 pour quitter le programme.\n");//demande à l'utilisateur l'etages auquel il se trouve
        scanf("%d",&etg[0]);
        //le programme vérifie si le numéro d'étage est correct
        if((etg[0]>=-5 && etg[0]<=15)||etg[0]==100){
            break1=1;
        }
        else{
            printf("Etages non valide\n");
        }
    }
}

void deplacements(int *tabAscenseurs, int etgAppel){
    int *etgDest=malloc(sizeof(int));
    deplacementAscenceur(tabAscenseurs,etgAppel, choixAscenceur(tabAscenseurs,etgAppel));//le programme execute la fonction choixAscenceurs ensuite le programme execute la fonction deplacementAcenceur
    selection(etgDest);//le programme execute la fonction selection
    deplacementAscenceur(tabAscenseurs,etgDest[0], choixAscenceur(tabAscenseurs,etgAppel));//le programme execute la fonction deplacementAcenceur
}

void selection(int *etg){

    while(1){//on boucle tant que l'utilisateur n'a pas entrée une valeur adéquate
        //le programme demande à l'utilisateur à quel étage il souhaite se rendre
        printf("Selection de l'etage de destination? de -5 a 15.\n");
        scanf("%d",&etg[0]);
        //le programme vérifie si l'étages entrée est compris entre 15 et -5, si ce n'est pas le cas il redemande un étage à l'utilisateur
        if(etg[0]>15 && etg[0]<-5){
            printf("Selection de l'etage de destination? de -5 a 15.\n");
            scanf("%d",&etg[0]);
        }
        //si c'estle cas il arrete la fonction
        else{
            break;
        }
    }
}

int choixAscenceur(int *tabAscenceurs,int etgAppel){
    int numAsc=0;
    for(;numAsc<=5;numAsc++){
        printf("je suis l'ascenceur numero %d et je suis a l'etage %d\n",numAsc+1, tabAscenceurs[numAsc]);//le programme affiche les différents ascenceurs ainsi que l'étages auquel ils se trouvent
    }
    return 0;
}

void deplacementAscenceur(int *tabAscenceurs,int etgDest, int numAsc){
    //le programme tourne tant que l'ascenceur n'est pas au bon étage
    while(tabAscenceurs[numAsc]!=etgDest){
        if(etgDest>tabAscenceurs[numAsc]){
            tabAscenceurs[numAsc]++;//incrémente de 1
            printf("Ascenceur numero %d - Etage %d\n",numAsc,tabAscenceurs[numAsc]);
            Sleep(2000);//attend pendant 2 secondes
        }
        else if(etgDest<tabAscenceurs[numAsc]){
            tabAscenceurs[numAsc]--;//décremente de 1
            printf("Ascenceur numero %d - Etage %d\n",numAsc,tabAscenceurs[numAsc]);
            Sleep(2000);//attend pendant 2 secondes
        }
    }
}
