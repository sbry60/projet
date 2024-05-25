#include "tri.h"


//Fonction qui cree la matrice permettant la manipulationde la grille
void matrice(int tab[TAILLE][TAILLE],int taille){
  int nv_taille=0;       //Variable permettant de placer les murs exterieurs au bonne endroits
  for(int i=0;i<taille;i++){
    for(int j=0;j<taille;j++){
      int v=(i==0|j==0|i==taille-1|j==taille-1); //creation de la grille
      if(v){
        tab[i][j]=1; // les 1 sont les chiffres qui representent les murs dans la matrice
                     // les 0 sont les chiffres qui marquent le vide dans la matrice
      }
      else if(v==0&&(i%2==0|j%2==0)){  //Créer des case vides pour agrandir les dimensions
        tab[i][j]=9;
      }
    }
  }
  int a,b;
  if(taille%2==0){
    nv_taille=(taille-8)/2; //calcul pour initialiser nv_taille ainsi les murs ne se collent pas
  }
  else{
    nv_taille=(taille-8)/2+1;
  }
  do{
  a=(rand()%(nv_taille))*2+4;
  b=(rand()%(nv_taille))*2+4;
  }while(a==b); // pour qu'il n'y ai pas deux murs a la meme position
  tab[a][1]=1;
  tab[b][1]=1;
  do{
    a=(rand()%(nv_taille))*2+4;
    b=(rand()%(nv_taille))*2+4;
    }while(a==b);
  tab[1][a]=1;
  tab[1][b]=1;
  do{
    a=(rand()%(nv_taille))*2+4;
    b=(rand()%(nv_taille))*2+4;
    }while(a==b);
  tab[a][taille-2]=1;
  tab[b][taille-2]=1;
  do{
    a=(rand()%(nv_taille))*2+4;
    b=(rand()%(nv_taille))*2+4;
    }while(a==b);
  tab[taille-2][a]=1;
  tab[taille-2][b]=1;

}

//fonction pour le creation et le placemnent des cibles
void creation_C(int tab1[TAILLE][TAILLE],Cible tab2[TAILLE],int taille){
  Cible cible;
  int valeur=taille/2.6; //Calcul qui permet d'initialiser une taille pour que les murs-angle ne colle pas les murs de la grille
  for(int i=0;i<18;i++){
    do{                           // creation des coordonnees
    cible.y=(rand()%valeur)*2+5;
    cible.x=(rand()%valeur)*2+5;
    }while(tab1[cible.x][cible.y]!=0 | inlistC(tab2,cible.x,cible.y)==1);
    // Verification que les cibles ne se positionnes que sur les cases vides
    // verification qu'il n'y a pas deux cibles avec les memes coordonnees
    tab1[cible.x][cible.y+2]=8;    // les 8 sont les chiffres qui marquent l'interdiction pour placer une cible
    tab1[cible.x][cible.y-2]=8;
    tab1[cible.x+2][cible.y]=8;    // On les places autour des cibles pour eviter les cibles collees
    tab1[cible.x-2][cible.y]=8;
    tab1[cible.x-2][cible.y+2]=8;
    tab1[cible.x-2][cible.y-2]=8;
    tab1[cible.x+2][cible.y-2]=8;
    tab1[cible.x+2][cible.y+2]=8;
    tab1[cible.x][cible.y]=2;    // les 2 sont les chiffres qui representent les cibles dans la matrice
    cible.numero=i+1;  //Initialisation des numeros de cible
    tab2[i]=cible; //on met la cible dans la liste dediee
  }
}

// Fonction qui permet de placer les murs-angle des cibles
void coins(int tab1[TAILLE][TAILLE],int x,int y){
  int angle=(rand()%4)+1;
  if(angle==1){                // Si angle egale 1, on le place en haut a gauche
    tab1[x-1][y]=1;
    tab1[x-1][y-1]=1;
    tab1[x][y-1]=1;
  }
  if(angle==2){                // Si angle egale 2, on le place en haut a droite
    tab1[x-1][y]=1;
    tab1[x-1][y+1]=1;
    tab1[x][y+1]=1;
  }
  if(angle==3){                 // Si angle egale 3, on le place en bas a droite
    tab1[x+1][y]=1;
    tab1[x+1][y+1]=1;
    tab1[x][y+1]=1;
  }
  if(angle==4){                 // Si angle egale 4, on le place en bas a gauche
    tab1[x+1][y]=1;
    tab1[x+1][y-1]=1;
    tab1[x][y-1]=1;
  }

}

// Fonction pour la creation et le placement des robots
void robot(int tab1[TAILLE][TAILLE],Robot tab3[TAILLE],int taille){
  Robot robot;
  int valeur=taille/2.6;
  for(int i=0;i<4;i++){
    do{
    robot.y=(rand()%valeur)*2+5; // creation des coordonnees
    robot.x=(rand()%valeur)*2+5;
    }while(tab1[robot.x][robot.y]!=0 | inlistR(tab3,robot.x,robot.y)==1);
    // Verification que les robots ne se positionnes que sur les cases vides
    // verification qu'il n'y a pas deux robots avec les memes coordonnees
    tab1[robot.x][robot.y]=3; // les 2 sont les chiffres qui representent les robots dans la matrice
    robot.numero=i+1;  //Initialisation des numeros de robots
    tab3[i]=robot; //on met les robots dans la liste dediee

  }
}

//Fonction dediee pour les deplacements des robots
void deplacement(int tab1[TAILLE][TAILLE],Cible tab2[TAILLE],Robot rob[TAILLE],int indice,int direct,int taille){
  int x=rob[indice].x;        // x et y les coordonnees du robot
  int y=rob[indice].y;
  int mur=0;                  //mur represent l'abscisse ou l'ordonnee max que le robot n'a pas le droit de depasser
  if (inlistC(tab2,x,y)==1){
    tab1[x][y]=2;             // Condition permettant le reaffichage du numero de la cible quand le robot n'est pas dans la cible
  }
  else{
    tab1[x][y]=0;
  }
  if(direct==1){            //si la direction est en haut
      mur=1;                //Initialisation de la limite du deplacement robot s'il n y a pas d'obstacle devant lui
      for(int i=0;i<x;i++){
        if(tab1[i][y]==1){  //si obstacle trouve, la nouvelle limite est la case qui la precede
          mur=i+1;
        }

      }
  tab1[mur][y]=3;    //deplacement du robot
  rob[indice].x=mur; //on met a jour les coordonnes du robot
  }


  if(direct==2){          //si la direction est en bas
      mur=taille-1; 
      for(int i=taille-1;i>x;i--){
        if(tab1[i][y]==1){
          mur=i-1;
        }

      }
    tab1[mur][y]=3;
    rob[indice].x=mur;
  }

  if(direct==3){        //si la direction est a gauche
    mur=1;
    for(int i=0;i<y;i++){
      if(tab1[x][i]==1){
        mur=i+1;
      }

    }
    tab1[x][mur]=3;
    rob[indice].y=mur;
  }

  if(direct==4){       //si la direction est a droite
      mur=taille-1;
      for(int i=taille-1;i>y;i--){
        if(tab1[x][i]==1){
          mur=i-1;
        }

      }
      tab1[x][mur]=3;
      rob[indice].y=mur;
      }

}

//Fonction pour la creation et initialisation des joueurs
void creation_J(Joueur tab4[TAILLE],int nb){
  Joueur joueur;
  for(int i=0;i<nb;i++){
    joueur.numero=i+1;
    joueur.score=0;
    tab4[i]=joueur;    //on met les robots dans la liste dediee

  }

}



