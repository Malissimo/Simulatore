#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReadFile.h"


// il codice legge i file in input

int Readengine (double datiengine[])
{
    // INIZIALIZZAZIONE delle variabili
    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("engine.txt", "r");
    int i=-1, n=200;
    char buffer[n], *str;
    double value;


    if (fdat == NULL)
        {return 1;}

    
    while(fgets(buffer, n, fdat)!= NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            i++;

            datiengine[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
            //printf("value : %g\n", datiengine[i]);
        }
    }
    fclose(fdat);
    return 0;
}

int ReadPropeller (double datipropeller[])
{
    // INIZIALIZZAZIONE delle variabili
    FILE *fdat; //puntatore al file di input (.txt)

    int i=-1, n=200;
    char buffer[n], *str;
    double value;

    fdat = fopen("propeller.txt", "r");

    if (fdat == NULL)
    {return 1;}


    while(fgets(buffer, n, fdat)!= NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            i++;

            datiengine[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
            //printf("value : %g\n", datiengine[i]);
        }
    }
    fclose(fdat);
    return 0;
}