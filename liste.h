#ifndef LISTE_H
#define LISTE_H
#include "maillon.h"

	/*les fichiers liste.h et .c contiennent 1.2, 1.3 et toutes les fonctions pour manipuler une liste*/
struct liste_s
{

	struct maillon_s * premier;
	struct maillon_s * dernier;
	int taille;
};
typedef  struct liste_s liste_t;

 

 	
 /*1.2 structure de la liste des pieces capturées*/
struct liste_piece_capture_s{
	struct maillon_piece_s * premier;
	struct maillon_piece_s* dernier;
	int taille;
};
typedef struct liste_piece_capture_s liste_piece_capture_t;
/*

1.3 structure de la liste des coups joués */
struct liste_coup_s{
	maillon_coup_t* premier;
	maillon_coup_t* dernier;
	int taille;
};
typedef struct liste_coup_s liste_coup_t;

int liste_piece_capture_vide(liste_piece_capture_t l);
liste_coup_t *liste_initialiser_cj();
liste_piece_capture_t  *liste_initialiser_pc();
void liste_coup_ajouter_debut(liste_coup_t  *l, maillon_coup_t *m);
void liste_piece_ajouter_debut(liste_piece_capture_t *l, maillon_piece_t  *m);
maillon_coup_t * liste_coup_extraire_debut(liste_coup_t *l);
maillon_piece_t * liste_piece_extraire_debut(liste_piece_capture_t *l);
maillon_coup_t * liste_coup_extraire_fin(liste_coup_t *l);
void liste_piece_empiler (liste_piece_capture_t *p, piece_t piece);
		/*les fonctions */

void liste_piece_detruire(liste_piece_capture_t *p);
int liste_piece_capture_vide(liste_piece_capture_t l);
piece_t liste_piece_depiler (liste_piece_capture_t * p);



void liste_detruire_coup(liste_coup_t *l);
piece_t liste_piece_depiler (liste_piece_capture_t * p);











#endif
