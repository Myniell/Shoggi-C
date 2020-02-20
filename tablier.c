#include <stdio.h>
#include <stdlib.h>
#include "tablier.h"





                /* Fonction pur creer l'echiquier */

tablier_t *creer_tablier(){


	int i,j,l=11;
	piece_t p =piece_creer(0,non_promue,'.');


	tablier_t * res =(tablier_t*)malloc(sizeof(tablier_t));
	res -> tab =malloc(sizeof(piece_t)*l);
	for(i = 0; i < l; i++)
		{
			res -> tab[i] =malloc(sizeof(piece_t)*l);
		}

	res -> l = l;

	for(i = 0; i < res ->l; i++)
	{
		for(j = 0; j < res ->l; j++)
		{
			res -> tab[i][j] = p;
		}
	}



	return res;
}

                                                /* Changer la piece*/

void changer_piece(tablier_t* tab,int x, int y,piece_t p)
{
    tab->tab[x][y]=p;
}


                                                        /* Supprimer la piece*/



void detruire_piece(tablier_t* tab,int x, int y)
{
	piece_t p=piece_creer(0,non_promue,'.');
   tab->tab[x][y]=p;
}

void afficher_tablier(tablier_t * p)
{
	int i;
	int j;
	printf(" ");
	for(j = 0 ; j < p -> l ; j += 1)
	{
	printf(" %2d",j);
	}
	printf("\n");


	for ( i = 0 ; i < p -> l ; i += 1 )
	{

	printf("%d",i);

		for ( j = 0 ; j < p -> l ; j += 1 )
		{

			 piece_afficher(p -> tab[i][j]);



		}
		if (j==p->l)
		printf("%3d",i);
	printf("\n");
	}
	printf(" ");
	for(j = 0 ; j < p -> l ; j += 1)
	{
	printf(" %2d",j);
	}
	printf("\n");
	printf("\n----------------------------------------------------------------\n");
}



                                /* Remplace le '.' par des pieces */

void remplir_tablier(tablier_t *tab){

changer_piece(tab,1,1,piece_creer(0,non_promue,'L'));
changer_piece(tab,1,2,piece_creer(0,non_promue,'N'));
changer_piece(tab,1,3,piece_creer(0,non_promue,'S'));
changer_piece(tab,1,4,piece_creer(0,non_promue,'G'));
changer_piece(tab,1,5,piece_creer(0,non_promue,'K'));
changer_piece(tab,1,6,piece_creer(0,non_promue,'G'));
changer_piece(tab,1,7,piece_creer(0,non_promue,'S'));
changer_piece(tab,1,8,piece_creer(0,non_promue,'N'));
changer_piece(tab,1,9,piece_creer(0,non_promue,'L'));

changer_piece(tab,2,2,piece_creer(0,non_promue,'R'));
changer_piece(tab,2,8,piece_creer(0,non_promue,'B'));


changer_piece(tab,3,1,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,2,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,3,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,4,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,5,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,6,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,7,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,8,piece_creer(0,non_promue,'P'));
changer_piece(tab,3,9,piece_creer(0,non_promue,'P'));


changer_piece(tab,9,1,piece_creer(1,non_promue,'l'));
changer_piece(tab,9,2,piece_creer(1,non_promue,'n'));
changer_piece(tab,9,3,piece_creer(1,non_promue,'s'));
changer_piece(tab,9,4,piece_creer(1,non_promue,'g'));
changer_piece(tab,9,5,piece_creer(1,non_promue,'k'));
changer_piece(tab,9,6,piece_creer(1,non_promue,'g'));
changer_piece(tab,9,7,piece_creer(1,non_promue,'s'));
changer_piece(tab,9,8,piece_creer(1,non_promue,'n'));
changer_piece(tab,9,9,piece_creer(1,non_promue,'l'));

changer_piece(tab,8,2,piece_creer(1,non_promue,'b'));
changer_piece(tab,8,8,piece_creer(1,non_promue,'r'));


changer_piece(tab,7,1,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,2,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,3,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,4,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,5,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,6,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,7,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,8,piece_creer(1,non_promue,'p'));
changer_piece(tab,7,9,piece_creer(1,non_promue,'p'));

}


void detruir_tablier(tablier_t *p){
	free(p->tab);

}








