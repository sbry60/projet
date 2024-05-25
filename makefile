

all: exec clean

main.o : main.c tri.h
	gcc -c main.c -o main.o

jeu.o : jeu.c tri.h
	gcc -c jeu.c -o jeu.o

fonc_bas.o : fonc_bas.c tri.h
	gcc -c fonc_bas.c -o fonc_bas.o

fonction.o : fonction.c tri.h
	gcc -c fonction.c -o fonction.o

affichage.o : affichage.c tri.h
	gcc -c affichage.c -o affichage.o

exec : main.o jeu.o fonc_bas.o fonction.o affichage.o
	gcc *.o -o exec


clean:
	rm -f *.o



