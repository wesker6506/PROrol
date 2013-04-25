#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include "statsglobals.h"
#include "combat.h"
#include "GUI.h"
#include "modificador.h"
//#include "modificador.h"
//sudo apt-get install libncurses5-dev libncursesw5-dev
//per construir cambiar la instruccio afegint la seguent opcio
//build:  -lncurses

int main(){
	
	bool endCombat = false;
	int rondaS = 1, choose, initFix = 1,estrPJ,estrEN,enemicEscollit,iniciRonda = 1,resultatRonda,grauExit,initAnim = 1,idJugador = 0;
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
				
				//Añadir excepcion para grauExit = 0
				/*if(grauExit == 0){
				mvprintw(11,0,"| Un dels dos ha esquivat l'atac              ");
				mvprintw(12,0,"|                                             ",estrEN, resultatRonda, grauExit);
				}
				getch();refresh();
				*/
				
				mvprintw(11,0,"| Resultats del combat:                       ");
				mvprintw(12,0,"| EstrEN: %d, res ronda: %d GExit: %d         ",estrEN, resultatRonda, grauExit);
				getch(); //Este getch debe ser quitado, ya que muestra información de tiempo de ejecución, solo se usará para controlar los 
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
					modificadorExperiencia(enemicEscollit,idJugador);
					jugador[0].pVida = jugador[0].pVidaMax;
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
