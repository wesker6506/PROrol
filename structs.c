#include <stdio.h>

void creacioPersonatge(){
     printf("Escull\n 1.Slot 1\n 2.Slot 2\n 3.Slot 3\n");
     int slot;
     do{
        scanf("%d",&slot);
        if(slot==0 || slot>3){
                   printf("torna a introduir un numero\n");
        }
     }while(slot>0 && slot<=3);
      printf("Introdueix nom de personatge\n");
        scanf("%s",personatges[slot].nom);
     }
     
     int main(){
     creacioPersonatge();
     getch();
     return 0;
     }    
     
