#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CI_utente.h"
// carico le condizioni iniziali
int loadCI(double *CI,int *flagatm)
{
    int input;

    if(*flagatm==1)
    {
        printf("\nCondizioni iniziali di default:\n");
        printf("V =\t\t%g m/s\nh =\t\t%g m\ngamma =\t\t%g deg\n",CI[0],CI[1],CI[2]);
        do
            {
            printf("\nMantenere le condizioni di volo?\n");
            printf("0->SI\n1->NO\n");
            scanf("%d",
                  &input); //la funzione scanf restituisce un numero intero pari al numero di conversioni eseguite con successo.
            if (input != 0 && input != 1) {
                scanf("%*[^\n]"); //svuoto buffer di scanf
                printf("[!]WARNING: Scelta non valida\n");
            }
            switch (input)
            {
                case 0:
                    break;
                case 1:
                    printf("Inserire velocita' di volo (30 m/s<=V<=75 m/s):\n");
                    scanf("%lf", &CI[0]);
                    if (CI[0] < 30 || CI[0] > 75)
                    {
                        do{
                            printf("[!]WARNING: Scelta non valida\n");
                            printf("Re-inserire velocita' di volo (30 m/s<=V<=75 m/s):\n");
                            scanf("%lf", &CI[0]);
                        } while (CI[0] < 30 || CI[0] > 75);
                    }
                    printf("Inserire quota di volo (0 m<=h<=4116 m):\n");
                    scanf("%lf", &CI[1]);
                    if (CI[1] < 0 || CI[1] > 4116)
                    {
                        do {
                            printf("[!]WARNING: Scelta non valida\n");
                            printf("Re-inserire quota di volo (0 m<=h<=4116 m):\n");
                            scanf("%lf", &CI[1]);
                        } while (CI[1] < 0 || CI[1] > 4116);
                    }
                    printf("Inserire angolo di rampa (gamma=0 volo livellato, gamma!=0 volo in salita/discesa):\n");
                    scanf("%lf", &CI[2]);
                    break;
            }
        } while (input != 0 && input != 1);
    }
    if(*flagatm==2) {
        printf("\nCondizioni iniziali di default:\n");
        printf("V =\t\t%g m/s\nh=\t\tutente\ngamma =\t\t%g deg\n",CI[0],CI[2]);
        do {
            printf("\nMantenere le condizioni di volo?\n");
            printf("0->SI\n1->NO\n");
            scanf("%d",
                  &input); //la funzione scanf restituisce un numero intero pari al numero di conversioni eseguite con successo.
            if (input != 0 && input != 1) {
                scanf("%*[^\n]"); //svuoto buffer di scanf
                printf("[!]WARNING: Scelta non valida\n");
            }
            switch (input) {
                case 0:
                    break;
                case 1:
                    printf("Inserire velocita' di volo (30 m/s<=V<=75 m/s):\n");
                    scanf("%lf", &CI[0]);
                    if (CI[0] < 30 || CI[0] > 75) {
                        do {
                            printf("[!]WARNING: Scelta non valida\n");
                            printf("Re-inserire velocita' di volo (30 m/s<=V<=75 m/s):\n");
                            scanf("%lf", &CI[0]);
                        } while (CI[0] < 30 || CI[0] > 75);
                    }
                    printf("Inserire angolo di rampa (gamma=0 volo livellato, gamma!=0 volo in salita/discesa):\n");
                    scanf("%lf", &CI[2]);
                    printf("Dati relativi alla quota inseriti manualmente in precedenza\n");
                    break;
            }
        } while (input != 0 && input != 1);
    }
    return 0;
}
