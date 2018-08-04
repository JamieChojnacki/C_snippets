//
//  main.c
//  dice_srand_time
//
//  Created by Jakub Chojnacki on 11/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <time.h>                               // potrzebujemy funkcji time
#include <stdlib.h>
#include "geek.h"

int main(int argc, const char * argv[]) {
    int rzuty, wynik;
    int scianki, status;
    
    srand((unsigned int) time(0));                      // losowe ziarno
    puts("podaj liczbe scianek, 0 oznacza koniec");
    while( (scanf("%d", &scianki) == 1) && scianki > 0 )
    {
        puts("ile rzutow ?");
        if((status = scanf("%d", &rzuty)) != 1)
        {
            if(status == EOF)
                break;                                          // przerywamy petle
            else
            {
            puts("nalezy podac liczbe calkowita !");
            puts(" sprobujmy jeszcze raz");
            while(getchar() != 0x0a)                                                    // odrzucenie niepoprawnego wejscia
                continue;
            puts("podaj liczbe scianek, 0 oznacza koniec");
            continue;                                                                           // nowy przebieg petli
            }
        }
        wynik = rzucaj_n_razy(rzuty, scianki);
        printf("wyrzucono razem %d uzywajac %d %d-sciennych kosci.\n", wynik, rzuty, scianki);
        puts("podaj liczbe scianek, 0 oznacza koniec");
        
    }
    printf("funkcja rzucaj() zostala wywolana %d razy.\n", liczba_rzutow);
    
    puts("PEACE !");
    
    return 0;
}
