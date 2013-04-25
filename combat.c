//funciones de combate
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include "GUI.h"
#include "statsglobals.h"

FILE *fich;


int calculGrauExit(estrEN, estrPJ){ //Calcula el grau d'èxit de cada atac prenent com a referencia les estrategies del jugador i l'enemic
									//Retorna el grau d'èxit
									//Caldrá afegir la id del Jugador actiu com a parametre per tal de fer el calcul correcte
	/*
	Estrategia
	Atac: moneda atac
	Engany: moneda atac
	Defensa: moneda defensa 
	Maniobra: moneda defensa
	*/
	
	//Calculant la efectivitat de les estrategies
	
	int randEfecte,grauExit = 0,i;
	int monedes;
	
	
	if( (estrEN == 1) || (estrEN == 3) )
		monedes = temporal[0].atac ; 
	if( (estrEN == 2) || (estrEN == 4) )
		monedes = temporal[0].defensa;
	
	if( (estrPJ == 1) || (estrPJ == 3) )
		monedes = jugador[0].atac;
	if( (estrPJ == 2) || (estrPJ == 4) )
		monedes = jugador[0].defensa;
	
	for ( i = 0 ; i <= monedes ; i ++ ){
		//srand((unsigned)time(NULL) );
		randEfecte = rand()%2;
		if(randEfecte == 1){
			grauExit ++;
		}
	}
		
		
		return grauExit;
	
	return 0;
}

int estrategiaEnemic(){  //Generacio aleatorio de la estrategia del enemic
						 //Retorna la estrategia del enemic
	
	int estrEN;
	
	
	srand((unsigned)time(NULL) );
	estrEN = rand()%4;
	
	while (estrEN==0){
		estrEN= rand()%4;
		estrEN ++;
	}
	return estrEN;
}



int ronda(int estrPJ, int estrEN){ //Calcul del resultat de cada ronda, depenent de la estrategia del juegador i del enemic(random)
									//Retorna el resultat de cada ronda	
 
 //Estrategies: Atac 1 , Defensa 2 , Engany 3 , Maniobra 4
 
 //Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
 //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
 //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333                  
 
 srand((unsigned)time(NULL) );
 
 //Fix per a estrategia aleatoria "tecla Enter"
 if(estrPJ > 4)
  estrPJ = rand()%4;
 if(estrPJ == 0)
  estrPJ + 1;
    
 switch(estrPJ){
                    
                    case 1:
						if(estrEN == 1){return 111;}
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

int eleccioEnemicManual(){ //Elecció manual del enemic, si no es troba, retorna -1( enemic no trobat )
	int i,enemic,choose = 0;
	char nom[20];
	
	mvprintw(11,29,"                        |");
	mvprintw(13,0,"+----------------------------------------------------+");
	mvprintw(11,0,"| Escriu el nom d'un monstre: "); 
	mvprintw(12,0,"|                                            "); 
	mvscanw(11,29,"%s", nom); 
	//mvprintw(11,29,"                        |"); //limpiando el monstruo escrito antes
	refresh();
	
	
	for(i=0;i<10 ;++i){
		if (strcasecmp(nom , enemics[i].nom)==0){
			mvprintw(11,0, "| Un %s t'ataca!                ",enemics[i].nom);
			refresh();
			//move(11,29);
			//getch();
			refresh();
			choose = 1;
			return enemic=i;
		}
		enemic=-1;//devuelve este valor si el nombre no se ha encontrado
	}
	
	if(choose == 1)
		mvprintw(12,0,"|                                                    |");
	refresh();
	
    return enemic;
}

int eleccioEnemicRand(int jugadorEscollit){ //S'escull un enemic aleatori en funció del nivel del jugador
											 //Es retorna l'enemic escollit(int)
	int nivellJ=jugadorEscollit;//jugadorescollit es la id del jugador actual. cambiar per la struct de jugador.
	//esto se puede quitar al final solo es prueba pero va bien que la funcion te diga que ha salido.
	srand((unsigned)time(NULL) );
	int nivellEnem;
	nivellEnem=rand()%5;//escollir el nivell
	if (nivellEnem<1)nivellEnem++;
	
	switch(nivellJ){
		case 1:
		srand((unsigned)time(NULL) );
		nivellEnem=rand()%2;
		if (nivellEnem==0)nivellEnem++;
		break;
		case 2:
		srand((unsigned)time(NULL) );
		while(nivellEnem<1 && nivellEnem>3){
		nivellEnem=rand()%5;
		}
		break;
		case 3:
		srand((unsigned)time(NULL) );
			while(nivellEnem<2 && nivellEnem>4){
		nivellEnem=rand()%5;
		nivellEnem++;
		}
		break;
		case 4:
		srand((unsigned)time(NULL) );
			while(nivellEnem<3){
		nivellEnem=rand()%5;
		nivellEnem++;
		}
		break;
		case 5:
		srand((unsigned)time(NULL) );
		while(nivellEnem<4){
		nivellEnem=rand()%5;
		nivellEnem++;
		}
		break;
	};
		
		//printf("nivell que esta sortint despres switch %d \n",nivellEnem);
	int diferencia=rand()%2;
	 int i=0;//fa de contador y es la ID de enemic escollit final
	 bool trobat=false;
	 int enemicEscollit;
	while(i<=9 && !trobat){
		if (enemics[i].nivell==nivellEnem){
			if(enemics[i].idEnem==diferencia){
				trobat=true;
				enemicEscollit=i;
			}
		}
		i++;
	}
	mvprintw(11,0, "| Un %s t'ataca!                     ",enemics[enemicEscollit].nom);
	refresh();
	
 return enemicEscollit;
}

void modificadorStatFinalRonda(int grauExit, int resultatRonda){ //Aquesta funció modificarà la struct temporal amb els stats del enemic i la struc del jugador,
																  //en funció del grau d'èxit i del resultat de la ronda.

switch(resultatRonda){
			
			//!Resultats jugador:
			
			//Jugador danyat: Vida de jugador - grau exit
			case 1: 
				jugador[0].pVida -= grauExit; 
			break;
			
			//Jugador guarit: 
			case 2:
				jugador[0].pVida += grauExit;
				if(jugador[0].pVida > jugador[0].pVidaMax)
					jugador[0].pVida = jugador[0].pVidaMax;
			break;
			
			//Jugador penalitzat: Defensa/Vida? de jugador - grau exit
			case 3:  
			jugador[0].defensa -= grauExit;
			if(jugador[0].defensa <= 0)
				jugador[0].defensa = 0;
			break;
			
			//Jugador danyat x2: Vida de jugador - (grau exit)x2 
			case 4: 
				jugador[0].pVida -= (grauExit * 2); 
			break;
			
			//!Resultats enemic:
			
			//Enemic danyat: Vida de enemic - grau exit
			case 11: 
				temporal[0].pVida -= grauExit; 
			break;
			
			
			//Enemic guarit: Sense efecte 	
			case 22: 
				temporal[0].pVida += grauExit;
				if(temporal[0].pVida > temporal[0].pVidaMax)
					temporal[0].pVida = temporal[0].pVidaMax;
			break;
			
			//Enemic penalitzat: Defensa - grau exit
			case 33: 
				temporal[0].defensa -= grauExit;
			break;
				
			//Enemic Danyat: Vida de enemic - (grau exit)x2	
			case 44: 
				temporal[0].pVida -= (grauExit * 2);
			break;
			
			//!Resultats combinats:
			
			//Jugador i enemic danyats: Vida jugador i enemic - grauExit
			case 111: 
				temporal[0].pVida -= grauExit; 
				jugador[0].pVida  -= grauExit;
			break;	
			
			//Jugador i adversari guarits 
			case 222: 
			
			jugador[0].pVida += grauExit;
				if(jugador[0].pVida > jugador[0].pVidaMax)
					jugador[0].pVida = jugador[0].pVidaMax;
			
			temporal[0].pVida += grauExit;
				if(temporal[0].pVida > temporal[0].pVidaMax)
					temporal[0].pVida = temporal[0].pVidaMax;
				
			break;
		
		//case 333:  //Jugador i adversari penalitzats: Vida/Defensa? jugador/enemic - grau exit
		//break;
		
	}	
	
}


/*
void ficheroPJ(){ //Funció que encara cal implementar, permetrà guardar la partida i continuarla a partir del començament d'una batalla

 fich = fopen("personaje1.txt", "a+"); crear fichero con el nombre del personaje 1,2,3
 fprintf(fich,"%d,%d,%d,%d,%d,%d,%d",jugador[0].punts,jugador[0].pVida,jugador[0].pVidaMax,jugador[0].atac,jugador[0].pAtacMax,jugador[0].defensa,jugador[0].pDefMax);
 

}


void leerFicheroPJ(){ //Leemos el fichero personajeX.X y lo copiamos en la posicion X de la struct jugador
	
	

}
*/


/*
Comentarios sobre añadidos: 
Preferencia en estrategias de los enemigos ( mucha vida = no defenderse , etc )
Guardado de partida
Objetos
Drop de monstruos
*/
/*
Aún hay errores de salida inesperada de la batalla, jugador y enemigo dañados es un caso 
*/
//Se debe crear la función de inicio de juego, donde se seleccionará el slot de juego y se escribirá el nombre del personaje
