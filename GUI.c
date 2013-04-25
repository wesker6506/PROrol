#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include <stdio.h>
#include <time.h>

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
void printEstrEN(int estrEN){ //Printat de les estrategies del enemic

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
