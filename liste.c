#include<stdlib.h>
#include<stdio.h>
#include"liste.h"

/*creer une liste simplement chainée*/
liste_piece_capture_t  *liste_initialiser_pc()
{
  liste_piece_capture_t  *l = malloc(sizeof(liste_piece_capture_t));
  l-> premier = NULL; 
  l-> dernier = NULL; 
  l-> taille = 0;
  return l; 
}
/*creer une liste doublement chainée */

liste_coup_t  *liste_initialiser_cj()
{
  liste_coup_t * l = malloc(sizeof(liste_coup_t));
  l -> premier = NULL; 
  l -> dernier = NULL; 
  l -> taille = 0;
  return l; 
}


void liste_coup_ajouter_debut(liste_coup_t *l, maillon_coup_t *m)
{
  if (l -> taille == 0)
    {
      l -> premier = m;
      l -> dernier = m;
    }
  else
    {
      m -> suivant = l -> premier;
      m -> precedent = NULL;
      (l -> premier)->precedent = m;
	l->premier = m;
	}
      l -> taille++;
    
}



/*reajouter un maillon_piece à la liste des pieces capturées */
void liste_piece_ajouter_debut(liste_piece_capture_t* l, maillon_piece_t * m)
{
	if (l -> taille == 0)
	{
		l -> premier = m;
		l -> dernier = m;
		l -> taille = 1;
	}
	else
	{
		m -> suivant = l -> premier;
		l -> premier-> suivant = m;
		l -> premier = m;
		l -> taille++;
	}
}

/*extraire un maillon_coup du debut de la liste des coups joués */

maillon_coup_t * liste_coup_extraire_debut(liste_coup_t * l)
{
	if (l->taille == 0)
	{
		return NULL;
	}
		maillon_coup_t *res;
		if (l->taille !=0)
		{
			res=l->premier;
			l->premier = res->suivant;
			res->suivant = NULL;
			res->precedent = NULL;
			if(l->premier !=NULL)
				{
				(l->premier)->precedent = NULL;
				}
			
			l->taille--;
		}	
 return res;

}


int liste_piece_capture_vide(liste_piece_capture_t l){
	if(l.taille==0)
	    return 1;
return 0;
}
	
/*extraire un maillon_piece du debut de la liste des pieces capturées */

maillon_piece_t * liste_piece_extraire_debut(liste_piece_capture_t * l)
{
	maillon_piece_t * m = l -> premier; 
	if ( l -> taille == 0)
	{
		return m; 
	}
	else if ( l -> taille == 1)
	{
		l -> premier = NULL; 
		l -> dernier = NULL; 
		l -> taille = 0;
		return m; 
	}
	else  
	{
		l -> premier = m -> suivant;
		m -> suivant = NULL; 
		l -> taille --;  
	}
	return m; 
}

/*
extraire un maillon_coup de la fin de la liste des coups joués */
maillon_coup_t * liste_coup_extraire_fin(liste_coup_t * l)
{
	
	maillon_coup_t *res;
	res=l->dernier;
	
	if(l->taille != 0){
	return res;
	}
	else 
	if(l->taille == 1)
	{
	l->premier=NULL;
	l->dernier=NULL;
	l->taille=0;
	return res;
	}
	else {
	l->dernier = res->precedent;
	
	l->dernier->suivant= NULL;
	l->taille--;
	res->precedent=NULL;
	return res;
	}
return res;

}

 /*detruire coup */
void liste_detruire_coup(liste_coup_t *l){
	maillon_coup_t *d=NULL;
	while(l->taille > 0){
	d= liste_coup_extraire_fin(l);
	if (d != NULL){
		detruire_maillon_coup(d);
	}
	}
	free(l);
}
void liste_piece_empiler (liste_piece_capture_t *p, piece_t piece) {
  liste_piece_ajouter_debut(p,maillon_piece_creer(piece, NULL));
}

void liste_piece_detruire(liste_piece_capture_t *p){
	while(!liste_piece_capture_vide(*p))
	    detruire_maillon_piece(liste_piece_extraire_debut(p));
	free(p);
}


