#ifndef PARTIE_H
#define PARTIE_H
#include "tablier.h"
#include "liste.h"

struct partie_s{
	tablier_t* tab;
	liste_piece_capture_t *pc;
	liste_coup_t * cj;
	int joueur;
};
typedef struct partie_s partie_t;

int case_vide(partie_t *p, int x , int y);
piece_t contenu_case(partie_t * p, int x, int y);
void modifier_case(partie_t* partie,piece_t piece,int x,int y);
void changer_joueur(partie_t *partie);
void afficher_echiquier(partie_t *partie);  
int joueur_valid(partie_t *partie ,int x,int y);
partie_t * partie_creer();
void deplacement(partie_t* p);
void partie_detruire(partie_t* partie);
partie_t * partie_nouvelle();/*
void annuler_deplacement(partie_t * partie);*/
void menu ();

void partie_sauvegarder(partie_t* partie, char *nom);
partie_t* partie_charger(char *nom);
void commencer_nouvelle_partie(partie_t *p);
void modifier_contenue_case(partie_t *t,int x,int y, char c, int v, int s);

#endif 


