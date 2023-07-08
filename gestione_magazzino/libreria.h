#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#endif // LIBRERIA_H_INCLUDED

//La struct "data" viene utilizzata per gestire il magazzino partendo da una data prestabilita.

struct data {
int giorno;
int giornoX;
char *mese;
int anno;
};
typedef struct data Data;

//La struct "magazzino" viene utilizzata per attribuire ad ognuno dei 20 prodotti del Magazzino le seguenti caratteristiche

struct magazzino {
int codice;
char *nome;
char *specifica;
int quantita;
int costo;
};
typedef struct magazzino Elettronica;

//Prototipi delle function utilizzate

int acquisto(char *, char *, char *, char *);
int andare_o_restare(int);


