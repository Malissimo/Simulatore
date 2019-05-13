#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Atmosphere.h"

// il codice mostra i dati atmosferici di default a video e permette di modificarli.

int AtmosphereChoice (double *press0,double *temp0,double *rho0,double *vsuono0,
                      double *press_h,double *temp_h,double *rho_h,double *vsuono_h, int *flagatm)
{
    int input;

    printf("\nATMOSFERA ISA\n\n");
    printf("La simulazione fa riferimento al modello atmosferico ISA, avente i segeunti valori per quota h=0m (sea level):\n\n");
    printf("\tPressione: \t\tP = %g Pa\n",*press0);
    printf("\tTemperatura: \t\tT = %g C\n",*temp0);
    printf("\tDensita': \t\trho = %g kg/m^3\n",*rho0);
    printf("\tVelocita' del Suono: \ta = %g m/s\n",*vsuono0);

    printf("\nSe non si desidera procedere con i suddetti parametri e' possibile modicarli, reinserendoli manualmente o scegliendo una quota differente.\n");
    do {
        printf("\nPremere:\n");
        printf("\t[1] se si desidera procedere con i valori iniziali precedentemente indicati\n"); // mantiene i valori iniziali di default
        printf("\t[2] se si desidera modificare i valori iniziali a h=0\n"); //modifica i valori iniziali di default
        printf("\t[3] se di desidera immettere i valori manualmente a una quota specifica\n");// immette i valori manualmente a una data quota senza richiederla poi

        scanf("%d", &input);
        if(input!=1 && input!=2 && input!=3)
        {
            scanf("%*[^\n]"); //svuota il buffer di scanf se immetto un carattere invece che un numero
            printf("[!]WARNING immettere un numero da 1 a 3\n");
        }
        switch(input)
        {
            case 1: // mantiene i valori iniziali di default
                *flagatm = 1;
                break;
            case 2: //modifica i valori iniziali di default
                printf("Inserire un valore di pressione (h=0) in Pa:");
                scanf("%lf", press0);
                printf("Inserire un valore di temperatura (h=0) in C:");
                scanf("%lf", temp0);
                printf("Inserire un valore di densita' in kg/m^3:");
                scanf("%lf", rho0);
                printf("Inserire un valore di velocita' (h=0) del suono in m/s:");
                scanf("%lf", vsuono0);
                *flagatm = 1;
                break;
            case 3: // immette i valori manualmente a una data quota senza richiederla poi
                printf("Inserire un valore di pressione in Pa:");
                scanf("%lf", press_h);
                printf("Inserire un valore di temperatura in C:");
                scanf("%lf", temp_h);
                printf("Inserire un valore di densita' in kg/m^3:");
                scanf("%lf", rho_h);
                printf("Inserire un valore di velocita' (h=0) del suono in m/s:");
                scanf("%lf", vsuono_h);
                *flagatm = 2;
                break;
        }
    }
    while(input!=1 && input!=2 && input!=3);

    return 0;
}

int AtmosphereCalc (double *CI, double *datiengine, double Pmax_h,double *press0,double *temp0,double *rho0,double *vsuono0,
                    double *press_h,double *temp_h,double *rho_h,double *vsuono_h, int *flagatm)
{
    double R=287.05;
    switch(*flagatm)
    {
        case 1: // calcola le condizioni atmosferiche e di pot per i valori a SL di default o inseriti dall'utente
            *temp0= *temp0 + 273.15;
            *temp_h=*temp0 - 0.0065*CI[1];
            *press_h=*press0*(pow((*temp_h/(*temp0)),5.2561));
            *rho_h=*press_h/(R*(*temp_h));
            Pmax_h= datiengine[0]* pow(*rho_h/(*rho0),datiengine[1]);

            printf("\nI dati atmosferici e di potenza per la quota di %f sono:\n\n",CI[1]);
            printf("Temperatura: \t\t%f [K]\n",*temp_h);
            printf("Pressione: \t\t%f [Pa]\n",*press_h);
            printf("Desita': \t\t%f [kg/m^3]\n",*rho_h);
            printf("Potenza: \t\t%f [kW]\n",Pmax_h);
            break;
        case 2:// usa i valori scelti dall'utente
            *temp_h=*temp_h+273.15;
            Pmax_h= datiengine[0]* pow(*rho_h/(*rho0),datiengine[1]);

            printf("\nI dati atmosferici scelti e la potenza ad essi associata, sono:\n\n");
            printf("Temperatura: \t\t%f [K]\n",*temp_h);
            printf("Pressione: \t\t%f [Pa]\n",*press_h);
            printf("Desita': \t\t%f [kg/m^3]\n",*rho_h);
            printf("Potenza: \t\t%f [kW]\n",Pmax_h);
            break;
    }
    return 0;
}