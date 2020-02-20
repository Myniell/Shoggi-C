#ifndef TABLIER_H_INCLUDED
#define TABLIER_H_INCLUDED
#include "piece.h"

struct tablier_s {
piece_t** tab;
int l;
};

typedef struct tablier_s tablier_t;

tablier_t *creer_tablier();

void changer_piece(tablier_t* tab,int x, int y,piece_t p);

void detruire_piece(tablier_t* tab,int x, int y);

void afficher_tablier(tablier_t * p);

void remplir_tablier(tablier_t *tab);

void detruir_tablier(tablier_t *p);

#endif
