#include <stdio.h>
#include <time.h>
#include "statsglobals.h"
#include <stdbool.h>
#include <string.h>
int eleccioEnemicRand(int jugadorEscollit){
	int nivellJ=jugador[jugadorEscollit].nivell;
	//esto se puede quitar al final solo es prueba pero va bien que la funcion t diga que ha salido.
	srand((unsigned)time(NULL) );
	int nivellEnem;
	nivellEnem=rand()%5;//escollir el nivell
	
	if (nivellEnem<1)nivellEnem++;
	printf("nivell que esta sortint %d \n",nivellEnem);
	switch(nivellJ){
		case 1:
		nivellEnem=rand()%2
		nivellEnem++;
		break;
		case 2:
		while(nivellEnem<1){
		nivellEnem=rand()%5
		nivellEnem++;
		if (nivellEnem>3)
			nivell--;
		}
		case 3:
			while(nivellEnem<2){
		nivellEnem=rand()%5
		nivellEnem++;
		if (nivellEnem>4)
			nivell--;
		}
		break;
		case 4:
			while(nivellEnem<3){
		nivellEnem=rand()%5
		nivellEnem++;
		}
		break;
		case 5:
		while(nivellEnem<4){
		nivellEnem=rand()%5
		nivellEnem++;
		}
		break;
	}
		
		nivellEnem=rand()%5;
		printf("nivell que esta sortint despres while %d \n",nivellEnem);
		if (nivellEnem==0) {
			 nivellEnem++;
		printf("nivell que esta sortint si entro al if %d \n",nivellEnem);
		}
	
	if (nivellEnem==0) nivellEnem++;
	if (nivellEnem==6) nivellEnem--;
	printf("nivell que sortira %d \n",nivellEnem);
	int diferencia=rand()%2;
	 int i=0;//fa de contador y es la ID de enemic escollit final
	 bool trobat=false;
	 int enemicEscollit;
	while(i<=9 && !trobat){
		printf("chivato\n");
		if (enemics[i].nivell==nivellEnem){
			printf("chivato\n");
			if(enemics[i].idEnem==diferencia){
				trobat=true;
				printf("chivato\n");
				enemicEscollit=i;
			}
		}
		i++;
	}
	printf("t'ha tocat: %s amb id: %d\n",enemics[enemicEscollit].nom,enemicEscollit);
 return enemicEscollit;
}
 int main(){
	 int num;
	 printf("introdueix un nivell");
	 scanf("%d",&num);
	 //esto seria la parte del codigo fuente donde escogemos el monstruo. s
	num=eleccioEnemicRand(num);
	if(num==-1){
		//en esta linea se llama a  eleccion_aleatoria
		printf("Valor no valid");
	}
		else{
			printf("holagola %d",num);
			
		}
	}




