//funciones de combate
#include <stdio.h>
#include <time.h>
#include "statsglobals.h"
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>

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

void printEstrEN(estrEN){ //Printat de les estrategies del enemic

//Estrategies: Atac 1 , Defensa 2 , Engany 3 , Maniobra 4

switch(estrEN){
	case 1:
		mvprintw(11,0,"| L'enemic ataca!                ");
		mvprintw(12,0,"|                                           ");	
		refresh(); getch();
	break;
	
	case 2:
		mvprintw(11,0,"| L'enemic s'ha defensat..       ");	
		mvprintw(12,0,"|                                            ");
		refresh(); getch();
	break;
	
	case 3:
		mvprintw(11,0,"| L'enemic t'intenta enganyar ~~       ");	
		mvprintw(12,0,"|                                             ");
		refresh(); getch();
	break;
	
	case 4:
		mvprintw(11,0,"| L'enemic realitza una maniobra innesperada!     ");
		mvprintw(12,0,"|                                              ");
		refresh(); getch();
	break;
}
	
}

int ronda(int estrPJ, int estrEN){ //Calcul del resultat de cada ronda, depenent de la estrategia del juegador i del enemic(random)
									//Retorna el resultat de cada ronda	
 
 //Estrategies: Atac 1 , Defensa 2 , Engany 3 , Maniobra 4
 
 //Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
 //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
 //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333                  
    
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

void printResultat(int resultatRonda){ //Funció que interpreta el resultat de cada ronda i en fa un print, el parametre es una 
										//variable pont per printar el resultat de cada ronda
	
	//Resultats jugador:   Danyat 1, Guarit 2, Penalitzat 3, Jug: Danyat x2 4,
    //Resultats enemic:    Danyat 11, Guarit 22, Penalitzat 33, Adv: Danyat x2 44,
    //Resultats combinats: Jug i Adv: Danyat 111, Jug i Adv: Guarit 222, Jug i Adv: Penalitzat 333
	
	switch(resultatRonda){
			//Resultats jugador:
			case 1:
				mvprintw(11,0,"| Jugador danyat                             ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 2:
				mvprintw(11,0,"| Jugador guarit                               ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 3:
				mvprintw(11,0,"| Jugador penalitzat                           ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 4: 
				mvprintw(11,0,"| Jugador danyat x2                            ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
				
			//Resultats enemic:
			case 11:
				mvprintw(11,0,"| Enemic danyat                                ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 22: 
				mvprintw(11,0,"| Enemic guarit                                ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 33: 
				mvprintw(11,0,"| Enemic penalitzat                            ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 44:
				mvprintw(11,0,"| Enemic danyat x2                             ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			//Resultats combinats:
			case 111:
				mvprintw(11,0,"| Jugador i enemic danyats                     ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 222:
				mvprintw(11,0,"| Jugador i adversari guarits                  ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
			case 333: 
				mvprintw(11,0,"| Jugador i adversari Penalitzats                    ");break;
				mvprintw(12,0,"| 	 										");
				refresh(); getch();	
	}
	
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

void ficheroPJ(){ //Funció que encara cal implementar, permetrà guardar la partida i continuarla a partir del començament d'una batalla

 fich = fopen("personaje1.txt", "a+"); /*crear fichero con el nombre del personaje 1,2,3*/
 fprintf(fich,"%d,%d,%d,%d,%d,%d,%d",jugador[0].punts,jugador[0].pVida,jugador[0].pVidaMax,jugador[0].atac,jugador[0].pAtacMax,jugador[0].defensa,jugador[0].pDefMax);
 

}

void leerFicheroPJ(){ //Leemos el fichero personajeX.X y lo copiamos en la posicion X de la struct jugador
	
	

}

void copiarStructEnemicTemporal(int enemic){ //Copiamos la struct del enemigo elegido en nuestra struct temporal
											  
	
 strcpy(temporal[0].nom,enemics[enemic].nom);
		temporal[0].nivell   = enemics[enemic].nivell;
		temporal[0].punts    = enemics[enemic].punts;
		temporal[0].pVida    = enemics[enemic].pVida ;
		temporal[0].pVidaMax = enemics[enemic].pVidaMax;
		temporal[0].atac     = enemics[enemic].atac;
		temporal[0].pAtacMax = enemics[enemic].pAtacMax;
		temporal[0].defensa  = enemics[enemic].defensa;
		temporal[0].pDefMax  = enemics[enemic].pDefMax;
}

void cuadroBase(){ //Función que dibuja el cuadrado base

	//Printado del cuadro base	
	mvprintw(0,0, "+----------------------------------------------------+\n");
	mvprintw(1,0, "|                                                    |\n");
	mvprintw(2,0, "|                                                    |\n");
	mvprintw(3,0, "|                                                    |\n");
	mvprintw(4,0, "|                                                    |\n");
	mvprintw(5,0, "|                                                    |\n");
	mvprintw(6,0, "|                                                    |\n");
	mvprintw(7,0, "|                                                    |\n");
	mvprintw(8,0, "|                                                    |\n");
	mvprintw(9,0, "|                                                    |\n");
	mvprintw(10,0,"+----------------------------------------------------+\n");
	refresh();

}

int main(){
	
	bool endCombat = false;
	int rondaS = 1, choose, initFix = 1,estrPJ,estrEN,enemicEscollit,iniciRonda = 1,resultatRonda,grauExit,initAnim = 1;
	//int initAnim = 1;
	
	initscr(); //Inicializamos la ventana en modo ncurses;
    //La estructura básica de ncurses se basa en el uso del modulo: <sentencias a ejecutar> getch();refresh(); 
    
   //El juego se compone de 10 rondas con sus correspondientes combates, en los cuales el jugador deberá dejar la salud del enemigo a 0
	while(rondaS < 11){

		while (endCombat != true){
			
			//Printado del cuadro base	
			cuadroBase();
			
			while(initAnim == 1){
			mvprintw(1,1,"Aquest es un joc de rol creat per");
			mvprintw(2,1,"Justin Rios i Victor Collado");
			mvprintw(3,1,"Les normes son sencilles, hauràs de lluitar ");
			mvprintw(4,1,"en 10 combats tot escribint el nom d'un enemic");
			mvprintw(5,1,"al començament de cadascun d'aquests, si falles");
			mvprintw(6,1,"un enemic aleatori del teu poder apareixerà.");
			mvprintw(7,1,"Seràs capaç d'arribar fins al final?");
			
			refresh(); getch();
			cuadroBase();
			
			mvprintw(1,1,"QUE COMENCI LA BATALLA!!");
			refresh(); getch();
			initAnim = 0;
			}
			cuadroBase();
			
			if(initFix == 1){ //Arreglo para el marco izquierdo al iniciar el programa
				mvprintw(12,0,"|                                                    |");
				initFix = 0;
			}
			
			enemicEscollit = eleccioEnemicManual();
			if( (enemicEscollit > 0) && (enemicEscollit <= 10) )
			iniciRonda = 1;
			
			if (enemicEscollit == -1){
				enemicEscollit = eleccioEnemicRand(jugador[0].nivell);
				iniciRonda = 1;
			}
			
			copiarStructEnemicTemporal(enemicEscollit);
			
			while(iniciRonda == 1)  {
				//printat dels estats del monstre per pantalla
				mvprintw(1,1," Combat %d/10",rondaS);
				
				//mvprintw(1,21,"%s",); 
				mvprintw(1,21,"%s LVL %d Vida:%d / %d  ",enemics[enemicEscollit].nom,temporal[0].nivell,temporal[0].pVida,temporal[0].pVidaMax);
				
				mvprintw(9,21,"LVL:%d Vida:%d / %d ",jugador[0].nivell, jugador[0].pVida, jugador[0].pVidaMax);
				
				move(11,29);
				refresh(); getch(); 
				
				mvprintw(12,0,"| 1.Atacar|2.Defensa|3.Engany|4.Maniobra|   ");
				mvprintw(11,0,"| Que vols fer?                                ");
				mvscanw(11,16,"%d", &estrPJ);
				refresh();
				estrEN = estrategiaEnemic();
				printEstrEN(estrEN);
				resultatRonda = ronda(estrPJ,estrEN);
				grauExit = calculGrauExit(estrEN,estrPJ);
				
				
				/*mvprintw(11,0,"| Resultats del combat:              ");
				mvprintw(12,0,"| EstrEN: %d, res ronda: %d GExit: %d         ",estrEN, resultatRonda, grauExit);
				getch();*/ //Este getch debe ser quitado, ya que muestra información de tiempo de ejecución, solo se usará para controlar los 
						 //valores parametrizados
				refresh();
				
				modificadorStatFinalRonda(grauExit,resultatRonda);
				choose = 1;
				printResultat(resultatRonda);
				
				/*!arreglo de estilo*/
				if(choose == 1)
					mvprintw(12,0,"|                                                    |");
				
				if(temporal[0].pVida <= 0){
					if(temporal[0].pVida < 0)//Fix per a mostrar 0 quan l'enemic es derrotat
						temporal[0].pVida = 0;
					mvprintw(1,21,"%s LVL %d Vida:%d / %d  ",enemics[enemicEscollit].nom,temporal[0].nivell,temporal[0].pVida,temporal[0].pVidaMax);
					mvprintw(12,0,"| Has guanyat el combat! ");
					getch(); refresh();
					iniciRonda = 0;
					//Añadir funcion que gestiona los puntos de experiencia
				}	
				
				if(jugador[0].pVida <= 0){ //condicion para cuando el jugador se quede sin puntos de vida
					
					mvprintw(12,0,"| Has mort,           ");
					mvprintw(11,0,"| Fi de la partida                 ");
					getch();
					refresh();
					iniciRonda = 0;
					endCombat = true;
				}
			}
			//Ronda ++ implica empezar otro combate
			rondaS++;
			cuadroBase();
			endwin();
			if(rondaS == 11){
				endCombat = true;
				return 0;
			}
		}
}
return 0;
}

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
