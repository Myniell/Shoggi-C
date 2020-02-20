#include<stdlib.h>
#include<stdio.h>
#include "partie.h"
#include "piece.h"
#include "tablier.h"


int main (){

int x;
	partie_t *p=malloc(sizeof(partie_t));
	p=partie_nouvelle();
	menu();
	scanf("%d",&x);

	while(x<=0||x>=3){
	menu ();
	printf("Commande invalide\n");
	scanf("%d",&x);
	}


	if(x==1){
	printf("Joueur 0 - grande pieces \n Joueur 1 - petit pieces\n");

	commencer_nouvelle_partie(p);
	}
	/*if(x==2){
	char *nom;
	printf("Pour rejoueur tappez '../tab/nom_de_jeu'\n");
	scanf("%s",nom);    																
	commencer_nouvelle_partie(partie_charger(nom)); 
																		
	}*/


return EXIT_SUCCESS;

}
