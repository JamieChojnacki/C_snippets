//
//  main.c
//  ile_odstepow
//
//  Created by Jakub Chojnacki on 07/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define STOP '#'

int main(int argc, const char * argv[]) {
    
    char znak;                                              // obecny znak
    int ile_odstepow = 0;                                   // ilosc odstepow
    int ile_nowych = 0;                                     // ilosc '\n'
    int ile_znakow = 0;                              // ilosc znakow ktore nie sa literami
    
    
    printf("wpisz zdanie, zakoncz je '#'\n");
    while( (znak = getchar()) != STOP)
    {
        if (isspace(znak))                                  // jezeli znak jest odstepem to odstepy+1
            ile_odstepow++;
        if(znak == 0x0a)                                    // jezeli jest znakiem nowej linii to nowe+1
            ile_nowych++;
        if(!isalpha(znak))                                  // jezeli nie jest litera, to znaki ++
            ile_znakow++;
    }
    printf("odstepy: %d\t nowe linie: %d\t wszystkie znaki: %d\n", ile_odstepow, ile_nowych, ile_znakow);
    return 0;
}
