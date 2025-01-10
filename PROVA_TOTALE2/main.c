#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPersone.h"

int main(int argc, char *argv[])
{

    FILE *pf;
    Record r;
    Lista l;


    //CREAZIONE DELLA LISTA
    nuovaLista(&l);

    pf = fopen(argv[1], "rb");


    //CONTROLLI APERTURA FILES
    if (argc != 2)
    {
        printf("Errore nell'apertura del file.. Metodo corretto %s...\n", argv[0]);
        exit(1);
    }

    if (pf == NULL)
    {
        printf("Errore nell'apertura del file.. Metodo corretto %s <eventi.dat>\n", argv[0]);
        exit(2);
    }

    while (fread(&r, sizeof(Record), 1, pf) == 1)
    {

        printf("Data: %d/%d/%d\nCod: %s\nTip: %c\n\n",r.day,r.mes, r.year, r.codFis, r.tipo);
        aggiorna(&l, r);
    }

    stampa(l);

    fclose(pf);

    return 0;
    
}