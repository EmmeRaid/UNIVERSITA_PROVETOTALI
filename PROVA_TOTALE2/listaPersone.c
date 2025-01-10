#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPersone.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
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

    while (*pl != NULL && strcmp((*pl)->dato.codFis, r.codFis) < 0)
    {
        pl = &(*pl)->next;
    }

    if (*pl == NULL || strcmp((*pl)->dato.codFis, r.codFis) != 0)
    {

        Dato d;
        strcpy(d.codFis, r.codFis);
        d.tampone = 0;
        d.vaccino = 0;
        insTesta(pl, d);
    }

    if (r.tipo == 'T')
    {
        (*pl)->dato.tampone = 1;
    }
    else if (r.tipo == 'V')
    {
        (*pl)->dato.vaccino = 1;
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s T: %d V: %d\n", l->dato.codFis, l->dato.tampone, l->dato.vaccino);
        l = l->next;
    }
}
