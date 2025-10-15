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
    if (*endptr != '\0' || res < 1 || res > 10) {
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
    if (endptr != 0 || res < -1 || res > 1) {
        res = -2;
    }
    free(num);
    num = NULL;
    return (short int)res;
}

int main(void) {
    int cmd = -1;
    int nGiorni = 0;
    int streakAssenze = 0;
    int* presenze = NULL;
    int* voti = NULL;
    int* rePresenze = NULL;
    int* reVoti = NULL;
    do {
        short int v = inserisciVoto();
        printf("res: %d\n", v);
        // chiedi la presenza (-1 = F, 0 = A, 1 = P)
        // se F => esci dal while
        // altrimenti: aumenta nGiorni e realloca rePresenze
        // se A => aumenta la streakAssenze
        // se P => annulla la streakAssenze + chiede voti + realloca reVoti
    }
    while (rePresenze != NULL && reVoti != NULL && cmd >= 0);
    // stampa tutti i voti, fa i calcoli necessari
    return 0;
}