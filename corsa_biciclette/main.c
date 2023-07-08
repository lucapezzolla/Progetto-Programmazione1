#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "libreria.h"
#include <math.h>

/*Progetto Corsa Biciclette.
 Il seguente programma simula una gara ciclistica a cui prendono parte tre corridori. Le informazioni attribuite ai tre corridori sono riportate all'interno della struct "bici".
 Ogni bicicletta, a turno, può muoversi da una a tre caselle, fino all'arrivo del traguardo. Il guadagno, espresso in secondi, attribuito ai tre corridori è inizialmente pari a zero.*/


void main()
{
    srand(time(NULL));  //viene chiamata la function srand (dalla libreria time.h) per evitare che ad ogni estrazione si ottenga lo stesso numero pseudocasuale

    printf("Benvenuto alla gara ciclistica, di seguito vi presentiamo i tre corridori che prenderanno parte alla gara!\n");

    //Percorso di char
    char percorso[LUNGHEZZA] = {'-','-','-','-','-','/','/','/','/','/','/','\\','\\','\\','\\','\\','\\','-','-','/','/','/','/','/','/','\\','\\','\\','\\','\\','\\','-','-','/','/','/','/','/','/','\\','\\','\\','\\','\\','\\','-','-','/','/','/','/','/','/','\\','\\','\\','\\','\\','\\','-','-'};

    //Inizializzazione delle strutture con nome, posizione iniziale e il guadagno in secondi
    struct bici bici_a = {'A',0,0};
    struct bici bici_b = {'B',0,0};
    struct bici bici_c = {'C',0,0};

    //Viene stampata la posizione dei tre corridori
    printf("Nome: %c\n", bici_a.nome);
    stampa(percorso, bici_a);

    printf("Nome: %c\n", bici_b.nome);
    stampa(percorso, bici_b);

    printf("Nome: %c\n", bici_c.nome);
    stampa(percorso, bici_c);

    printf("\nPremi il tasto invio per continuare e.. Buon divertimento!\n");
    getchar();

    printf("\n");

    int i;

    for(i = 1; i <= 20; i++) {  //Il seguente ciclo for viene ripetuto per ben 20 volte, in modo da simulare la gara ciclistica su 20 giri
    while(bici_a.pos < LUNGHEZZA || bici_b.pos < LUNGHEZZA || bici_c.pos < LUNGHEZZA) {  //Le tre bici continuano a muoversi fino a quando la loro posizione è minore o uguale alla LUNGHEZZA dell'intero percorso

    if(bici_a.pos < LUNGHEZZA) {
    muovi_bici(&bici_a, percorso); //Chiamata alla function muovi_bici per i tre corridori. Viene passato l'indirizzo della struttura
    stampa(percorso, bici_a);
    }


    if(bici_b.pos < LUNGHEZZA) {
    muovi_bici(&bici_b, percorso);
    stampa(percorso, bici_b);
    }

    if(bici_c.pos < LUNGHEZZA) {
    muovi_bici(&bici_c, percorso);
    stampa(percorso, bici_c);
    }

    }

    //L'uscita dal ciclo while avviene quando i tre corridori hanno terminato il loro giro, cioé quando la loro posizione è maggiore o uguale alla LUNGHEZZA del percorso
    pos_iniziale(&bici_a);
    pos_iniziale(&bici_b);
    pos_iniziale(&bici_c);
    printf("\nGiro n. %d terminato\n\n", i);

    }

    printf("\nGara terminata!");

}
