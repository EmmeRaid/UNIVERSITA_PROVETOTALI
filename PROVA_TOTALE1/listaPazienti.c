#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPazienti.h"

void nuovaLista(Lista *pl)
{
    pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void aggiorna(Lista *pl, Record r)
{

    while (*pl != NULL && strcmp((*pl)->dato.Cod_fis, r.Cod_fis))
        pl = &(*pl)->next;

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.Cod_fis, r.Cod_fis);
        d.temp = 0.0;
        d.sat = 0.0;
        d.n_rivelazioni = 0;
        insTesta(pl, d);
    }

    (*pl)->dato.temp += r.temp;
    (*pl)->dato.sat += r.sat;
    (*pl)->dato.n_rivelazioni += 1;
}

void stampa(Lista l)
{

    while (l)
    {
        printf("Codice Fiscale: %s\n   Temp: %.2f\n   Sat: %.2f\n", l->dato.Cod_fis, l->dato.temp / l->dato.n_rivelazioni, l->dato.sat / l->dato.n_rivelazioni);
        l = l->next;
    }
}

void elimTesta(Lista *pl){
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

int annoNascita(char *cf){
    return 1900 + 10 + (cf[6] - '0' ) + (cf[7] - '0');
}

void eliminaSani (Lista *pl){
    while(*pl)
        if (annoNascita((*pl)->dato.Cod_fis) >= 1950)
            elimTesta(pl);
        else 
            pl = &(*pl)->next;
            
}