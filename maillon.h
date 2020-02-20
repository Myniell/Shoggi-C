#ifndef MAILLON_H
#define MAILLON_H
#include"piece.h"


/* définition de la structure coordonnee */
 
struct coordonnee_s{
	int x;
	int y;
};
typedef struct coordonnee_s coordonnee_t;



/* definition de la structure coup*/
struct coup_s 
{

	coordonnee_t arriver;
	coordonnee_t depart;
	int capturer;
	int promotion;
};
typedef struct coup_s coup_t;



/* definition de la structure maillon */ 
struct maillon_s
{
	int  val;
	struct maillon_s * suivant;
	struct maillon_s * precedent;
};
typedef struct maillon_s maillon_t;


/*defintion de la structure mailllon coup*/
struct maillon_coup_s {
	coup_t val;
	struct maillon_coup_s * suivant;
	struct maillon_coup_s * precedent;
};
typedef struct maillon_coup_s maillon_coup_t;


/*defintion de la structure maillon piece */ 
struct maillon_piece_s{
	piece_t val;
	struct maillon_piece_s * suivant;
	
};
typedef struct maillon_piece_s maillon_piece_t;


/*fonctions*/

coordonnee_t creer_coordonnee(int x,int y);
maillon_piece_t *maillon_piece_creer(piece_t val, maillon_piece_t *suivant);
maillon_coup_t *maillon_coup_creer(coup_t val,maillon_coup_t* suivant,maillon_coup_t* precedent);
coup_t coup_creer(coordonnee_t a,coordonnee_t d,int c,int p);
void detruire_maillon_coup(maillon_coup_t * mc);
void detruire_maillon_piece(maillon_piece_t * mp);
#endif 

