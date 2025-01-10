#include <stdio.h>
#include <stdlib.h>

#include "listaPazienti.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Errore nell'apertura del programma\n");
        exit(1);
    }

    FILE *pf;
    Record r;
    Lista l;
    pf = fopen("rb", argv[1]);

    if ((pf = fopen(argv[1], "rb")) == NULL)
    {
        printf("Errore apertura %s\n", argv[1]);
        exit(2);
    }

    nuovaLista(&l);

    while (fread(&r, sizeof(Record), 1, pf) == 1)
    {

        aggiorna(&l, r);
        
        
    }
    stampa(l);

    
    eliminaSani(&l);

    stampa(l);

    return 0;
    fclose(pf);
}