utenti: main.o listaUtenti.o
	gcc -g -o utenti main.c listaUtenti.c -lm

main.o: main.c listaUtenti.h
	gcc -g -c main.c

listaUtenti.o: listaUtenti.c listaUtenti.h
	gcc -g -c listaUtenti.c
	