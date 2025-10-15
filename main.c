#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    int cmd = 0;
    int nGiorni = 0;
    int streakAssenze = 0;
    int* presenze = NULL;
    float* voti = NULL;
    int* rePresenze = NULL;
    int* reVoti = NULL;
    do {
        // chiedi la presenza (-1 = F, 0 = A, 1 = P)
        // se F => esci dal while
        // altrimenti: aumenta nGiorni e realloca rePresenze
        // se A => aumenta la streakAssenze
        // se P => annulla la streakAssenze + chiede voti + realloca reVoti
    }
    while (rePresenze != NULL && reVoti != NULL && cmd >= 0);
    // stampa tutti i voti, fa i calcoli necessari
    printf("Hello, World!\n");
    return 0;
}