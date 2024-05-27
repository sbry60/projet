#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define TAILLE 41
#define TAILLE2 101

typedef struct{
    int numero;
    int x;
    int y;
}Cible;
typedef struct{
    int numero;
    int nb_mouv;
    int score;
}Joueur;

typedef struct{
    int numero;
    int x;
    int y;
}Robot;

void affichage(int tab[TAILLE][TAILLE],Cible tab1[TAILLE],Robot robot[TAILLE],int size);
void emoji(Robot robot[TAILLE],int i, int j);
void sleep_custom(unsigned int ms);
int puissance10(int n);
int verif_scan(int min,int max);
int min(Joueur joueur[TAILLE],int nb);
int max_score(Joueur joueur[TAILLE],int nb);
int inlistC(Cible tab2[TAILLE],int x,int y);
int inlistR(Robot tab3[TAILLE],int x,int y);
int verif_liste(int liste[TAILLE],int nb);
void matrice(int tab[TAILLE][TAILLE],int taille);
void creation_C(int tab1[TAILLE][TAILLE],Cible tab2[TAILLE],int taille);
void coins(int tab1[TAILLE][TAILLE],int x,int y);
void robot(int tab1[TAILLE][TAILLE],Robot tab3[TAILLE],int taille);
void deplacement(int tab1[TAILLE][TAILLE],Cible tab2[TAILLE],Robot rob[TAILLE],int indice,int direct,int taille);
void creation_J(Joueur tab4[TAILLE],int nb);
void jeu(int tab[TAILLE][TAILLE],Cible tab1[TAILLE],Robot robot1[TAILLE],Joueur joueurs[TAILLE],int nv,int manche,int nb_manche,int nb,int taille);
int main(void);
