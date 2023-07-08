#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "libreria.h"

//La function "stampa" di tipo void viene utilizzata per stampare la posizione del corridore lungo l'intero percorso.

void stampa(char percorso[LUNGHEZZA], struct bici b) {     //I parametri della function sono il percorso, nonché un array di char inizializzato nel MAIN, e un generico paranetro "b" di tipo struct bici
    int i;
    for(i=0;i<LUNGHEZZA;i++) {     //Questo semplice ciclo for ci consente di stampare la posizione della bici e l'intero array di char
        if(b.pos == i)
            printf("%c ", b.nome);
        else
            printf("%c ", percorso[i]);
        }

    printf("\tGuadagno: %d\n", b.guadagno);

}

//La function conta_salita di tipo int viene richiamata nella function sottostante (muovi_bici) ed è utilizzata per calcolare il guadagno, in negativo, nel caso in cui il corridore percorra una SALITA.
//Viene inizializzato un contatore di tipo int a cui viene assegnato il valore zero. Il contatore, in base alla posizione occupata dal corridore, "calcola" quante delle 6 salite sono rimaste e si incrementa ogni volta di uno.

int conta_salita(char percorso[LUNGHEZZA], int indice, char s) {    //I parametri di questa function sono l'array di char, un indice di tipo intero e un dato di tipo char che rappresenta la SALITA.
    int cont = 0;
    while(percorso[indice++] == s)
        cont++;

    return abs(cont - 7);
}

//La function conta_discesa di tipo int viene richiamata nella function sottostante (muovi_bici) ed è utilizzata per calcolare il guadagno, in positivo, nel caso in cui il corridore percorra una DISCESA.
//Il funzionamento è identico alla function conta_salita, ma in questo caso il contatore parte dal valore numerico 7 e viene decrementato ogni qualvolta incontra una DISCESA. Questo avviene perché il corridore in DISCESA acquista secondi secondo lo schema inverso della SALITA.

int conta_discesa(char percorso[LUNGHEZZA], int indice, char d) {
    int cont = 7;
    while(percorso[indice++] == d)
        cont--;

    return abs(cont - 7);

}

//La function muovi_bici di tipo void viene utilizzata per permettere ai corridori di muoversi lungo il percorso

void muovi_bici(struct bici *b, char percorso[LUNGHEZZA]) {   //I parametri sono rispettivamente un puntatore alla struttura bici e l'array di char

    int indice = 1 + rand() % 3;      //Viene dichiarato un indice di tipo intero al quale viene assegnato un numero pseudocasuale da 1 a 3

    b->pos += indice;                 //Dopo la generazione del numero, quest'ultimo viene assegnato alla posizione della bicicletta (inizialmente uguale a zero)


    //Il seguente ciclo switch permette di separare i vari casi per quanto concerne il calcolo del guadagno acquisito dal corridore
    //Se il corridore si trova su una casella che rappresenta una PIANURA, il suo guadagno è pari all'indice moltiplicato per 10
    //Se il corridore si trova su una casella che rappresenta una SALITA, egli perde guadagno rispetto agli altri corridori
    //Se il corridore si trova su una casella che rappresenta una DISCESA, egli ottiene guadagno rispetto agli altri corridori

    switch(percorso[b->pos]) {
        case PIANURA:
            b->guadagno += (indice * 10);
        break;
        case SALITA:
            b->guadagno -= conta_salita(percorso, b->pos, SALITA);  //Chiamata alla function di tipo int conta_salita. I parametri che vengono richiamati sono l'array di char, la posizione del corridore e la casella rappresentante la SALITA
        break;
        case DISCESA:
            b->guadagno += conta_discesa(percorso, b->pos, DISCESA);  //Chiamata alla function di tipo int conta_discesa nel caso in cui il corridore si trovi in DISCESA
        break;
    }
}



//La function di tipo void pos_iniziale permette ai tre corridori di ripartire dalla posizione iniziale del percorso, una volta terminato il giro

void pos_iniziale(struct bici *b) {   //L'unico parametro della function è un puntatore alla struttura bici

b->pos = 0;

}
