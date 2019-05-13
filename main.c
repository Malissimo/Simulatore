#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ManageFile.h"
#include "Atmosphere.h"
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
    double descvel[1000], deflec[1000], massacomb[1000];
    double alpha[1000],CX[1000],CY[1000],CZ[1000],Cl[1000],Cm[1000],Cn[1000];
    double CXA[1000],CXAP[1000],CXU[1000],CXQ[1000],CXB[1000],CXP[1000],CXR[1000];
    double CYB[1000],CYBP[1000],CYP[1000],CYR[1000],CYA[1000],CYQ[1000];
    double CZALPHA[1000],CZAP[1000],CZU[1000],CZQ[1000],CZB[1000],CZP[1000],CZR[1000];
    double ClB[1000],ClBP[1000],ClP[1000],ClR[1000],ClA[1000],ClQ[1000];
    double CmA[1000],CmAP[1000],CmU[1000],CmQ[1000],CmB[1000],CmP[1000],CmR[1000];
    double CnB[1000],CnBP[1000],CnP[1000],CnR[1000],CnA[1000],CnQ[1000];
    double CXde[1000],CXdle[1000],CZde[1000],CZdle[1000],CYda[1000],CYdr[1000];
    double Clda[1000],Cldr[1000],Cmde[1000],Cmdle[1000],Cnda[1000],Cndr[1000];
    double CXom[1000],CYom[1000],CZom[1000],Clom[1000],Cmom[1000],Cnom[1000];
    int ritorno=0;

    //#2.2 Apertura dei file, lettura e salvataggio su vettori

    ritorno = ReadEngine(datiengine);// controllo lettura file engine.txt
    if (ritorno==1)
    {
        printf("[!]ERRORE nella lettura del file engine.txt\n");
        exit(10);
    }
    else
        {
        PrintEngine(datiengine);
        }

    ritorno = ReadPropeller(datipropeller, CSI, RD, CH, BA);// controllo lettura file propeller.txt
    if (ritorno==1)
    {
        printf("[!]ERRORE nella lettura del file propeller.txt\n");
        exit(10);
    }
    else
        {
        PrintPropeller(datipropeller);
        }

    ritorno = ReadDBA(descvel, deflec, massacomb,
            alpha,CX,CY,CZ,Cl,Cm,Cn,
            CXA,CXAP,CXU,CXQ,CXB,CXP,CXR,
            CYB,CYBP,CYP,CYR,CYA,CYQ,
            CZALPHA,CZAP,CZU,CZQ,CZB,CZP,CZR,
            ClB,ClBP,ClP,ClR,ClA,ClQ,
            CmA,CmAP,CmU,CmQ,CmB,CmP,CmR,
            CnB,CnBP,CnP,CnR,CnA,CnQ,
            CXde,CXdle,CZde,CZdle,CYda,CYdr,
            Clda,Cldr,Cmde,Cmdle,Cnda,Cndr,
            CXom,CYom,CZom,Clom,Cmom,Cnom);// controllo lettura file dba.txt
    if (ritorno==1)
    {
        printf("[!]ERRORE nella lettura del file propeller.txt\n");
        exit(10);
    }
    else
    {
        printf("\nFile 'dba.txt' letto con successo\n");
    }

    //#2.3 Dati atmosferici

    double press=101225 ,temp=15 ,rho=1.225, vsuono=340;

    Atmosphere(press,temp,rho,vsuono);


    return 0;
}
