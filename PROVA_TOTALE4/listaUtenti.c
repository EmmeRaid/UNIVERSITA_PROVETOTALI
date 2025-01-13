#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{

    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    aux->dati = d;
    aux->next = *pl;
    *pl = aux;
}

void stampa(Lista l)
{
    while (l != NULL)
    {
        printf("Codice Fiscale: %s %d %d %d\n", l->dati.cod_fis, l->dati.att1, l->dati.att2, l->dati.att3);
        l = l->next;
    }
}

void aggiornaLista(Lista *pl, Record r)
{
    Dato d;

    while (*pl != NULL && strcmp((*pl)->dati.cod_fis, r.cod_fis) != 0)
    {
        pl = &(*pl)->next;
    }

    if (*pl == NULL)
    {
        strcpy(d.cod_fis, r.cod_fis);
        d.att1 = 4;
        d.att2 = 4;
        d.att3 = 4;
        insTesta(pl, d);
    }
}

void aggiornaLista2(Lista *pl, Record2 r2)
{
    while (*pl != NULL)
    {
        if (strcmp((*pl)->dati.cod_fis, r2.cod_fis) == 0)
        {
            if (r2.att == 1)
            {
                (*pl)->dati.att1--;
            }
            else if (r2.att == 2)
            {
                (*pl)->dati.att2--;
            }
            else if (r2.att == 3)
            {
                (*pl)->dati.att3--;
            }
        }pl = &(*pl)->next;
    }
}