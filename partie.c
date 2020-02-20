#include<stdlib.h>
#include<stdio.h>
#include "partie.h"
#include "Deplacements.h"


piece_t contenu_case(partie_t* p ,int x, int y)
{

    return p-> tab->tab[x][y];
	

}

                        /* verifie si la case de tableau est vide */

int case_vide(partie_t * p,int x ,int y){

	piece_t piece= contenu_case(p,x,y);
	if(piece.joueur==0)
		return 1;
	else
		return 0;
}


                   /* Modifie la case d'un tableau*/

void modifier_case(partie_t* p,piece_t piece,int x,int y){

changer_piece(p->tab,x,y,piece);

}


                    /* Change le joueur */

void changer_joueur(partie_t* partie){

	if(partie->joueur==1)
		partie->joueur = 0;
	else
		partie->joueur = 1;
}

                     /*Affiche le tablier */

void afficher_echiquier(partie_t* partie){

	afficher_tablier(partie->tab);
}



void deplacement(partie_t* p){


	int x=0,x1=0,y=0,y1=0,cmp=0;

while(x<=0||x>=9||x1<=0||x1>=9||y<=0||y>=9||y1<=0||y1>=9||joueur_valid(p,x,y)==0){

	if(cmp!=0){
		afficher_tablier(p->tab);
		printf("mouvement invalide \n ");


	}


	printf("Donnez le (x,y) de depart et (x,y) d'arriver:\n");
	printf("Depart x\n");
	scanf("%d",&x);
	printf("Depart y\n");
	scanf("%d",&y);
	printf("Arrive x\n");
	scanf("%d",&x1);
	printf("Arrive y\n");
	scanf("%d",&y1);


		cmp++;


		if(deplacement_valide(x,y,x1,y1,p)==0){
		
		
		printf("Mouvement invalide de piece \n");

		if(p->joueur==0)
		printf("joueur 0\n");
		else
		printf("joueur 1\n");

			x=10;

			}
		}


		if(deplacement_valide(x,y,x1,y1,p)==1){
		coup_t coup;
		coup=coup_creer(creer_coordonnee(x1,y1),creer_coordonnee(x,y),0,0);
		liste_coup_ajouter_debut(p->cj,maillon_coup_creer(coup,NULL,NULL));
		changer_piece(p->tab,x1,y1,contenu_case(p,x,y));
		detruire_piece(p->tab,x,y);
	}


	if(deplacement_valide(x,y,x1,y1,p)==2){
		printf("WTF1");
		coup_t coup;
		coup=coup_creer(creer_coordonnee(x1,y1),creer_coordonnee(x,y),1,0);
		liste_coup_ajouter_debut(p->cj,maillon_coup_creer(coup,NULL,NULL));
		liste_piece_ajouter_debut(p->pc,maillon_piece_creer(contenu_case(p,x1,y1),NULL));
		changer_piece(p->tab,x1,y1,contenu_case(p,x,y));
		detruire_piece(p->tab,x,y);
	}


	/*
	 if(deplacement_valide(x,y,x1,y1,p)==3){

			changer_piece(p->tab,x1,y1,contenu_case(p->tab,x,y));
			changer_piece(p->tab,x1,y1,piece_promotion(p));
			supprimer_piece(p->tab,x,y);
	}*/


} 


int joueur_valid(partie_t *partie ,int x,int y){
	if((partie->joueur==0&&piece_joueur(contenu_case(partie,x,y))==0)||(partie->joueur==1 && piece_joueur(contenu_case(partie,x,y))==1))
	return 1;
	else
	return 0;
}


partie_t * partie_creer(){
	partie_t *p=malloc(sizeof(partie_t));
	p->joueur =0;
	p->tab=creer_tablier();
	creer_tablier(p->tab);
	p->pc->premier=NULL;
	p->cj->premier=NULL;
	p->pc->taille=0;
	p->cj->taille=0;
return p;
}

void partie_detruire(partie_t* partie){

	liste_piece_detruire(partie->pc);
	liste_detruire_coup(partie->cj);
	free(partie);
}

partie_t * partie_nouvelle(){


	partie_t*p =malloc(sizeof(partie_t));
	p->tab=creer_tablier();
	remplir_tablier(p->tab);
	p->cj=liste_initialiser_cj();
	p->pc=liste_initialiser_pc();
	p->joueur=0;

return p;

}
/*
void annuler_deplacement(partie_t * partie){
	int x,x1,y,y1;

	if(partie->lcoups->debut->capture==0){

		x=partie->cj->debut->depart->x;
		y=partie->cj->debut->depart->y;
		x1=partie->cj->debut->arrive->x;
		y1=partie->cj->debut->arrive->y;
		changer_piece(partie->tab,x,y,contenu_case(partie->tab,x1,y1));
		supprimer_piece(partie->tab,x1,y1);

		}
	else{
		x=partie->cj->debut->depart->x;
		y=partie->cj->debut->depart->y;
		x1=partie->cj->debut->arrive->x;
		y1=partie->cj->debut->arrive->y;
		changer_piece(partie->tab,x,y,contenu_case(partie->tab,x1,y1));
		}
	}
*/
void menu (){
printf("____________________________________\n");
printf("|---------------MENU---------------|\n");
printf("|Pour commencer une nouvelle partie|\n");
printf("|Tappez 1__________________________|\n");
printf("|__________________________________|\n");
printf("|Pour continuer une partie_________|\n");
printf("|Tappez 2__________________________|\n");
printf("|__________________________________|\n");

}

void commencer_nouvelle_partie(partie_t *p){

char *n=malloc(sizeof(char));
int a,b,c;
afficher_tablier(p->tab);




	printf("Pour faire un deplacement, tappez 1! \n Pour sortir, tappez 2!\n");
	scanf("%d",&a);


	while(a>=3||a<=-1){
		printf("Choix Invalide\n");
		scanf("%d",&a);
	 	}
	
	if (a==2){
		printf("Pour sauvegarder la partie, tappez 1\n Pour sortir sans sauvegarder, tappez 2\n");
		scanf("%d",&c);
			if(c==1){
			printf("pour sauvegarder tappez '../tab/nom_de_jeu'\n");
			scanf("%s",n);
			partie_sauvegarder(p,n);
			c=2;
			}
		}






	while((p->joueur==0||p->joueur==1)&&a==1){
	
		if(p->joueur==0){

	printf("JOUEUR 0\n");
	deplacement(p);
	afficher_tablier(p->tab);
	printf("Pour annuler le coup précédent tappez 1, sinon 0\n");
	scanf("%d",&b);
		while(b>=2||b<=-1){
			printf("Choix Invalide\n");
			scanf("%d",&b);
			}
/*
		if(b==1){
			afficher_tablier(p->tab);
			annuler_deplacement(p);
			afficher_tablier(p->tab);
		deplacement(p);
		afficher_tablier(p->tab);
		}*/
	}

		if(p->joueur==1){


	printf("Joueur 1 \n");

	deplacement(p);
	afficher_tablier(p->tab);
	printf("Pour annuler le coup précédent tappez 1, sinon 0\n");
	scanf("%d",&b);
		while(b>=2||b<=-1){
			printf("Choix Invalide\n");
			scanf("%d",&b);
			}
/*
		if(b==1){
			afficher_tableau(p->tab);
			annuler_deplacement(p);
			afficher_tableau(p->tab);
		deplacement(p);
		afficher_tablier(p->tab);
		}*/

	}
	
	changer_joueur(p);
	afficher_tablier(p->tab);

	printf("Pour faire un deplacement, tappez 1! \n Pour sortir, tappez 2!\n");
	scanf("%d",&a);


	while(a>=3||a<=-1){
		printf("Choix Invalide\n");
		scanf("%d",&a);
	 	}
	
	if (a==2){
		printf("Pour sauvegarder la partie, tappez 1\n Pour sortir sans sauvegarder, tappez 2\n");
		scanf("%d",&c);
			if(c==1){
			printf("pour sauvegarder tappez '../tab/nom_de_jeu'\n");
			scanf("%s",n);
			partie_sauvegarder(p,n);
			c=2;
			}
		}

}
}

void partie_sauvegarder(partie_t* partie, char *nom){

FILE * f=NULL;



int i,j;

f=fopen((nom),"w");
	if(f!=NULL)
	{


	for(i=0;i<11;i++)
		{
		for (j=0;j<11;j++)
			{

				fprintf(f," %c",piece_charactere(contenu_case(partie->tab,i,j)));

			}
		printf("\n");
		}

fclose(f);
 	}

}

partie_t* partie_charger(char *nom){

FILE * f=NULL;

char data[11][11];

int i,j;
char e;
partie_t *p;

f=fopen(nom,"r");
	if(f!=NULL)
	{

	p=partie_nouvelle();

	for(i=0;i<11;i++)
		{
		for (j=0;j<11;j++)
			{

				fscanf(f," %c",&data[i][j]);
				e=data[i][j];


				if(e=='L'||e=='N'||e=='S'||e=='G'||e=='K'||e=='R'||e=='B'||e=='P')
				modifier_contenue_case(p,i,j,e,0,0);
				if(e=='D'||e=='J'||e=='C'||e=='F'||e=='T'||e=='A')
				modifier_contenue_case(p,i,j,e,0,1);
				

				if(e=='l'||e=='n'||e=='s'||e=='g'||e=='k'||e=='r'||e=='b'||e=='p')
				modifier_contenue_case(p,i,j,e,1,0);
				if(e=='d'||e=='j'||e=='c'||e=='f'||e=='t'||e=='a')
				modifier_contenue_case(p,i,j,e,1,1);


				if(e=='.')
				modifier_contenue_case(p,i,j,e,-1,0);

			}
		}

	return p;

fclose(f);
 	}
  else
	{
	return NULL;
	}
}

void modifier_contenue_case(partie_t *t,int x,int y, char c, int v, int s){

	piece_t p;
	p.type=c;
	p.joueur=v;
	p.statut=s;

	changer_piece(t->tab,x,y,p);


}







