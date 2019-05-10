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


int ReadPropeller(double *datipropeller, double *CSI,double *RD, double *CH, double *BA)
{
    // INIZIALIZZAZIONE delle variabili

    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("Input/propeller.txt", "r");
    if (fdat == NULL)
    {

        return 1;}

    int i=0, n=200, flag=0;
    char buffer[n], *str, *col1, *col2, *col3;

    while(fgets(buffer, n, fdat) != NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            if(buffer[0]=='C') //divide la prima parte del file dalla tabella sotto, azzerando il contatore
            {
                flag= 1;
                i=0;
                continue;
            }
            if (flag==0) {
                //printf("%s", buffer);
                datipropeller[i] = strtof(buffer,&str); //converte il segmento in un numero e lo colloca nel vettore dati
                //printf("%g\n", datipropeller[i]);
                //printf("%s\n", str);
            }
            else
            {
                //printf("%s",buffer);
                CSI[i] = strtof(buffer,&col1); // salva un vettore CSI
                RD[i] = strtof(col1,&col2); // salva un vettore RD
                CH[i] = strtof(col2,&col3); //salva un vettore CH
                BA[i] = strtof(col3,&str); //salva in vettore BA
                //printf("%g\n", CSI[i]);
                //printf("%g\n", RD[i]);
                //printf("%g\n", CH[i]);
                //printf("%g\n", BA[i]);

                if(buffer[0]=='1')
                {
                    break;
                }
            }
            i++;
        }
    }
    fclose(fdat);
    return 0;
}


void PrintPropeller(double *datipropeller) //stampa a video i dati del file propeller.txt, tranne la tabella finale
{
    printf("\nDATI GEOMETRICI ELICA:\n");
    printf("\nDiametro Elica:\t\t\t\t\t\t%g m\n", datipropeller[0]);
    printf("Diametro Ogiva:\t\t\t\t\t\t%g m\n", datipropeller[1]);
    printf("Numero di Pale:\t\t\t\t\t\t%g \n", datipropeller[2]);
    printf("Inerzia:\t\t\t\t\t\t%g kgm^2\n", datipropeller[3]);
    printf("Numero Stazioni:\t\t\t\t\t%g \n", datipropeller[4]);
    printf("\nDATI AERODINAMICI ELICA:\n");
    printf("\nCl_alfa:\t\t\t\t\t%g rad^-1\n", datipropeller[5]);
    printf("Cl_0:\t\t\t\t\t\t%g \n", datipropeller[6]);
    printf("a_0:\t\t\t\t\t\t%g rad\n", datipropeller[7]);
    printf("Cd_alfa^2:\t\t\t\t\t%g rad^-2\n", datipropeller[8]);
    printf("Cd_alfa:\t\t\t\t\t%g rad^-1\n", datipropeller[9]);
    printf("Cd_0:\t\t\t\t\t\t%g rad^-1\n", datipropeller[10]);
    printf("\nCARATTERISTICHE ELICA lette con successo\n");
    printf("\nFile 'propeller.txt' letto con successo\n");
}


int ReadDBA(double*descvel)
{
    // INIZIALIZZAZIONE delle variabili

    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("Input/dba.txt", "r");
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
            descvel[i]=strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
            //printf("%g\n", datiengine[i]);
            //printf("%s\n", str);
            i++;
        }
    }
    fclose(fdat);
    return 0;
}