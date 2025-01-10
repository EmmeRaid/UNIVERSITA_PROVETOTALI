typedef struct
{
    char tel[11];
    char piano;
    float credito;
} Record;

typedef struct
{
    char tel[11];
    char piano;
    float credito;
} Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo* Lista;
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Dato d);
void stampa(Lista l);