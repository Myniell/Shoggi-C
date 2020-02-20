#ifndef PIECE_H
#define PIECE_H 
#define JOUEUR1 1
#define JOUEUR0 0
#define promue 1
#define non_promue 0
/*#define VIDE 2*/



enum type_s { PION, LANCE, CAVALIER, FOU, TOUR, GENERAL_DARGENT , GENERAL_DOR , ROI}; 
typedef enum type_s type_t;


struct piece_s{
	int joueur;
	char type;
	int statut;
};
typedef struct piece_s piece_t;

piece_t piece_creer(int j,int s,char t);
int piece_joueur(piece_t p);
piece_t piece_identifier(char c);
char piece_charactere(piece_t piece);
void piece_afficher(piece_t piece);

#endif 
