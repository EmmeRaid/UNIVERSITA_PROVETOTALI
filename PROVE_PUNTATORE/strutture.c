#include <stdio.h>
#include <string.h>


struct Persona
{
    char nome[10];
    char cognome[10];
    int eta;
};

void presentaPersona(struct Persona persona){

    printf("%d %s %s\n", persona.eta, persona.nome, persona.cognome);

}


int main(){

    struct Persona persona1;
    strcpy(persona1.nome,"luca");
    strcpy(persona1.cognome,"Rossi");
    persona1.eta= 25;

    struct Persona persona2;
    strcpy(persona1.nome,"luca");
    strcpy(persona1.cognome,"Rossi");
    persona1.eta= 25;

    presentaPersona(persona1);

    presentaPersona(persona2);


    return 0;


}