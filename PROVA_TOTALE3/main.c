#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "listaUtenti.h"

typedef struct
{
    char telefono[17];
    int durata;
} Record2;

float Calcolocredito(Lista *pl, Record2 r2)
{

    double Creditospeso = 0.00;
    int numeroScatti = 0;

    while (*pl != NULL)
    {
        if (strcmp((*pl)->dato.tel, r2.telefono) == 0)
        {
            if ((*pl)->dato.piano == 'A')
            {
                numeroScatti = (r2.durata / 60) + 1;
                Creditospeso = 0.15 + (0.08 * numeroScatti);
                (*pl)->dato.credito = (*pl)->dato.credito - Creditospeso;
            }
            else if ((*pl)->dato.piano == 'B')
            {
                double costo_secondo = (0.12 / 60);
                double costo_totale = costo_secondo * r2.durata;
                Creditospeso = floor(costo_totale * 100) / 100;
                (*pl)->dato.credito = (*pl)->dato.credito - Creditospeso;
            }
        }pl = &(*pl)->next;
    }
}

int main(int argc, char *argv[])
{

    FILE *pf;
    Record r;
    Record2 r2;
    Lista l;
    Dato d;

    nuovaLista(&l);

    if (argc < 3)
    {
        printf("Errore nell'apertura del programma, inserire %s nome file nome file2\n", argv[0]);
        exit(1);
    }

    pf = fopen(argv[1], "rb");
    if (pf == NULL)
    {
        printf("Errore nell'apertura del programma, inserire %s nome file valido ad esempio utenti.dat chiamate.txt\n", argv[0]);
        exit(2);
    }

    while (fread(&d, sizeof(Dato), 1, pf) == 1)
    {
        insTesta(&l, d);
    }

    fclose(pf);

    stampa(l);

    pf = fopen(argv[2], "rt");

    if (pf == NULL)
    {
        printf("Errore nell'apertura del programma, inserire %s nome file valido ad esempio utenti.dat chiamate.txt\n", argv[0]);
        exit(2);
    }

    printf("\nLista con Credito residuo aggiornato\n\n");

    while (fscanf(pf, "%s %d", r2.telefono, &r2.durata) != EOF)
    {
        Calcolocredito(&l, r2);
    }

    stampa(l);

    return 0;
}