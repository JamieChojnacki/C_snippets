//
//  main.c
//  pobieranie scanf
//
//  Created by Jakub Chojnacki on 14/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int funkcja (int mux);                                 //prototyp funkcji do mnozenia

unsigned int wartosc=2;
int mux;
int ile;

int main(int argc, const char * argv[]) {
    
    char stan;                                          //pobieranie wartosci true or false
    
    printf("ile razy ma sie wykonac mnozenie? \n");
    stan = scanf("%d", &ile);
    
    while (stan == 1)
   {
    funkcja(ile);
       printf("wartosc obecnie to : %u \n", wartosc);
       stan = scanf("%d", &ile);                        //sprawdz czy podano liczbe
    }
    
    printf("wartosc wynosi : %u \n", wartosc);          //wynik mnozenia
    
    return 0;
}

            
int funkcja (int mux)
{
    while(mux > 0){                                       //wykonujemy mnozenie
        
    wartosc = wartosc * wartosc;
        
        mux--;
    }
    return wartosc;                                         //zwroc wartosc do main
}
