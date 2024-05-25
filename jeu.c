#include "tri.h"



//Fonction pour effectuer une seule manche
void jeu(int tab[TAILLE][TAILLE],Cible tab1[TAILLE],Robot robot1[TAILLE],Joueur joueurs[TAILLE],int nv,int manche,int nb_manche,int nb,int taille){
    srand(time(NULL));
    int parcours=0;            //Variable pour la selection des directions des deplacements
    int select_rob=0;          //variable pour le choix aleatoire du robot
    int select_cib=0;          //variable pour le choix aleatoire de la cible
    do{
    select_rob=rand()%4;
    select_cib=rand()%18;
    }while(robot1[select_rob].x==tab1[select_cib].x && robot1[select_rob].y==tab1[select_cib].y);
    /*Verification que le robot ne soit pas deja dans la cible demandee*/
    int temps=0;      //variable pour le chronometre
    Joueur pl_min;    //Pour choisir qui sera le joueur qui porra deplacer le robot
    if(nv==1){        //variable pour choisir la difficulte et donc diminuer le temps
      temps=60;
    }
    if(nv==2){
      temps=45;
    }
    if(nv==3){
      temps=30;
    }

    for(int i=0;i<temps;i++){
      printf("%d\n",i);         //affichage du chronometre
      printf("Manche %d/%d\n",manche,nb_manche);       //affichage du numero de la manche
      printf("Robot ");
      emoji(robot1,robot1[select_rob].x,robot1[select_rob].y);
      printf(" Cible %d\n",select_cib+1);    //affichage du robot a deplacer et la cible a atteindre
      affichage(tab,tab1,robot1,taille);  //affichage de la grille
      sleep_custom(1000);    //mettre en pause d'une seconde pour le chronometre
      system("clear");       //effacer la console 
    }
    int a=0;              //variable pour le choix du nombre de deplacements
    for(int i=0;i<nb;i++){
      printf("Joueur %d, entrez le nombre de vos deplacements (max 100) ",i+1);
      a=verif_scan(1,101);
      joueurs[i].nb_mouv=a;  //nb_mouv prend le nombre de deplacement du joueur
    }
    pl_min=joueurs[min(joueurs,nb)]; //grace a la fonction min, nous avons le joueur qui a le moins de mouvement
    
    int liste[TAILLE2]={0}; //liste pour la selection des deplacements
    do{
    printf("Joueur %d, ecrivez votre parcours\n1=haut, 2=bas, 3=gauche,4=droite ",pl_min.numero);
    parcours=verif_scan(1,puissance10(pl_min.nb_mouv)); 
    /* Transformation d'un nombre a n chiffre en une liste a n elements
    pour faciliter l'execution de la fonction depalcement*/
    for(int i=pl_min.nb_mouv;i>0;i--){
       liste[pl_min.nb_mouv-i]=parcours/puissance10(i-1);
       parcours-=liste[pl_min.nb_mouv-i]*puissance10(i-1);

    }
    }while(verif_liste(liste,pl_min.nb_mouv)==1);


    int mouv_realise=0;   /*variable pour la verification pour voir qu'on 
    fais bien le nombre de mouvement choisi par le joueur*/
    for(int i=0;i<pl_min.nb_mouv;i++){
      system("clear");
      affichage(tab,tab1,robot1,taille);
      deplacement(tab,tab1,robot1,select_rob,liste[i],taille);
      if(tab1[select_rob].x!=robot1[select_rob].x && tab1[select_rob].y!=robot1[select_rob].y){
        mouv_realise++;
      }
      sleep_custom(3000);
    }
    int mm_coord=(tab1[select_rob].x==robot1[select_rob].x && tab1[select_rob].y==robot1[select_rob].y);
    if( mm_coord && mouv_realise==pl_min.nb_mouv){
        pl_min.score+=2; /*si le robot arrive a la cible avec le nombre de mouvement qu'il
        choisi, il prend 2 points*/
    }
    else if( mm_coord && mouv_realise!=pl_min.nb_mouv){
        pl_min.score-=1; /*si le robot arrive a la cible mais le nombre de mouvement qu'il
        choisi n'est pas respecte, le joueur perd 1 point*/
    }
    else{
    for(int i=0;i<nb;i++){      
      if(i!=min(joueurs,nb)){
        joueurs[i].score++;   /*sinon tout les autres joueurs prennent 1 point*/
      }
      
    }
    }
  





}

