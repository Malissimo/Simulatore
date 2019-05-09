#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ManageFile.h"


// il codice legge i file in input

int ReadEngine(double *datiengine)
{
    // INIZIALIZZAZIONE delle variabili

    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("Input/engine.txt", "r");
    if (fdat == NULL)
    {

        return 1;}

    int i=0, n=200;
    char buffer[n], *str;

    while(fgets(buffer, n, fdat) != NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            //printf("%s", buffer);
            datiengine[i]=strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
            //printf("%g\n", datiengine[i]);
            //printf("%s\n", str);
            i++;
        }
    }
    fclose(fdat);
    return 0;
}

void PrintEngine(double *datiengine) //stampa a video dati del file engine.txt
{
    printf("\nDATI MOTORE:\n");
    printf("\nPotenza MAX a Quota 0:\t\t\t\t\t\t%g kW\n", datiengine[0]);
    printf("Esponente Legge di Variazione della Potenza con la Quota:\t%g\n", datiengine[1]);
    printf("Numero di Giri MIN:\t\t\t\t\t\t%g rpm\n", datiengine[2]);
    printf("Numero di Giri MAX:\t\t\t\t\t\t%g rpm\n", datiengine[3]);
    printf("Rapporto di Riduzione/Moltiplicazione:\t\t\t\t%g\n", datiengine[4]);
    printf("Rendimento della Trasmissione:\t\t\t\t\t%g\n", datiengine[5]);
    printf("Consumo Specifico:\t\t\t\t\t\t%g kg/s\n", datiengine[6]);
    printf("\nFile 'engine.txt' letto con successo\n");
}


int ReadPropeller(double *datipropeller, double **matricepropeller)
{
    // INIZIALIZZAZIONE delle variabili

    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("Input/propeller.txt", "r");
    if (fdat == NULL)
    {

        return 1;}

    int i=0, j=0, n=200, flag=0;
    char buffer[n], *str;

    while(fgets(buffer, n, fdat) != NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            if(buffer[0]=='C')
            {
                flag = 1;
            }
            if (flag==0)
            {
                //printf("%s", buffer);
                datipropeller[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
                //printf("%g\n", datipropeller[i]);
                //printf("%s\n", str);
            }
            else
            {
                sscanf(buffer,"%lf %lf %lf %lf", &matricepropeller[i][0], &matricepropeller[i][1], &matricepropeller[i][2], &matricepropeller[i][3]);
            }
            i++;
        }

    }
    fclose(fdat);
    return 0;
}