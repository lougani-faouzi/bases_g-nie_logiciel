#include "queens.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* check_same_diagonal: return vrai si les reines (c0, r0) et (c1, r1) sont dans le
 * même diagonale. */
static bool check_same_diagonal(const int c0, const int r0,const int c1, const int r1) {
  
  //2 reines sont deux une meme diagonale si l'expression suivante est vérifiée   
  if((c1-c0==r1-r0)||(c0-c1==r0-r1))
  return true;
  else
  return false;
  
  assert((c1-c0==r1-r0)||(c0-c1==r0-r1));
  
}

/* check_column_ok: renvoie true ssi le placement (c, r) est ok avec toutes les reines
 * à gauche de la colonne c déjà placée dans queen_row.
 * condition préalable: queen_row doit être au moins de taille c. */
 
static bool check_column_ok(const int c, const int r, const int queen_row[]) {
   
	int i;
   	bool t=false;
   	for(i=1;i<=c;i++) 
   	{   if(queen_row[c-i]==r)
   	        t=true;
   	}
   	if (t==false)
   	return true;
   	else return false;
   	  
}

/* find_available: renvoie une ligne disponible supérieure à min.
 * Si aucune ligne n'est trouvée, renvoie -1 */

static int find_available(const int min, const int n, const bool available[]){
   int i; 
   
     for(i=0;i<n;i++)
     {
     if(i>min){
     if((available[i]==true))
         return i;
     else 
         return -1;  
         }  
         
    }
 
    
}


 /*_find_solution:solution aux problèmes des n-reines en remplissant
 * colonnes de c à n.
 * queen_row contient les positions de ligne pour les colonnes inférieures à c.
 * available contient les lignes disponibles pour remplir les colonnes supérieures ou égales à c.
 */

static bool _find_solution(const int n, const int c, int queen_row[],bool available[])
{
  int i,a=0;
    for(i=c;i<n;i++)
    {
    
    if(check_column_ok(i,queen_row[i],queen_row)==true && (check_same_diagonal(i,queen_row[i],i+1,queen_row[i+1])!=true))
       {
    	queen_row[i]=find_available(i,n,available);
    	available[i]="false";
    	a=1;
    	printf("%d\n",queen_row[i]);
       }
 
    }
    if(a==1)
           return true;
           else
           return false;	
}

/* find_solution: renvoie true ssi une solution n-reines est trouvée.
 * queens_row est un tableau int de taille n qui sera
 * écrasé par la solution.
 *
 * si une solution est trouvée, queens_row [c] contiendra le numéro de ligne pour la reine
 * à la colonne c.
 * */


bool find_solution(const int n, int queen_row[]) {
  bool available[n];
  for (int i = 0; i < n; i++) {
    available[i] = true;
  }
  return _find_solution(n,0,queen_row,available);
}
