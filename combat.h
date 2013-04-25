#ifndef _combat_h_
#define _combat_h_
#include "combat.c"

int calculGrauExit(int estrEN, int estrPJ);//Calcula el grau d'èxit de cada atac prenent com a referencia les estrategies del jugador i l'enemic
											//Retorna el grau d'èxit
											//Caldrá afegir la id del Jugador actiu com a parametre per tal de fer el calcul correcte

void ficheroPJ();//Funció que encara cal implementar, permetrà guardar la partida i continuarla a partir del començament d'una batalla
int eleccioEnemicManual();//eleccio manual
int eleccioEnemicRand(int jugadorEscollit);//retorna la id de enemic
int estrategiaEnemic();//Generacio aleatorio de la estrategia del enemic
						 //Retorna la estrategia del enemic
void modificadorStatFinalRonda(int grauExit, int resultatRonda); //Aquesta funció modificarà la struct temporal amb els stats del enemic i la struc del jugador,
																  //en funció del grau d'èxit i del resultat de la ronda.

void leerFicheroPJ(); //Leemos el fichero personajeX.X y lo copiamos en la posicion X de la struct jugador
int ronda();//calcula com es desenvolupa la ronda
//int ronda(int estrPJ, int estrEN)					   //y retorna el resultat d'aquest.
#endif
