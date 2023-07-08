

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <string.h>

//Programma sulla Gestione di un magazzino di prodotti elettronici
//Il seguente programma permette all'utente di acquistare, ogni giorno, un massimo di due prodotti tra quelli disponibili

void main()
{

printf("Benvenuto al nostro magazzino!\n");


Data corrente; //Viene inizializzata una variabile "corrente" di tipo Data.
corrente.giorno = 2;
corrente.mese = "Gennaio";
corrente.anno = 2021;


//Viene inizializzato un array di tipo Elettronica, contenente i 20 prodotti con le relative caratteristiche dichiarate nella struct magazzino.
Elettronica prodotto[20] = {{100,"PS5","10.28 TFLOPS",4,500},{101,"PS4","4.20 TFLOPS",4,250},{102,"PS3","2 TFLOPS",4,150},{103,"PS2","6.2 GFLOPS",4,100},{104,"PS1mini","Oltre 20 giochi inclusi",4,100},{105,"XBOXSeriesX", "12 TFLOPS",4,500},{106,"XBOXSeriesS", "4 TFLOPS",4,400},{107,"XBOXOneX", "6 TFLOPS",4,300},{108,"XBOXOneS", "1,4 TFLOPS",4,250},{109,"XBOX360", "1 TFLOPS",4,150},{110,"iPhone12", "RAM 4 GB",4,1200},{111,"iPhone11", "RAM 4 GB",4,900},{112, "iPhoneX", "RAM 3 GB",4,600},{113,"SamsungS20","RAM 8 GB",4,900},{114,"SamsungS10", "RAM 8 GB",4,500},{115,"SamsungS8", "RAM 4 GB",4,250},{116,"SamsungA71", "RAM 8 GB",4,400},{117,"SamsungA51", "RAM 4 GB",4,350},{118,"HuaweiP40", "RAM 8 GB",4,400},{119,"HuaweiP30", "RAM 4 GB",4,350}};

Elettronica *p;   //Viene dichiarato un puntatore *p di tipo Elettronica
p = &prodotto[0]; //Il puntatore punta all'indirizzo base dell'array prodotto
int i, j;
for(i=0;i<20;i++)
    //Stampa dei 20 prodotti con le relative caratteristiche
    printf("\nProdotto n. %d dal codice n. %d, nome %s, specifica %s, quantita' %d e costo %d\n", i, (p+i)->codice,(p+i)->nome, (p+i)->specifica,(p+i)->quantita,(p+i)->costo);

int venduti = 0; //Variabile di tipo intero per tener conto degli acquisti effettuati dall'utente durante un certo lasso di tempo

for(j=0;j<11;j++) {
        //La variabile j viene utilizzata all'interno di un ciclo for per incrementare la data corrente di un giorno, ogni qualvolta l'utente decida di andar via
printf("\n%d %s %d\n", corrente.giorno+j, corrente.mese, corrente.anno);
printf("\nProdotti disponibili: %s %s %s\n", (p+j)->nome, (p+j+1)->nome, (p+j+2)->nome);

char *scelta;
printf("\nQuale prodotto desidera acquistare?\n");
scanf(" %s", &scelta);


if(acquisto(&scelta,(p+j)->nome,(p+j+1)->nome,(p+j+2)->nome) == 1) //Chiamata alla prima function
venduti++; //Se la function acquisto ritorna 1, l'utente ha effettuato il suo primo acquisto e la variabile "venduti" di tipo int viene incrementata di 1

printf("\nPremi 1 per continuare ad acquistare o 0 per uscire\n");
int a;
scanf(" %d", &a); //Viene chiesto all'utente di compiere una seconda scelta. Se la scelta è 1 l'utente può effettuare un nuovo acquisto

if(andare_o_restare(a) == 1) {  //Chiamata alla seconda function.
    printf("\nQuale prodotto desidera acquistare?\n");
    scanf(" %s", &scelta);
    if(acquisto(&scelta,(p+j)->nome,(p+j+1)->nome,(p+j+2)->nome) == 1) //Se l'utente decide di acquistare un nuovo prodotto, la function acquisto viene richiamata. Il suo funzionamento rimane inalterato
    venduti++;
}
else printf("\nVa bene,arrivederci\n");

}


//Viene chiesto all'utente di inserire due date.
printf("\nInserire due date per visualizzare il numero di prodotti venduti nel mese di Gennaio:\n");
scanf(" %2d %2d", &corrente.giorno, &corrente.giornoX);

//Scelte le due date, viene stampato il numero di prodotti venduti fino alla seconda data scelta dall'utente
printf("\nIl numero di prodotti venduti dal %d al %d %s e' %d",corrente.giorno,corrente.giornoX,corrente.mese,venduti);

}


