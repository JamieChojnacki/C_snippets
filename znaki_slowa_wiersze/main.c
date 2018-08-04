//
//  main.c
//  znaki_slowa_wiersze
//
//  Created by Jakub Chojnacki on 06/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define STOP '|'

int main(int argc, const char * argv[]) {
    
    bool licz_slowo = false;                                            // flaga == true jezeli znajduje sie w slowie
    char znak;                                                          // biezacy znak
    char poprzedni;                                                     // poprzedni znak
    int ile_wierszy = 0;
    int ile_slow = 0;
    long ile_znakow = 0L;
    
    printf("podaj slowo, jezeli chcesz zakonczyc podaj '|'\n");
    poprzedni = '\n';                                                      // poprzedni znak ustawiami na znak nowego wiersza
    
    while( (znak = getchar()) != STOP)
    {
        ile_znakow++;                                                     // jezeli udalo sie rozpoznac znak to znak++
        
        if(isspace(znak) && !licz_slowo){                                 // jezeli jest spacja i flaga == false to poczatek slowa, ustaw flage na true
            licz_slowo = true;                                            // i slowo ++
            ile_slow++;
        }
        if(isspace(znak) && licz_slowo){                     // jezeli jest spacja i flaga == true to koniec slowa
            licz_slowo = false;
            poprzedni = znak;                                // przypisz pobrany znak zmiennej poprzedni
        }
        if(znak == '\n')                                     // jezeli znak jest nowym wierszem to wiersz++
            ile_wierszy++;
    }
    printf("znaki : %ld \t wiersze : %d \t slowa : %d\n",ile_znakow, ile_wierszy, ile_slow);
    
    return 0;
}
