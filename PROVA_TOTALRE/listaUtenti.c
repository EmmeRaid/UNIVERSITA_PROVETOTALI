#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "listaUtenti.h"

void nuovaLista (Lista *pl){

    *pl = NULL;
}

void insTesta(Lista *pl, Dato d){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void stampa(Lista l){

    printf("\nLISTA:\n");

    while(l){
        printf("%s %c %.2f\n", l->dato.tel, l->dato.piano, l->dato.credito);
        l = l->next;
    }

}