typedef struct
{
    char codFis[17];
    int ora;
    float temp;
    float sat;
} Record;

typedef struct
{
    char codFis[17];
    int rivelazioni;
    float somm_temp;
    float somm_sat;
    int anomalia;
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
Lista* ricerca( Lista *pl);
void eliminasani(Lista *pl);
void elimTesta(Lista *pl);
int calcoloAnno(char *cf);