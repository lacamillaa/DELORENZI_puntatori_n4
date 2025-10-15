#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

short int inserisciVoto() {
    char* v = (char*)malloc(sizeof(char) * 3);
    char* endptr;
    int i = 0;
    while (i < 3) {
        char c = (char)getchar();
        *(v + i) = c;
        if (c == 10) {
            break;
        }
        i++;
    }
    *(v + i) = 0;
    long res = strtol(v, &endptr, 10);
    if (*endptr != '\0') {
        res = -2;
    }
    if ((res < 1 || res > 10) && res != 0) {
        res = -2;
    }
    free(v);
    v = NULL;
    return (short int)res;
}

short int inserisciPresenza() {
    char* num = (char*)malloc(sizeof(char) * 3);
    char* endptr;
    int i = 0;
    while (i < 3) {
        char c = (char)getchar();
        *(num + i) = c;
        if (c == 10) {
            break;
        }
        i++;
    }
    *(num + i) = 0;
    long res = strtol(num, &endptr, 10);
    if (*endptr != 0 || res < -1 || res > 1) {
        res = -2;
    }
    free(num);
    num = NULL;
    return (short int)res;
}

int main(void) {
    short int cmd = -1;
    int nGiorni = 0;
    int nVoti = 0;
    int streakAssenze = 0;
    short int* presenze = NULL;
    short int* voti = NULL;
    short int* rePresenze = (short int*)malloc(sizeof(short int));
    short int* reVoti = (short int*)malloc(sizeof(short int));
    do {
        printf("Giorno %d\n",nGiorni + 1);
        do {
            printf("Lo studente era presente oggi? (-1 = F / 0 = A / 1 = P) ");
            cmd = inserisciPresenza();
        } while (cmd == -2);
        rePresenze = (short int*)realloc(rePresenze, nGiorni + 1);
        if (rePresenze != NULL) {
            rePresenze[nGiorni] = cmd;
            presenze = rePresenze;
            nGiorni++;
            if (cmd != -1) {
                streakAssenze = !cmd * (streakAssenze + 1);
                if (streakAssenze >= 5) {
                    printf("Attenzione: necessario certificato medico.\n");
                    printf("Totale assenze consecutive: %d\n", streakAssenze);
                }
                if (cmd == 1) {
                    int nAggiunte = 0;
                    short int v = -2;
                    do {
                        while (v == -2) {
                            printf("Inserisci voto: (0 per terminare) ");
                            v = inserisciVoto();
                        }
                        reVoti = (short int*)realloc(reVoti, nVoti + 1);
                        if (reVoti != NULL) {
                            voti = reVoti;
                            reVoti[nVoti] = v;
                            nVoti++;
                        }
                        else {
                            printf("Memoria esaurita\n");
                            free(reVoti);
                            reVoti = NULL;
                            v = 0;
                        }
                    } while (v != 0);
                }
            }
        }
    }
    while (rePresenze != NULL && reVoti != NULL && cmd >= 0);
    // stampa tutti i voti, fa i calcoli necessari
    free(rePresenze);
    rePresenze = NULL;
    return 0;
}