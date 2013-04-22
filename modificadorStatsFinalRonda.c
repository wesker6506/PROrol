modificadorStatFinalRonda(int grauExit, int resultatRonda){ //Aquesta funció modificarà la struct temporal amb els stats del enemic i la struc del jugador,
															 //en funció del grau d'èxit i del resultat de la ronda.

switch(resultatRonda){
			//Resultats jugador:
			case 1: //Jugador danyat: Vida de jugador - grau exit
				jugador[0].pVida - grauExit;
			break;
			
			case 2: //Jugador guarit: sense efecte
			break;
			
		case 3: //Jugador penalitzat: Defensa/Vida? de jugador - grau exit
			 
		break;
			
			case 4: //Jugador danyat x2: Vida de jugador - (grau exit)x2 
				jugador[0].pVida - (grauExit)x2 ;
			break;
			
			//Resultats enemic:
			
			case 11: //Enemic danyat: Vida de enemic - grau exit
				temporal[0].pVida - grauExit;
			break;
				
			case 22: //Enemic guarit: Sense efecte 
			break;
				
		case 33: //Enemic penalitzat: Defensa/Vida de jugador - grau exit
				
		break;
				
			case 44: //Enemic Danyat: Vida de enemic - (grau exit)x2
				temporal[0].pVida - (grauExit)x2;
			break;
			
			//Resultats combinats:
			case 111: //Jugador i enemic danyats: Vida jugador i enemic - grau exit
				temporal[0].pVida - (grauExit);
				jugador[0].pVida - (grauExit)x2;
			break;
				
			case 222: //Jugador i adversari guarits: sense efecte
			break;
				
		case 333:  //Jugador i adversari penalitzats: Vida/Defensa? jugador/enemic - grau exit
			
		break;
	}	
}







