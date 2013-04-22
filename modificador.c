#include <stdio.h>
#include <time.h>
#include "statsglobals.h"
#include <stdbool.h>
#include <string.h>
					 
				  //{monstre=exp}
/*	nivel-5=20000{Dullahan=1000,hidra=1250}
	nivell-4=10000{guerrer caos=590, troll=625
	nivell-3=5000{golem=416, ogre=512}
	nivell-2=2500{orc=313 , quimera=500)
	nivell-1=1250{kobold=250 ,manticora=400}
	*/

int modificadorExperiencia(int resultat , int idEnemic,int idJugador ){//retorna 1 si s'ha pujat de lvl 0 si no -1 si error
	int expActual;
	int nivellActu;
	const int n1=1250;
	const int n2=2500;
	const int n3=5000;
	const int n4=10000;
	int pujada=0;
	expActual=jugador[idJugador].exp;//cambiar per fer probes
	nivellActu=jugador[idJugador].nivell;
	switch(nivellActu){
		case 1:
			expActual=expActual+enemics[idEnemic].exp;
			if (expActual>n1){
				nivellActu++;
				jugador[idJugador].exp=0;
				pujada=1;
			}
			else{
				jugador[idJugador].exp=expActual;
			}
			return pujada;
			break;
		case 2:
			expActual=expActual+enemics[idEnemic].exp;
			if (expActual>n2){
				nivellActu++;
				jugador[idJugador].exp=0;
				pujada=1;
			}
			else{
				jugador[idJugador].exp=expActual;
			}
			return pujada;
			break;
		case 3:
			expActual=expActual+enemics[idEnemic].exp;
			if (expActual>n3){
				nivellActu++;
				jugador[idJugador].exp=0;
				pujada=1;
			}
			else{
				jugador[idJugador].exp=expActual;
			}
			return pujada;
			break;
		case 4:
			expActual=expActual+enemics[idEnemic].exp;
			if (expActual>n4){
				nivellActu++;
				jugador[idJugador].exp=0;
				pujada=1;
			}
			else{
				jugador[idJugador].exp=expActual;
			}
			return pujada;
			break;
		case 5://podria no poner nada para el lvl 5 pero no se si poner un mensajito que diga que estas a lvl max k no ganaras mas exp o ke
			return pujada;
			break;
		
	}
	pujada=-1;
	return pujada;
}
