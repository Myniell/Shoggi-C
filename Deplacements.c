#include<stdlib.h>
#include<stdio.h>
#include"Deplacements.h"

int deplacement_valide_pion(int x,int y,int x1,int y1, partie_t* p)
{
int j,k,l;

/*        Non promue                       Promue

      9 o o o o o o o o o             9 o o o o o o o o o
      8 o o o o o o o o o             8 o o o o o o o o o
      7 o o o o o o o o o             7 o o o o o o o o o
      6 o o o o o o o o o             6 o o o o o o o o o
      5 o o o x o o o o o             5 o o x x x o o o o
      4 o o o P o o o o o             4 o o x P x o o o o
      3 o o o o o o o o o             3 o o o x o o o o o
      2 o o o o o o o o o             2 o o o o o o o o o
      1 o o o o o o o o o             1 o o o o o o o o o
        1 2 3 4 5 6 7 8 9               1 2 3 4 5 6 7 8 9
                           */

        j=piece_joueur(contenu_case(p,x,y));
        k=piece_joueur(contenu_case(p,x1,y1));
        l=j+k;

					/* joueur 0 */
	if (j==0){
   	 if (y==y1 && x1==x+1)
        	{
       		if(case_vide(p,y1,x1)==1)
     			return 1;
        	else if (l==0)
            		return 2;
        	else
            		return 0;
		}
	}
					/* joueur 1 */
	if (j==1){
       	 if (y==y1 && x1==x-1)
      	        {
       		if(case_vide(p,y1,x1)==1)
     			return 1;
      		  else if (l==0)
          		  return 2;
       		 else
          		  return 0;
		} 
	}  
return 0;
}

int deplacement_valide_tour(int y,int x,int y1,int x1, partie_t* p)
{

/*        Non promue                       Promue

      9 o o o x o o o o o              9 o o o x o o o o o
      8 o o o x o o o o o              8 o o o x o o o o o
      7 o o o x o o o o o              7 o o o x o o o o o
      6 o o o x o o o o o              6 o o o x o o o o o
      5 o o o x o o o o o              5 o o x x x o o o o
      4 x x x T x x x x x              4 x x x T x x x x x
      3 o o o x o o o o o              3 o o x x x o o o o
      2 o o o x o o o o o              2 o o o x o o o o o
      1 o o o x o o o o o              1 o o o x o o o o o
        1 2 3 4 5 6 7 8 9                1 2 3 4 5 6 7 8 9
                           */

int i,k,l,cmp1,cmp2;
	k=piece_joueur(contenu_case(p,x,y));
    l=piece_joueur(contenu_case(p,x1,y1));
	cmp1=0;cmp2=0;

	if(x==x1&&y<y1){
		for(i=y;i<y1;i++){
			if(case_vide(p,x,i+1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;

		}



	if(x==x1&&y>y1){
		for(i=y;i>y1;i--){
			if(case_vide(p,x,i-1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;

		}




	if( y==y1 && x<x1 ){
		for(i=x;i<x1;i++){
			if(case_vide(p,i+1,y)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;

		}



	if( y==y1 && x>x1 ){
		for(i=x;i>=x1;i--){
		if(case_vide(p,i-1,y)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;;

		}

return 0;
}

int deplacement_valide_roi(int y, int x, int y1, int x1, partie_t *p)
{

	int j,k,l;

/*    9 o o o o o o o o o
      8 o o o o o o o o o
      7 o o o x x x o o o
      6 o o o x R x o o o
      5 o o o x x x o o o
      4 o o o o o o o o o
      3 o o o o o o o o o
      2 o o o o o o o o o
      1 o o o o o o o o o
        1 2 3 4 5 6 7 8 9
                       */    

        j=piece_joueur(contenu_case(p,x,y)); 
        k=piece_joueur(contenu_case(p,x1,y1)); 
        l=j+k;


    if (x==x1 && y1==y+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (x==x1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (y==y1 && x1==x+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if (y==y1 && x1==x-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
/* >------------------------------------------------------------------------------------------------------------< */ 

    else if(x1==x+1 && y1==y+1)
          {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x+1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y+1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y-1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
	else
		return 0;


}

int deplacement_valide_cavalier(int y,int x,int y1,int x1, partie_t* p)
{

	int j,l,k;
/*    1 . . . . . . . . .
      2 . . . . . . . . .
      3 . . . . . . . . .
      4 . . . X . X . . .
      5 . . . . . . . . .
      6 . . . . C . . . .
      7 . . . . . . . . .
      8 . . . x . x . . .
      9 . . . . . . . . .
        1 2 3 4 5 6 7 8 9
                          */ 
    	j=piece_joueur(contenu_case(p,x,y));
        k=piece_joueur(contenu_case(p,x1,y1));
        l=j+k;


					/* Joueur 0 */
	if (j==0)
	{
   	 if (x1==x-1 && y1==y+2)
      	{
   		if(case_vide(p,x1,y1)==1)
   		  return 1;
    	if (l==1)
    	    return 2;
    	else
    	    return 0;
        }

   else if (x1==x+1 && y1==y+2)
     {
   		if(case_vide(p,x1,y1)==1)
   		  return 1;
    	if (l==1)
    	    return 2;
    	else
    	    return 0;
        }
	}

					/* joueur 1 */
	if (j==1)
	{
     	if (x1==x+1 && y1==y-2)
        {
   		if(case_vide(p,x1,y1)==1)
   		  return 1;
    	if (l==1)
    	    return 2;
    	else
    	    return 0;
        }


    	else if (x1==x-1 && y1==y-2)
      	{
   		if(case_vide(p,x1,y1)==1)
   		  return 1;
    	if (l==1)
    	    return 2;
    	else
    	    return 0;
     	 }
	 }
     	return 0;

}


int deplacement_valide_fou(int y,int x,int y1,int x1, partie_t* p)
{
 int i,j,k,l,cmp1,cmp2;
	k=piece_joueur(contenu_case(p,x,y));
    l=piece_joueur(contenu_case(p,x1,y1));
    cmp1=0;cmp2=0;
	if(x<x1&&y<y1){
		for(i=x,j=y;i<x1;i++,j++){
			if(case_vide(p,i+1,j+1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;



	}


	if(x>x1&&y>y1){
		for(i=x,j=y;i>x1;i--,j--){
			if(case_vide(p,i-1,j-1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;


	}

	if(x>x1&&y<y1){
		for(i=x,j=y;i>x1;i--,j++){
			if(case_vide(p,i-1,j+1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;


	}


	if(x<x1&&y>y1){
		for(i=x,j=y;i<x1;i++,j--){
			if(case_vide(p,i+1,j-1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;



	}

	return 0;
}


int deplacement_valide_general_or(int y,int x,int y1,int x1, partie_t* p)
{

	int j,k,l;

/*    1 o o o o o o o o o
      2 o o o o o o o o o
      3 o o o x x x o o o
      4 o o o x G x o o o
      5 o o o o x o o o o
      6 o o o o o o o o o
      7 o o o o o o o o o
      8 o o o o o o o o o
      9 o o o o o o o o o
        1 2 3 4 5 6 7 8 9
                        */   

        j=piece_joueur(contenu_case(p,x,y));
        k=piece_joueur(contenu_case(p,x1,y1));
        l=j+k;


								/* Joueur 0 */
	if (j==0)
	{
    	if (x==x1 && y1==y+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (x==x1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (y==y1 && x1==x+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if (y==y1 && x1==x-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

    else if(x1==x+1 && y1==y+1)
          {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
	}

								/* Joueur 1 */

	if(j==1)
	{
    	if (x==x1 && y1==y+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (x==x1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

   else if (y==y1 && x1==x+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if (y==y1 && x1==x-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y-1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==3)
            return 2;
        else
            return 0;

	}
   else if(x1==x+1 && y1==y-1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==3)
            return 2;
        else
            return 0;

        } 
	}
	return 0;
}


int deplacement_valide_general_argent(int y,int x,int y1,int x1, partie_t* p)
{

	int j,k,l;

/*    1 o o o o o o o o o
      2 o o o o o o o o o
      3 o o o x o x o o o
      4 o o o o S o o o o
      5 o o o x x x o o o
      6 o o o o o o o o o
      7 o o o o o o o o o
      8 o o o o o o o o o
      9 o o o o o o o o o
        1 2 3 4 5 6 7 8 9
                           */

        j=piece_joueur(contenu_case(p,x,y));
        k=piece_joueur(contenu_case(p,x1,y1));
        l=j+k;

							  /*   Joueur 0  */

	if(j==0)
	{
    	if (x==x1 && y1==y+1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

    else if(x1==x+1 && y1==y+1)
          {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x+1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y+1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y-1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
}
 							   /* Joueur 1 */

	if (j==1)
	{
	if (x==x1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }

    else if(x1==x+1 && y1==y+1)
          {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x+1 && y1==y-1)
        {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y+1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;

        }
   else if(x1==x-1 && y1==y-1)
         {
       	if(case_vide(p,x1,y1)==1)
     		return 1;
        else if (l==1)
            return 2;
        else
            return 0;
	}
	}
		return 0;
}


int deplacement_valide_lance(int x,int y,int x1,int y1, partie_t* p)
{
    int i,k,l,cmp1,cmp2;
	k=piece_joueur(contenu_case(p,x,y));
        l=piece_joueur(contenu_case(p,x1,y1));
	cmp1=0;cmp2=0;

	if (k==0){
	if(y==y1&&x<x1){
		for(i=x;i<x1;i++){
			if(case_vide(p,y,i+1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;

		}


	}
	if (k==1){
	if(y==y1&&x>x1){
		for(i=x;i>x1;i--){
			if(case_vide(p,y,i-1)==1){
				cmp1++;
				}
			else
				cmp2++;
		}
		if(cmp2==0)
			return 1;
		else if (cmp1-cmp2==cmp1-1&&k+l==1)
			return 2;
		else
			return 0;

        	}
	}
    return 0;
}

int deplacement_valide_fou_promue(int y,int x,int y1,int x1, partie_t *p)
{

   if(deplacement_valide_fou(y,x,y1,x1,p)==0||deplacement_valide_roi(y,x,y1,x1,p)==0)
    	return 0;
   else if(deplacement_valide_fou(y,x,y1,x1,p)==1||deplacement_valide_roi(y,x,y1,x1,p)==1)
    	return 1;
   else if(deplacement_valide_fou(y,x,y1,x1,p)==2||deplacement_valide_roi(y,x,y1,x1,p)==2)
    	return 2;
   else
   return 0;


}

int deplacement_valide_tour_promue(int y,int x,int y1,int x1, partie_t *p)
{


   if(deplacement_valide_tour(y,x,y1,x1,p)==0||deplacement_valide_roi(y,x,y1,x1,p)==0)
	return 0;
   else if(deplacement_valide_tour(y,x,y1,x1,p)==1||deplacement_valide_roi(y,x,y1,x1,p)==1)
	return 1;
   else if(deplacement_valide_tour(y,x,y1,x1,p)==2||deplacement_valide_roi(y,x,y1,x1,p)==2)
        return 2;
   else
   return 0;
}






int deplacement_valide(int x,int y,int x1,int y1, partie_t *p){


piece_t pr=contenu_case(p,x,y);

				/* NON_PROMUE */

	if(piece_charactere(pr)=='p'||piece_charactere(pr)=='P'){

		if(deplacement_valide_pion(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_pion(x,y,x1,y1,p)==1)
			return 1;
	
		if(deplacement_valide_pion(x,y,x1,y1,p)==2){
			return 2;
		}


	}

	if(piece_charactere(pr)=='l'||piece_charactere(pr)=='L'){

		if(deplacement_valide_lance(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_lance(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_lance(x,y,x1,y1,p)==2){
			return 2;
		}

	}


	if(piece_charactere(pr)=='n'||piece_charactere(pr)=='N'){

		if(deplacement_valide_cavalier(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_cavalier(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_cavalier(x,y,x1,y1,p)==2){
			return 2;
		}

	}

	if(piece_charactere(pr)=='s'||piece_charactere(pr)=='S'){

		if(deplacement_valide_general_argent(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_argent(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_general_argent(x,y,x1,y1,p)==2){
			return 2;
		}

	}

	if(piece_charactere(pr)=='g'||piece_charactere(pr)=='G'){

		if(deplacement_valide_general_or(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_or(x,y,x1,y1,p)==1){
			return 1;
		}
		if(deplacement_valide_general_or(x,y,x1,y1,p)==2){
			return 2;
		}

	}

	if(piece_charactere(pr)=='k'||piece_charactere(pr)=='K'){

		if(deplacement_valide_roi(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_roi(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_roi(x,y,x1,y1,p)==2){
			return 2;
		}

	}

	if(piece_charactere(pr)=='b'||piece_charactere(pr)=='B'){

		if(deplacement_valide_fou(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_fou(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_fou(x,y,x1,y1,p)==2){
			return 2;
		}

	}

	if(piece_charactere(pr)=='r'||piece_charactere(pr)=='R'){

		if(deplacement_valide_tour(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_tour(x,y,x1,y1,p)==1){
			return 1;
		}

		if(deplacement_valide_tour(x,y,x1,y1,p)==2){
			return 2;
		}
	}

	
			  	     /* PROMUE */

		if(piece_charactere(pr)=='d'||piece_charactere(pr)=='D'){

		if(deplacement_valide_general_or(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_or(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_general_or(x,y,x1,y1,p)==2){
			return 2;
		}


	}
		if(piece_charactere(pr)=='j'||piece_charactere(pr)=='J'){

		if(deplacement_valide_general_or(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_or(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_general_or(x,y,x1,y1,p)==2){
			return 2;
		}


	}

		if(piece_charactere(pr)=='c'||piece_charactere(pr)=='C'){

		if(deplacement_valide_general_or(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_or(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_general_or(x,y,x1,y1,p)==2){
			return 2;
		}


	}

		if(piece_charactere(pr)=='f'||piece_charactere(pr)=='F'){

		if(deplacement_valide_fou_promue(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_fou_promue(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_fou_promue(x,y,x1,y1,p)==2){
			return 2;
		}


	}
		
		if(piece_charactere(pr)=='t'||piece_charactere(pr)=='T'){

		if(deplacement_valide_tour_promue(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_tour_promue(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_tour_promue(x,y,x1,y1,p)==2){
			return 2;
		}


	}

		if(piece_charactere(pr)=='a'||piece_charactere(pr)=='A'){

		if(deplacement_valide_general_or(x,y,x1,y1,p)==0)
			return 0;

		if(deplacement_valide_general_or(x,y,x1,y1,p)==1)
			return 1;
		
		if(deplacement_valide_general_or(x,y,x1,y1,p)==2){
			return 2;
		}


	}


return 0;

}
/*
piece_t promotion_piece(partie_t *p,int x, int x1,int y, int y1){
	int i,t;
	printf("Pour promover la piece tappez 1, sinon tappez 0");
	scanf("%d",&i);

	while(i<0||i>1)
	{
	printf("Choix Invalide");
	}
		if(i==1){
		if(p->joueur==0){
			t=piece_charactere(contenu_case(p,x,y));
			if (t=='P')
				return piece_creer(0,promue,'D');
		else
			if (t=='L')
				return piece_creer(0,promue,'J');
		else
			if (t=='N')
				return piece_creer(0,promue,'C');
		else
			if (t=='B')
				return piece_creer(0,promue,'F');
		else
			if (t=='R')
				return piece_creer(0,promue,'T');
		else
			if (t=='S')
				return piece_creer(0,promue,'A');
	}

		if(p->joueur==1){
			t=piece_charactere(contenu_case(p,x,y));
			if (t=='p')
				return piece_creer(1,promue,'d');
		else
			if (t=='l')
				return piece_creer(1,promue,'j');
		else
			if (t=='n')
				return piece_creer(1,promue,'c');
		else
			if (t=='b')
				return piece_creer(1,promue,'f');
		else
			if (t=='r')
				return piece_creer(1,promue,'t');
		else
			if (t=='s')
				return piece_creer(1,promue,'a');
	}
}

		else 
				return contenu_case(p,x1,y1);


}
*/


