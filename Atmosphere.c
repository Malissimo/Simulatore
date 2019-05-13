#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atmosphere.h"

// il codice mostra i dati atmosferici di default a video e permette di modificarli.

int Atmosphere (double press,double temp,double rho,double vsuono)
{
    int input;
    char str;
    float press1,temp1,rho1,vsuono1,h;

    printf("\nATMOSFERA ISA\n\n");
    printf("La simulazione fa riferimento al modello atmosferico ISA, avente i segeunti valori per quota h=0m (sea level):\n\n");
    printf("\tPressione: \t\tP = %g Pa\n",press);
    printf("\tTemperatura: \t\tT = %g C\n",temp);
    printf("\tDensita': \t\trho = %g kg/m^3\n",rho);
    printf("\tVelocita' del Suono: \ta = %g m/s\n",vsuono);

    printf("\nSe non si desidera procedere con i suddetti parametri e' possibile modicarli, reinserendoli manualmente o scegliendo una quota differente.\n");
    printf("\nPremere:\n");
    printf("\t[1] se si desidera procedere con i valori precedentemente indicati\n");
    printf("\t[2] se si desidera modificare i valori manualmente\n");
    printf("\t[3] se di desidera scegliere una diversa quota\n");

    scanf("%d",&input);

    switch(input)
    {
        case 1:
            break;
        case 2:
            printf("\nInserire un valore di pressione in Pa:");
            scanf("%g",&press1);
            press=press1;
            printf("\nInserire un valore di temperatura in C:");
            scanf("%g",&temp1);
            temp=temp1;
            printf("\nInserire un valore di densita' in kg/m^3:");
            scanf("%g",&rho1);
            rho=rho1;
            printf("\nInserire un valore di velocita' del suono in m/s:");
            scanf("%g",&vsuono1);
            vsuono=vsuono1;
            break;
        case 3:
            printf("\nInserire una nuova quota:");
            scanf("%g %s",&h, &str);
        default:
            printf("Errore, immettere un numero da 1 a 3");
            break;
    }

    return 0;
}