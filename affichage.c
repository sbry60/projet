#include "tri.h"

//Fonction pour les emojis des robots

void emoji(Robot robot[TAILLE],int i, int j){
  if (robot[0].x==i && robot[0].y==j){       //emoji jaune
    printf("%s", "\U0001f600");
  }
  if (robot[1].x==i && robot[1].y==j){       //emoji vert
    printf("%s", "\U0001f922");
  }
  if (robot[2].x==i && robot[2].y==j){       //emoji bleu
    printf("%s", "\U0001f976");
  }
  if (robot[3].x==i && robot[3].y==j){       //emoji rouge
    printf("%s", "\U0001f621");
  }

}

//Fonction dediee a l'affichage de la grille
void affichage(int tab[TAILLE][TAILLE],Cible tab1[TAILLE],Robot robot[TAILLE],int taille){
  for(int i=0;i<taille;i++){
      for(int j=0;j<taille;j++){           //Si la case est un 1, on affiche un mur
        if(tab[i][j]==1){
           printf("⬜️");
        }
        else if(tab[i][j]==2){             //Si la case est un 1, on affiche la cible en question
           for(int k=0;k<18;k++){
             if(tab1[k].x==i&& tab1[k].y==j){
               if(tab1[k].numero<=9){         //petit reglage des espaces pour eviter les decalages
                printf("%d ",tab1[k].numero);
               }
               else{
                  printf("%d",tab1[k].numero);
               }
             }
           }
        }
        else if(tab[i][j]==3){    //Si la case est un 3, on affiche l'emomji du robot
          emoji(robot,i,j);
        }
        else{
           printf("  ");      //Sinon, on affiche du vide
        }
      }
      printf("\n");
  }
}
