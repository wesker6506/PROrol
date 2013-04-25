#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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
        int exp;/*camp utilitzat per enmagatzemar la experiencia actual del jugador 
					y per guardar la experiencia que dona cada monstre*/
        }entitats;
        

        entitats enemics[10]={
        {"Kobold",1,25,8,8,3,3,3,3,0,500},
        {"Manticora",1,30,10,10,4,4,2,2,1,700},
        {"Orc",2,35,12,12,4,4,3,3,0,830},
        {"Quimera",2,40,14,14,3,3,4,4,1,1000},
        {"Golem",3,45,15,15,3,3,5,5,0,832},
        {"Ogre",3,50,16,16,5,5,2,2,1,1032},
        {"Guerrer del caos",4,55,15,15,4,4,4,4,0,1080},
        {"Troll",4,60,18,18,3,3,5,5,1,1250},
        {"Dullahan",5,70,22,22,4,4,6,6,0,2000},
        {"Hidra",5,80,30,30,8,8,2,2,1,2500}
        };
        
        entitats jugador[3]={
			{"slot 1",1,0,10,10,3,3,3,3,0,0},
			{"slot 2",1,0,10,10,3,3,3,3,0,0},
			{"slot 3",1,0,10,10,3,3,3,3,0,0},
        };
        
        entitats temporal[1] = { //Aqui es copiara els stats que es faran servir en cada ronda
			{"temp",1,0,10,10,3,3,3,3,0,0},
		}; 
//partida nueva: Rescriure el slot escollit de personatge amb els valors base
//continuar: llegir la struct desde un fitxer
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
