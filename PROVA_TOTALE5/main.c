#include <stdio.h>
#include <stdlib.h>
#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    FILE *pf;
    Lista l;
    Record r;

    pf = fopen(argv[1], "rb");

    if (pf == NULL)
    {
        printf("Errore nell'apertura del file");
    }

    while (fread(&r, sizeof(Record), 1, pf) == 1)
    {
        aggiornaLista(&l, r);
    }

    stampa(l);

    eliminasani(&l);

    puts("lista aggiornata");

    stampa(l);

    fclose(pf);

    return 0;
}