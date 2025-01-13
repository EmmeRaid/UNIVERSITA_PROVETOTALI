typedef struct
{
    char cod_fis[17];
} Record;

typedef struct
{
    char cod_fis[17];
    int att;
} Record2;

typedef struct
{
    char cod_fis[17];
    int att1;
    int att2;
    int att3;

} Dato;

typedef struct nodo
{
    Dato dati;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;

void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Dato d);
void aggiornaLista(Lista *pl, Record r);
void stampa(Lista l);
void aggiornaLista2(Lista *pl, Record2 r2);
