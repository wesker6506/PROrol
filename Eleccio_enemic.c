#include <stdio.h>
#include <time.h>
#include "statsglobals.h"
#include <stdbool.h>
#include <string.h>

int eleccioEnemicManual(){
	int i;
	int opcio;
	char nom[20];
	printf("introdueix el nom del monstre\n");//el mensaje esta suejeto a cambios
	scanf("%s",nom);
	char enter;
	scanf("%c",&enter);
	for(i=0;i<10 ;++i){
		if (strcasecmp(nom , personatges[i].nom)==0){
			printf("has escollit %s\n ",personatges[i].nom);
			return opcio=i;
		}
		opcio=-1;//devuelve este valor si el nombre no se ha encontrado
		
	}
    return opcio;
}
 int main(){
	 int num;
	 //esto seria la parte del codigo fuente donde escogemos el monstruo. s
	num=eleccioEnemicManual();
	if(num==-1){
		//en esta linea se llama a  eleccion_aleatoria
		printf("Valor no valid");
	}
		else{
			printf("%d",num);
			
		}
	}




