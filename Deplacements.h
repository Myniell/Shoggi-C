#ifndef DEPLACEMENTS_H_INCLUDED
#define DEPLACEMENTS_H_INCLUDED
#include "partie.h"
#include "tablier.h"

int deplacement_valide_pion(int x,int y,int x1,int y1, partie_t* p );
int deplacement_valide_tour(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_cavalier(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_roi(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_fou(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_general_or(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_general_argent(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_lance(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_tour_promue(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide_fou_promue(int x,int y,int x1,int y1, partie_t* p);
int deplacement_valide(int x,int y,int x1,int y1, partie_t* p);
piece_t promotion_piece(partie_t* p);

#endif /* DEPLACEMENTS_H_INCLUDED*/
