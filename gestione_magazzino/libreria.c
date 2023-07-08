#ifndef LIBRERIA_C_INCLUDED
#define LIBRERIA_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>


#endif // LIBRERIA_C_INCLUDED


//Il Magazzino mette a disposizione, ogni giorno, 3 prodotti. L'utente può scegliere quale dei tre prodotti acquistare tramite la function acquisto di tipo int

int acquisto(char *scelta, char *oggetto1, char *oggetto2, char *oggetto3) { //I parametri di questa function sono quattro puntatori a char
if(strcmp(scelta,oggetto1) == 0 || strcmp(scelta,oggetto2) == 0 || strcmp(scelta,oggetto3) == 0) {   //Se la scelta dell'utente corrisponde ad uno dei tre prodotti disponibili per quel giorno, l'utente acquisterà quel determinato prodotto e la function restituirà il valore 1.
    printf("\nEcco a lei il prodotto: %s\n", scelta);
   return 1;
}
else            //Se la scelta dell'utente non corrisponde ad uno dei tre prodotti disponibili, l'acquisto non potrà essere effettuato e la function restituirà il valore 0.
    printf("Prodotto non disponibile!");
    return 0;
}


//Una volta che l'utente ha deciso se acquistare o meno un determinato prodotto, può decidere di "restare" per effettuare un nuovo acquisto, oppure andar via e passare, di conseguenza, al giorno successivo.
//La function andare_o_restare di tipo int ha un solo parametro "a" di tipo intero che corrisponde alla scelta presa dall'utente. La function restituisce 1 se l'utente decide di restare, oppure zero se decide di andarsene.

int andare_o_restare(int a) {
if (a == 1)
   return 1;
else
    return 0;

}
