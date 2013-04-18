#include <stdio.h>
#include <time.h>
int ronda(){
//int ronda(int estrPJ, int estrEN){
 
    
 //Estrategies: Atac 1 , Defensa 2 , Engany 3 , Maniobra 4
 
 
 //Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
 //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
 //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333                  
    
 int estrPJ,estrEN, resultat,vidaPJ,vidaEN;
 //estrPJ estrategia del jugador
 //estrEN estrategia del 
 
 srand((unsigned)time(NULL) );
 estrEN= rand()%4;
 while (estrEN==0){
	  estrEN= rand()%4;
  }
 printf("\n 1Que estrategia quieres elegir? ");
 scanf("%d",&estrPJ);
 printf("\n estrategia enemic es: %d\n",estrEN);
 switch(estrPJ){
                    case 1:
                    if(estrEN == 1){
						return 111;
						}
                    if(estrEN == 2){return 22;}
                    if(estrEN == 3){return 11;}
                    if(estrEN == 4){return 11;}
                    break;
                    
                    case 2:
                    if(estrEN == 1){return 2;}
                    if(estrEN == 2){return 222;}
                    if(estrEN == 3){return 4;}
                    if(estrEN == 4){return 3;}
                    break;
                    
                    case 3:
                    if(estrEN == 1){return 1;}
                    if(estrEN == 2){return 4;}
                    if(estrEN == 3){return 111;}
                    if(estrEN == 4){return 3;}
                    break;
                    
                    case 4:
                    if(estrEN == 1){return 1;}
                    if(estrEN == 2){return 33;}
                    if(estrEN == 3){return 33;}
                    if(estrEN == 4){return 333;}
                    break;   
    }
    return -1;
}


