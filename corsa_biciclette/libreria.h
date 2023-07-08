#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>



#endif // LIBRERIA_H_INCLUDED


//Di seguito sono riportate quattro "#define"

#define   LUNGHEZZA  61   //La prima define stabilisce la LUNGHEZZA del percorso lungo il quale corrono le tre biciclette.
#define   PIANURA    '-'  //La seconda define attribuisce alle caselle lungo le quali il percorso è in PIANURA, il simbolo raffigurato.
#define   SALITA     '/'  //La terza define attribuisce alle caselle lungo le quali il percorso è in SALITA, il simbolo raffigurato.
#define   DISCESA    '\\' //La quarta define attribuisce alle caselle lungo le quali il percorso è in DISCESA, il simbolo raffigurato.


//La struct bici contiene le informazioni relative ad ogni corridore. Ogni corridore è identificato da un carattere, una posizione e un guadagno (in secondi).

struct bici {
    char nome;
    int pos;
    int guadagno;
};


//Prototipi delle function utilizzate

void stampa(char [], struct bici);
int conta_salita(char [], int, char);
int conta_discesa(char [], int, char);
void muovi_bici(struct bici*, char []);
void pos_iniziale(struct bici *);
