//funcionesd e combate
#include <stdio.h>
#include <time.h>
#include "statsglobals.h"
#include <stdbool.h>
#include <string.h>

int ronda( int estrPJ,intestrEN){
 
 
    
 //Estrategies: Atac 1 , Defensa 2 , Engany 3 , Maniobra 4
 
 
 //Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
 //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
 //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333                  
    

 //estrPJ estrategia del jugador
 //estrEN estrategia del enemic
 
 srand((unsigned)time(NULL) );
 estrEN= rand()%4;
 while (estrEN==0){
	  estrEN= rand()%4;
  }
 printf("Quina estrategia quieres elegir? [1.Atacar][2.Defensa][3.Engany][4.Maniobra]\n");
 scanf("%d",&estrPJ);
 printf("\nEstrategia enemic es: %d\n",estrEN);
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
    return -1; //return contemplado para casos de errores
}

int eleccioEnemicManual(){
	int i;
	int enemic;
	char nom[20];
	printf("Introdueix el nom del monstre: ");//el mensaje esta suejeto a cambios
	scanf("%s",nom);
	char enter;
	scanf("%c",&enter);
	for(i=0;i<10 ;++i){
		if (strcasecmp(nom , enemics[i].nom)==0){
			printf("Has escollit %s \n",enemics[i].nom);
			return enemic=i;
		}
		enemic=-1;//devuelve este valor si el nombre no se ha encontrado
		
	}
    return enemic;
}
int eleccioEnemicRand(int jugadorEscollit){
	int nivellJ=personatges[jugadorEscollit].nivell;
	int enemicEscollit;
	srand((unsigned)time(NULL) );
	enemicEscollit=rand()%5;//escollir el nivell
	while(enemicEscollit>nivellJ+1 || enemicEscollit<nivell-1){
		enemicEscollit=rand()%5;
	}
	int diferencia=rand()%2;
	i=0;
	while(i<9){
		
	}
 return enemic


void printResultat(int resultatRonda){ //Funció que interpreta el resultat de cada ronda i en fa un print, el parametre es una 
										//variable pont per printar el resultat de cada ronda
	
	//Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
    //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
    //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333
	
	
	
	switch(resultatRonda){
			//Resultats jugador:
			case 1:
				printf("Jugador Danyat");break;
			case 2:
				printf("Jugador Guarit");break;
			case 3: 
				printf("Jugador Penalitzat"); break;
			case 4: 
				printf("Jugador Danyat x2"); break;
			//Resultats enemic:
			case 11:
				printf("Enemic Danyat"); break;
			case 22: 
				printf("Enemic Guarit"); break;
			case 33: 
				printf("Enemic Penalitzat"); break;
			case 44:
				printf("Enemic Danyat x2"); break;
			//Resultats combinats:
			case 111:
				printf("Jugador i enemic danyats"); break;
			case 222:
				printf("Jugador i adversari Guarits"); break;
			case 333: 
				printf("Jugador i adversari Penalitzat"); break;
	
	}	
	
}


 int main(){
	
	int resultatRonda;
	
	 
	//eleccion de monstruo
	int num=eleccioEnemicManual();
	
	if(num==-1){
		//en esta linea se llama a  eleccion_aleatoria
		printf("Valor no valid");
	}
		else{
			printf("IdEnemic: %d\n",num);
			//ronda();
			
		}
	
	resultatRonda = ronda();
	//printf("Resultat de la ronda es: %d\n",resultatRonda);
	printResultat(resultatRonda); //La funció printResultat llegeix el resultat de cada ronda i en fa un print
	
	return 0;
	
	}


