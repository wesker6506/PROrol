#ifndef _combat_h_
#define _combat_h_
#include "combat.c"

void calculMalRebut();
void calculPenalitador();
void calculGuarit();

int eleccioEnemicManual();//eleccio manual
int eleccioEnemicRand(int jugadorEscollit);//retorna la id de enemic

int ronda();//calcula com es desenvolupa la ronda
//int ronda(int estrPJ, int estrEN)					   //y retorna el resultat d'aquest.
#endif
