#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maillon.h"


coordonnee_t creer_coordonnee(int x,int y){	

	coordonnee_t t;
	t.x=x;
	t.y=y;

return t;
}

/*creer un maillon_coup*/

maillon_coup_t *maillon_coup_creer(coup_t val,maillon_coup_t *suivant,maillon_coup_t *precedent)
{  
  maillon_coup_t *mc = malloc(sizeof(maillon_coup_t));
  mc->val = val; 
  mc->suivant = suivant;
  mc->precedent = precedent;
  return mc;
}

/*creer un maillon_piece*/
maillon_piece_t *maillon_piece_creer(piece_t val, maillon_piece_t *suivant)
{  
  maillon_piece_t *mp =malloc(sizeof(maillon_piece_t));
  mp->val = val;
  mp-> suivant= suivant;
  return mp;
}


/*creer un coup*/
  coup_t coup_creer(coordonnee_t a,coordonnee_t d,int c,int p){
  coup_t res;
  
  res.arriver = a;
  res.depart = d;	
  res.capturer=c;
  res.promotion=p;
  return res;
}


/*detruire un maillon_coup*/
void detruire_maillon_coup(maillon_coup_t * mc)
{	
  free (mc);
}

/*detruire un maillon_piece*/
void detruire_maillon_piece(maillon_piece_t * mp)
{	
  free (mp);
}	


