#include <stdio.h>
#include <ncurses.h>
#include <string.h>
#include <stdbool.h>

int main(){
	
	int vida = 10,vidaMaxima = 30, nivell = 2;
	char monstre[20];
	
	bool endCombat = false;
	int ronda = 1, choose, initFix = 1;
	int estrPJ;
	int initAnim = 1;
	
	initscr(); //Inicializamos la ventana en modo ncurses;
    //La estructura básica de ncurses se basa en el uso del modulo: <sentencias a ejecutar> getch();refresh(); 
    //Animación inicial donde se podrá escribir una pequeña historia acerca del personaje
    
    /*
    if(initAnim = 1){
		cuadroBase();
		move(1,1);
		getch();refresh();
		mvprintw(1,1,"ROAD");
		getch();refresh();
		mvprintw(2,2,"OF");
		getch();refresh();
		mvprintw(3,3,"STRANGERS");
		getch();
		initAnim = 0;
		refresh();
	}*/
    
	while(ronda < 11){

		while (endCombat != true){

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
			
			
			if(initFix == 1){ //Arreglo para el marco izquierdo al iniciar el programa
				mvprintw(12,0,"|                                                    |");
				initFix = 0;
			}
			
			mvprintw(11,29,"                        |");
			mvprintw(11,0,"| Escriu el nom d'un monstre: ");  
			move(11,29);
			refresh();
			
			
			mvprintw(13,0,"+----------------------------------------------------+");
			
			mvscanw(11,29,"%s", monstre); 
			mvprintw(11,29,"                        |"); //limpiando el monstruo escrito antes
			refresh();
			
			/*En este punto se iniciaria el combate en si, cambiar condiciones por la funcion de elecció manual/random
			Ahora mismo, si no se escribe troll, las rondas seguirán avanzando, lo que se debe hacer es añadir las funciones
			de elección random y manual, para que en el caso de que el monstruo introducido no exista, se inicie el combate
			con un monstruo que tenga el mismo nivel, 1 nivel menos o un nivel mas*/
			
			if(strcmp(monstre,"troll")== 0){
				mvprintw(11,0, "| Un troll t'ataca!                                  |");
				//printat dels estats del monstre per pantalla, substituir valors per els de la struct
				mvprintw(1,1," Combat %d/10",ronda);
				mvprintw(1,21,"Estat enemic: LVL:%d Vida: %d/%d",nivell,vida,vidaMaxima);
				move(11,29);
				getch();
				refresh();
				/*!*/
				mvprintw(11,0,"| Que vols fer?                             ");
				mvprintw(12,0,"| [1.Atacar][2.Defensa][3.Engany][4.Maniobra]");
				mvscanw(11,16,"%d", &estrPJ);
					//Aquí finaliza la GUI, donde ahora se deberán añadir las funciones de modificación de daño y 
					//todo esto introducirlo dentro de un bucle RODA, que finalizará cuando el usuario o el enemigo tenga vitalidad =  0
				getch();
				refresh();
				
				choose = 1;
				monstre[0] = '#'; //Elimina l'error de; Si s'introdueix un monstre en una ronda, en la seguent si fem intro entrarà al bucle, ja que
								  // el nom d'aquest estara encara guardat, d'aquesta manera s'arregla l'error
			}
			
			if(choose == 1)
				mvprintw(12,0,"|                                                    |");
			
			//Añadir funciones de combate para cada ronda, el ronda ++ implica empezar otro combate
			ronda++;
			endwin();
			if(ronda == 11){
				endCombat = true;
				return 0;
			}
		}
}

return 0;
}

//

//mvprintw(14,0,"|Quina opcio vols escollir? "); ;
//mvprintw(1,25,"Estat: LVL %d HP%d/%d",nivell,vida,vidaMaxima);


/*
Introdueix el nom del monstre: troll
Has escollit Troll 
Quina estrategia vols escollir? [1.Atacar][2.Defensa][3.Engany][4.Maniobra][5.Aleatoria]
2

Estrategia enemic: Defensa
Jugador i adversari Guarits
El grau d'exit ha estat de: 1 
*/

int cuadroBase(){

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

return 0;
}






