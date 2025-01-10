pazienti: main.o listaPazienti.o
	gcc -g -o pazienti listaPazienti.c main.c

main.o: main.c listaPazienti.h
	gcc -g -c main.c

listaPazienti.o: listaPazienti.c listaPazienti.h
	gcc -g -c listaPazienti.c
	