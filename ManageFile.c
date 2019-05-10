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


int ReadDBA(double*descvel, double *deflec, double *massacomb,
        double *alpha, double *CX,double *CY,double *CZ,double *Cl,double *Cm,double *Cn,
        double *CXA	,double *CXAP,double *CXU,double *CXQ,double *CXB,double *CXP,double *CXR,
        double *CYB,double *CYBP,double *CYP,double *CYR,double *CYA,double *CYQ,
        double *CZALPHA,double *CZAP,double *CZU,double *CZQ,double *CZB,double *CZP,double *CZR,
        double *ClB,double *ClBP,double *ClP,double *ClR,double *ClA,double *ClQ,
        double *CmA,double *CmAP,double *CmU,double *CmQ,double *CmB,double *CmP,double *CmR,
        double *CnB,double *CnBP,double *CnP,double *CnR,double *CnA,double *CnQ,
        double *CXde,double *CXdle,double *CZde,double *CZdle,double *CYda,double *CYdr,
        double *Clda,double *Cldr,double *Cmde,double *Cmdle,double *Cnda,double *Cndr,
        double *CXom,double *CYom,double *CZom,double *Clom,double *Cmom,double *Cnom)
{
    // INIZIALIZZAZIONE delle variabili

    FILE *fdat; //puntatore al file di input (engine.txt)
    fdat = fopen("Input/dba.txt", "r");
    if (fdat == NULL)
    {

        return 1;}

    int i=0, n=200,flag=0;
    char buffer[n], *str, *col1, *col2, *col3, *col4, *col5, *col6, *col7;

    while(fgets(buffer, n, fdat) != NULL) //fgest restituisce NULL quando arriva a EOF
    {
        if(buffer[0]=='*' || buffer[0]=='A' || buffer[1]=='*') //non vengono lette le righe che iniziano con *
        {
            continue;
        }
        else
        {
            if(flag==0)//prende i dati di DESCRIZIONE VELIVOLO (con uno 0 in più iniziale perchè legge gli spazi iniziali)
            {
                //printf("%s", buffer);
                descvel[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
                //printf("%g\n", descvel[i]);
                //printf("%s\n", str);
                if(i==22)
                {
                    flag=1;
                    i=0;
                    continue;
                }
                i++;
            }

            if(flag==1)//prende i dati DEFFLECTION LIMITS
            {
                //printf("%s", buffer);
                deflec[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
                //printf("%g\n", deflec[i]);
                //printf("%s\n", str);
                if(i==5)
                {
                    flag=2;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==2)//prende i dati MASSA COMBUSTIBILE
            {
                //printf("%s", buffer);
                massacomb[i] = strtof(buffer, &str); //converte il segmento in un numero e lo colloca nel vettore dati
                //printf("%g\n", massacomb[i]);
                //printf("%s\n", str);
                if(i==1)
                {
                    flag=3;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==3)//prende la tabella STEADY STATE COEFFICIENTS dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CX[i] = strtof(col1,&col2);
                CY[i] = strtof(col2,&col3);
                CZ[i] = strtof(col3,&col4);
                Cl[i] = strtof(col4,&col5);
                Cm[i] = strtof(col5,&col6);
                Cn[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CX[i]);
                //printf("%g\n", CY[i]);
                //printf("%g\n", CZ[i]);
                //printf("%g\n", Cl[i]);
                //printf("%g\n", Cm[i]);
                //printf("%g\n", Cn[i]);
                if(i==125)
                {
                    flag=4;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==4)//prende la tabella X FORCE DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CXA[i] = strtof(col1,&col2);
                CXAP[i] = strtof(col2,&col3);
                CXU[i] = strtof(col3,&col4);
                CXQ[i] = strtof(col4,&col5);
                CXB[i] = strtof(col5,&col6);
                CXP[i] = strtof(col6,&col7);
                CXR[i] = strtof(col7,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CXA[i]);
                //printf("%g\n", CXAP[i]);
                //printf("%g\n", CXU[i]);
                //printf("%g\n", CXQ[i]);
                //printf("%g\n", CXP[i]);
                //printf("%g\n", CXR[i]);
                if(i==125)
                {
                    flag=5;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==5)//prende la tabella Y FORCE DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CYB[i] = strtof(col1,&col2);
                CYBP[i] = strtof(col2,&col3);
                CYP[i] = strtof(col3,&col4);
                CYR[i] = strtof(col4,&col5);
                CYA[i] = strtof(col5,&col6);
                CYQ[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CYB[i]);
                //printf("%g\n", CXBP[i]);
                //printf("%g\n", CYP[i]);
                //printf("%g\n", CYR[i]);
                //printf("%g\n", CYA[i]);
                //printf("%g\n", CYQ[i]);
                if(i==125)
                {
                    flag=6;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==6)//prende la tabella Z FORCE DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CZALPHA[i] = strtof(col1,&col2);
                CZAP[i] = strtof(col2,&col3);
                CZU[i] = strtof(col3,&col4);
                CZQ[i] = strtof(col4,&col5);
                CZB[i] = strtof(col5,&col6);
                CZP[i] = strtof(col6,&col7);
                CZR[i] = strtof(col7,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CZALPHA[i]);
                //printf("%g\n", CZAP[i]);
                //printf("%g\n", CZU[i]);
                //printf("%g\n", CZQ[i]);
                //printf("%g\n", CZP[i]);
                //printf("%g\n", CZR[i]);
                if(i==125)
                {
                    flag=7;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==7)//prende la tabella ROLLING MOMENT DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                ClB[i] = strtof(col1,&col2);
                ClBP[i] = strtof(col2,&col3);
                ClP[i] = strtof(col3,&col4);
                ClR[i] = strtof(col4,&col5);
                ClA[i] = strtof(col5,&col6);
                ClQ[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", ClB[i]);
                //printf("%g\n", ClBP[i]);
                //printf("%g\n", ClP[i]);
                //printf("%g\n", ClR[i]);
                //printf("%g\n", ClA[i]);
                //printf("%g\n", ClQ[i]);
                if(i==125)
                {
                    flag=8;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==8)//prende la tabella PITCHING MOMENT DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CmA[i] = strtof(col1,&col2);
                CmAP[i] = strtof(col2,&col3);
                CmU[i] = strtof(col3,&col4);
                CmQ[i] = strtof(col4,&col5);
                CmB[i] = strtof(col5,&col6);
                CmP[i] = strtof(col6,&col7);
                CmR[i] = strtof(col7,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CmA[i]);
                //printf("%g\n", CmAP[i]);
                //printf("%g\n", CmU[i]);
                //printf("%g\n", CmQ[i]);
                //printf("%g\n", CmP[i]);
                //printf("%g\n", CmR[i]);
                if(i==125)
                {
                    flag=9;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==9)//prende la tabella YAWING MOMENT DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CnB[i] = strtof(col1,&col2);
                CnBP[i] = strtof(col2,&col3);
                CnP[i] = strtof(col3,&col4);
                CnR[i] = strtof(col4,&col5);
                CnA[i] = strtof(col5,&col6);
                CnQ[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CnB[i]);
                //printf("%g\n", CnBP[i]);
                //printf("%g\n", CnP[i]);
                //printf("%g\n", CnR[i]);
                //printf("%g\n", CnA[i]);
                //printf("%g\n", CnQ[i]);
                if(i==125)
                {
                    flag=10;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==10)//prende la tabella CONTROL	FORCE DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CXde[i] = strtof(col1,&col2);
                CXdle[i] = strtof(col2,&col3);
                CZde[i] = strtof(col3,&col4);
                CZdle[i] = strtof(col4,&col5);
                CYda[i] = strtof(col5,&col6);
                CYdr[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CXde[i]);
                //printf("%g\n", CXdle[i]);
                //printf("%g\n", CZde[i]);
                //printf("%g\n", CZdle[i]);
                //printf("%g\n", CYda[i]);
                //printf("%g\n", CYdr[i]);
                if(i==125)
                {
                    flag=11;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==11)//prende la tabella CONTROL	MOMENT DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                Clda[i] = strtof(col1,&col2);
                Cldr[i] = strtof(col2,&col3);
                Cmde[i] = strtof(col3,&col4);
                Cmdle[i] = strtof(col4,&col5);
                Cnda[i] = strtof(col5,&col6);
                Cndr[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", Clda[i]);
                //printf("%g\n", Cldr[i]);
                //printf("%g\n", Cmde[i]);
                //printf("%g\n", Cmdle[i]);
                //printf("%g\n", Cnda[i]);
                //printf("%g\n", Cndr[i]);
                if(i==125)
                {
                    flag=12;
                    i=0;
                    continue;
                }
                i++;
            }
            if(flag==12)//prende la tabella ROTARY DERIVATIVES dividendola in vettori colonna
            {
                alpha[i] = strtof(buffer,&col1);
                CXom[i] = strtof(col1,&col2);
                CYom[i] = strtof(col2,&col3);
                CZom[i] = strtof(col3,&col4);
                Clom[i] = strtof(col4,&col5);
                Cmom[i] = strtof(col5,&col6);
                Cnom[i] = strtof(col6,&str);
                //printf("%g\n", alpha[i]);
                //printf("%g\n", CXom[i]);
                //printf("%g\n", CYom[i]);
                //printf("%g\n", CZom[i]);
                //printf("%g\n", Clom[i]);
                //printf("%g\n", Cmom[i]);
                //printf("%g\n", Cnom[i]);
                if(i==125)
                {
                    break;
                }
                i++;
            }
        }
    }
    fclose(fdat);
    return 0;
}