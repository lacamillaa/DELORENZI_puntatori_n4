# Esercizio #4 puntatori

**Realizzato da:** De Lorenzi Camilla

**Classe:** 4AII

**Consegna:** Sei lo sviluppatore dell'Itis Rossi e ti è stato richiesto di implementare
un'applicazione per gestire alcuni parametri degli studenti.
Ti è stato richiesto un programma prototipo in cui viene gestito uno studente
ed in particolare
● lista di voti dello studente.
● lista delle presenze (P) e assenze (A)
Inizialmente, il numero di voti e di giorni è sconosciuto, quindi decidi di
utilizzare un vettore dinamico per memorizzare i voti e le assenze. Tuttavia,
ogni volta che ricevi nuovi voti, potresti dover ridimensionare il vettore per
accogliere ulteriori dati.
Il main dovrà continuare a chiedere se lo studente è presente in aula, se è
presente chiedere se ci sono voti da inserire ed eventualmente inserirli nel
vettore. Ogni 5 assenze consecutive scrivere in console un alert.
A fine programma (numero negativo alla domanda sulla presenza) stampare
tutti i voti e farne la media (funzione media con i puntatori!)
Lo studente risulta promosso solo se la media è sopra il 6 e se ha fatto meno
del 20% di assenze