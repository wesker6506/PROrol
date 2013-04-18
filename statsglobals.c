#include <stdio.h>
#include <stdbool.h>
//incluir les constants de  stats que no cambian ttak tal y cual///
typedef struct{
        char nom[20];
        int nivell;
        int punts;
        int pVida;
        int pVidaMax;
        int atac;
        int pAtacMax;
        int defensa;
        int pDefMax; 
        int idEnem;//quan escollim enemic aleatori , necesitem un dels dos del mateix nivell
        }entitats;
        entitats enemics[10]={
        {"Kobold",1,25,8,8,3,3,3,3,0},
        {"Manticora",1,30,10,10,4,4,2,2,1},
        {"Orc",2,35,12,12,4,4,3,3,0},
        {"Quimera",2,40,14,14,3,3,4,4,1},
        {"Golem",3,45,15,15,3,3,5,5,0},
        {"Ogre",3,50,16,16,5,5,2,2,1},
        {"Guerrer del caos",4,55,15,15,4,4,4,4,0},
        {"Troll",4,60,18,18,3,3,5,5,1},
        {"Dullahan",5,70,22,22,4,4,6,6,0},
        {"Hidra",5,80,30,30,8,8,2,2,1}
        };
        
        entitats jugador[3]={
			{"slot 1",1,0,10,10,3,3,3,3,0},
			{"slot 2",1,0,10,10,3,3,3,3,0},
			{"slot 3",1,0,10,10,3,3,3,3,0},
        };

//partida nueva: Rescriure el slot escollit de personatge amb els valors base
//continuar: llegir la struct desde un fitxer
