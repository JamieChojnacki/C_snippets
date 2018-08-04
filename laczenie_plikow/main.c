//
//  main.c
//  laczenie_plikow
//
//  Created by Jakub Chojnacki on 23/11/2017.
//  Copyright © 2017 James. All rights reserved.
//
// glowna funkcja, pobierajaca dane z plikow .h i .c

#include <stdio.h>
#include "funkcje.h"                                // inicjuj biblioteke zawarta w pliku funkcje

int main(int argc, const char * argv[]) {
 
    int noce;
    double hotel;
    int kod;                                        // zmienna operujaca instrukcja switch
    while((kod = menu())!= KONIEC)                  // wywolaj funkcje menu, jezeli zwroci wartosc 5 to koniec
    {
        switch(kod)
        {
            case 1 :
                hotel = HOTEL1;                     // przypisz zmiennej hotel cene za noc rowno 80
                break;
            case 2 :
                hotel = HOTEL2;                     // i tak daleh
                break;
            case 3 :
                hotel = HOTEL3;
                break;
            case 4 :
                hotel = HOTEL4;
                break;
            default:                                // w innym wypadku wartosc za noc rowna 0
                hotel = 0.0;
                printf("ups\n");
                break;
        }
        noce = pobierz_noce();                      // pobierz funkcje ktora zwraca ilosc nocy
        pokaz_cene(hotel, noce);                    // funkcja pobiera ilosc nocy i cene i wyswietla laczny koszt pobytu
        
        
    }
    printf("dziekuje i do widzenia \n");
    return 0;
}
