typedef struct
{
    char Cod_fis[17];
    int H;
    float temp;
    float sat;
} Record;

typedef struct
{
    char Cod_fis[17];
    float temp;
    float sat;
    int n_rivelazioni;
} Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Dato  d);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);
void elimTesta(Lista *pl);
void eliminaSani (Lista *pl);