#include <stdio.h>
#include <stdlib.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{

    Lista l;
    Record r;
    Record2 r2;

    char code_fis[17];
    int att;

    if (argc != 3)
    {
        printf("Errore nell'apertura del programmma, utilizzare %s + nome file\n", argv[0]);
        exit(1);
    }

    FILE *pf;

    pf = fopen(argv[1], "rb");

    if (pf == NULL)
    {
        printf("Errore nell'apertura del programmma, utilizzare %s + codicifiscali.dat\n", argv[0]);
        exit(2);
    }

    nuovaLista(&l);

    while (fread(&r, sizeof(Record), 1, pf) == 1)
    {
        aggiornaLista(&l, r);
    }

    puts("PRIMA STAMPA LISTA NON AGGIORNATA:");

    stampa(l);

    fclose(pf);

    pf = fopen(argv[2], "rt");

    puts("PRIMA STAMPA LISTA2 NON AGGIORNATA:");


    while (fscanf(pf, "%s %d", r2.cod_fis, &r2.att) != EOF)
    {
        aggiornaLista2(&l, r2);
    }

    stampa(l);

    fclose(pf);

    return (0);
}