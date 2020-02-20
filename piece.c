#include <stdio.h>
#include "piece.h"


piece_t piece_creer(int j,int s,char t)
{
	piece_t piece;
	piece.joueur=j;
	piece.statut=s;
	piece.type=t;
	return piece;
}

int piece_joueur(piece_t p)
{
	
	return p.joueur;
}	

piece_t piece_identifier(char c)
{
	 piece_t piece;
   /*JOUEUR0*/
  if(c=='P')
    piece = piece_creer(0,non_promue,'P');
  if(c=='L')
    piece = piece_creer(0,non_promue,'L');
  if(c=='N')
    piece = piece_creer(0,non_promue,'N');
  if(c=='B')
    piece = piece_creer(0,non_promue,'B');
  if(c=='R')
    piece = piece_creer(0,non_promue,'R');
  if(c=='S')
    piece = piece_creer(0,non_promue,'S');
  if(c=='G')
    piece = piece_creer(0,non_promue,'G');
  if(c=='K')
    piece = piece_creer(0,non_promue,'K');
  if(c=='D')
    piece = piece_creer(0,promue,'D');
  if(c=='J')
    piece = piece_creer(0,promue,'J');
  if(c=='C')
    piece = piece_creer(0,promue,'C');
  if(c=='F')
    piece = piece_creer(0,promue,'F');
  if(c=='T')
    piece = piece_creer(0,promue,'T');
  if(c=='A')
    piece = piece_creer(0,promue,'A');
  /*JOUEUR1*/
  if(c=='p')
    piece = piece_creer(1,non_promue,'p');
  if(c=='l')
    piece = piece_creer(1,non_promue,'l');
  if(c=='n')
    piece = piece_creer(1,non_promue,'n');
  if(c=='b')
    piece = piece_creer(1,non_promue,'b');
  if(c=='r')
    piece = piece_creer(1,non_promue,'r');
  if(c=='s')
    piece = piece_creer(1,non_promue,'s');
  if(c=='g')
    piece = piece_creer(1,non_promue,'g');
  if(c=='k')
    piece = piece_creer(1,non_promue,'k');
  if(c=='d')
    piece = piece_creer(1,promue,'d');
  if(c=='j')
    piece = piece_creer(1,promue,'j');
  if(c=='c')
    piece = piece_creer(1,promue,'c');
  if(c=='f')
    piece = piece_creer(1,promue,'f');
  if(c=='t')
    piece = piece_creer(1,promue,'t');
  if(c=='a')
    piece = piece_creer(1,promue,'a');
  
  
  return piece;	
}

char piece_charactere(piece_t piece)
{
   /*JOUEUR0*/
  if(piece.joueur==0 && piece.type=='P' && piece.statut==non_promue)
    return 'P';
  if(piece.joueur==0 && piece.type=='L' && piece.statut==non_promue)
    return 'L';	
  if(piece.joueur==0 && piece.type=='N' && piece.statut==non_promue)
    return 'N';
  if(piece.joueur==0 && piece.type=='B' && piece.statut==non_promue)
    return 'B';
  if(piece.joueur==0 && piece.type=='R' && piece.statut==non_promue)
    return 'R';
  if(piece.joueur==0 && piece.type=='S' && piece.statut==non_promue)
    return 'S';
  if(piece.joueur==0 && piece.type=='G' && piece.statut==non_promue)
    return 'G';
  if(piece.joueur==0 && piece.type=='K' && piece.statut==non_promue)
    return 'K';	
  if(piece.joueur==0 && piece.type=='D' && piece.statut==promue)
    return 'D';
  if(piece.joueur==0 && piece.type=='J' && piece.statut==promue)
    return 'J';	
  if(piece.joueur==0 && piece.type=='C' && piece.statut==promue)
    return 'C';
  if(piece.joueur==0 && piece.type=='F' && piece.statut==promue)
    return 'F';
  if(piece.joueur==0 && piece.type=='T' && piece.statut==promue)
    return 'T';
  if(piece.joueur==0 && piece.type=='A' && piece.statut==promue)
    return 'A';
  /*JOUEUR1*/
  if(piece.joueur==1 && piece.type=='p' && piece.statut==non_promue)
    return 'p';
  if(piece.joueur==1 && piece.type=='l' && piece.statut==non_promue)
    return 'l';	
  if(piece.joueur==1 && piece.type=='n' && piece.statut==non_promue)
    return 'n';
  if(piece.joueur==1 && piece.type=='b' && piece.statut==non_promue)
    return 'b';
  if(piece.joueur==1 && piece.type=='r' && piece.statut==non_promue)
    return 'r';
  if(piece.joueur==1 && piece.type=='s' && piece.statut==non_promue)
    return 's';
  if(piece.joueur==1 && piece.type=='g' && piece.statut==non_promue)
    return 'g';
  if(piece.joueur==1 && piece.type=='k' && piece.statut==non_promue)
    return 'k';	
  if(piece.joueur==1 && piece.type=='d' && piece.statut==promue)
    return 'd';
  if(piece.joueur==1 && piece.type=='j' && piece.statut==promue)
    return 'j';	
  if(piece.joueur==1 && piece.type=='c' && piece.statut==promue)
    return 'c';
  if(piece.joueur==1 && piece.type=='f' && piece.statut==promue)
    return 'f';
  if(piece.joueur==1 && piece.type=='t' && piece.statut==promue)
    return 't';
  if(piece.joueur==1 && piece.type=='a' && piece.statut==promue)
    return 'a';
  else
  return '.';
}


void piece_afficher(piece_t piece)
{
	printf("  %c",piece_charactere(piece));
}

