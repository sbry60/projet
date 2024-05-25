#include "tri.h"


int main(void) {
  srand(time(NULL));
  int taille=(rand()%6)*2+31;         //Calcul pour la creation la taille de la grille(modele 2n+1)


  Cible cibl_pos[TAILLE];              //La liste des cibles
  Robot rob_pos[TAILLE];               //La liste des robots
  Joueur joueurs[TAILLE];              //La liste des joueurs
  int tab[TAILLE][TAILLE]={0};         //Le tableau pour la matrice
  int nb_joueurs=0;                    //Variable pour le nombre de joueurs
  int manche=1;                        //Variable pour afficher la manche
  int nb_manche=0;                     //Variable pour le nombre de manche
  int niveau=0;                        //Varaible pour la difficulte du jeu


  matrice(tab,taille);                 //Initialisation de la matrice
  creation_C(tab,cibl_pos,taille);     //Creation des cibles
  for(int i=0;i<18;i++){               //Creation dess murs-angle des cibles
    coins(tab,cibl_pos[i].x,cibl_pos[i].y);
  }
  robot(tab,rob_pos,taille);            //Creation des robots

  printf("Combien de joueurs êtes-vous ?(entre 2 et max 10 joueurs)");
  nb_joueurs=verif_scan(2,10);          //Demande du nombre de joueurs

  creation_J(joueurs,nb_joueurs);       //Creation des joueurs
  
  printf("Combien de manches voulez-vous ?(max 20 )");
  nb_manche=verif_scan(1,20);           //Demande du nombre de manches

  printf("niveau de difficulté\n1=facile, 2=moyen, 3=difficile ");
  niveau=verif_scan(1,3);               //Demande du niveau de diffculté


  for(int i=0;i<nb_manche;i++){         //Execution de la manche nb_manche fois
    jeu(tab,cibl_pos,rob_pos,joueurs,niveau,manche,nb_manche,nb_joueurs,taille);
    manche++;
  }
  if (manche>nb_manche){                //Si fin des manches
    printf("Joueur %d, vous avez gagné !\n",max_score(joueurs,nb_joueurs)+1);
    for(int i=0;i<nb_joueurs;i++){
      printf("Joueur %d : %d pts\n",joueurs[i].numero,joueurs[i].score);
    }
    //On affiche le vainqueur et les score de tous les joueurs
  }


  /*for(int i=0;i<40;i++){
    for(int j=0;j<40;j++){
        printf("%d",tab[i][j]);
    }
    printf("\n");
  }
  */

  return 0;
}



