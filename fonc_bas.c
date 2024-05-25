#include "tri.h"


//Fonction permettant de mettre en pause le programme pendant ms temps
// Utilisee pour le chronometre
void sleep_custom(unsigned int ms) {
  clock_t debut_temps = clock();
  clock_t fin_temps = ms * CLOCKS_PER_SEC / 1000 + debut_temps;

  while (clock() < fin_temps);
}
//Fonction qui les puissances de 10 (10 exposant n)
int puissance10(int n){
  int a=1;
    for(int i=0;i<n;i++){
      a=a*10;
    }
  return a;

}

// Fonction permatant la verification des scanf soit bien compris entre le min et le max souhaité
int verif_scan(int min,int max){
    int ret_var = 0;
    int valeur = 1;
    int verif = 0;
    while (ret_var != 1 || valeur < 0)
    {   
        do{
        if (verif!=0){
          printf("Choix invalide. Veuillez ressaisir ");
        }
        ret_var = scanf("%d", &valeur);
        while(getchar()!='\n'){}
        verif++;

        }while(valeur<min | valeur>max);

    }
    return valeur;

}
//Fonction cherchant le joueur avec le nombre de deplacements choisi le plus faible 
int min(Joueur joueur[TAILLE],int nb){
    int min=0;
    for(int i=0;i<nb;i++){
      if (joueur[i].nb_mouv<joueur[min].nb_mouv){
        min=i;
      }
    }
    return min;
}

//Fonction cherchant le joueur avec le score le plus eleve
int max_score(Joueur joueur[TAILLE],int nb){
    int max=0;
    for(int i=0;i<nb;i++){
      if (joueur[i].score>joueur[max].score){
        max=i;
      }
    }
    return max;
}

/*Fonction cherchant dans une liste de cibles si les coordonnees x,y ne sont identique
a aucune des coordonnees des cibles*/
int inlistC(Cible tab2[TAILLE],int x,int y){
  for(int i=0;i<18;i++){
    if(tab2[i].x==x&&tab2[i].y==y)
      return 1;
  }
  return 0;
}
/*Fonction cherchant dans une liste de robots si les coordonnees x,y ne sont identique
a aucune des coordonnees des robots*/
int inlistR(Robot tab3[TAILLE],int x,int y){
  for(int i=0;i<4;i++){
    if(tab3[i].x==x&&tab3[i].y==y)
      return 1;
  }
  return 0;
}


//Fonction utilisee pour la selection des directions des deplacements
/*Sachant que les touches de 1 a 4 sont utilisee pour les deplacement
Elle verifie si dans la liste il ne contient ni des valeurs 
superieures ou egales a 0 ou des valeurs superieures a 4*/
int verif_liste(int liste[TAILLE],int nb){
    for(int i=0;i<nb;i++){
      if(liste[i]<=0|liste[i]>4){
        return 1;
      }
    }
  return 0;
}
