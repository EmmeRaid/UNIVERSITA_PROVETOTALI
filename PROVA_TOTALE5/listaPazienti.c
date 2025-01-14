#include <stdio.h>
#include <stdlib.h>
#include "listaPazienti.h"
#include <string.h>

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

void aggiornaLista(Lista *pl, Record r)
{

    while (*pl != NULL && strcmp((*pl)->dati.codFis, r.codFis) != 0)
    {
        pl = &(*pl)->next;
    }

    if (*pl == NULL)
    {
        Dato d;
        strcpy(d.codFis, r.codFis);
        d.somm_temp = 0;
        d.somm_sat = 0;
        d.rivelazioni = 0;
        d.anomalia = 0;
        insTesta(pl, d);
    }
    (*pl)->dati.rivelazioni++;
    (*pl)->dati.somm_temp += r.temp;
    (*pl)->dati.somm_sat += r.sat;

    if (r.sat < 96 || r.temp > 37.5)
    {
        (*pl)->dati.anomalia = 1;
    }
}

void stampa(Lista l)
{

    int conto = 0;

    while (l != NULL)
    {

        printf("(%d): %s\nTemp med:%.2f Sat med:%.2f %d\n", conto, l->dati.codFis, l->dati.somm_temp / l->dati.rivelazioni, l->dati.somm_sat / l->dati.rivelazioni, l->dati.rivelazioni);
        conto++;
        l = l->next;
    }
}

Lista *ricerca(Lista *pl)
{

    while (*pl)
    {
        if ((*pl)->dati.anomalia == 1)
        {
            break;
        }
        pl = &(*pl)->next;
    }

    return pl;
}

void eliminasani(Lista *pl)
{
    while (*pl)
    {
        if ((*pl)->dati.anomalia == 1 && calcoloAnno((*pl)->dati.codFis) >= 1950)
        {
            elimTesta(pl);
        }
        else
        {
            pl = &(*pl)->next;
        }
    }
}

void elimTesta(Lista *pl)
{
    Nodo *aux = *pl;
    *pl = (*pl)->next;
    free(aux);
}

int calcoloAnno(char *cf)
{
    return 1900 + 10 * (cf[6] - '0') + (cf[7] - '0');
}