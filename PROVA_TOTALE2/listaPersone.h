typedef struct
{
    int day;
    int mes;
    int year;
    char codFis[17];
    char tipo;
} Record;

typedef struct
{

    char codFis[17];
    int vaccino;
    int tampone;
} Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
//FUNZIONI PER LE LISTE
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Dato d);
void aggiorna(Lista *pl, Record r);
void stampa(Lista l);