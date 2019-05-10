#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ManageFile.h"
int main() {
    /////////////////////
    ///#1 INTESTAZIONE//////////////////////////////////////////////////////////////////////
    /////////////////////

    printf("SIMULATORE CESSNA 172\n");
    printf("Politecnico di Torino\n");
    printf("Corso di Simulazione del Volo - Prof. G. Guglieri\nGiugno 2019\n");
    printf("Sviluppato da:\n Emanuele Frediani\n Davide Locardi s249043\n Erika Mai\n Simone Malisani\n");

    /////////////////////////////
    ///#2 LETTURA INPUT (dati)//////////////////////////////////////////////////////////////
    /////////////////////////////
    // #2.1 Definizione delle variabili da leggere

    double datiengine [7], datipropeller[11];
    double CSI[100],RD[100], CH[100], BA[100];
    int ritorno=0;


    // #2.1 Definizione delle variabili da leggere

    //#2.2 Apertura dei file, lettura e salvataggio su vettori
    ritorno = ReadEngine(datiengine);
    if (ritorno==1){
        printf("[!]ERRORE nella lettura del file engine.txt\n");
        exit(10);
    }

    PrintEngine(datiengine);

    ritorno = ReadPropeller(datipropeller, CSI, RD, CH, BA);
    if (ritorno==1){
        printf("[!]ERRORE nella lettura del file propeller.txt\n");
        exit(10);
    }

    PrintPropeller(datipropeller);
    return 0;
}
