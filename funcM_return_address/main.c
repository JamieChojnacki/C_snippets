//
//  main.c
//  funcM_return_address
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include "assignMemory.h"

int main(int argc, const char * argv[]) {
   
    int *wt;
    int rozmiar;
    int wartosc;
    puts("podaj liczbe elementow :");
    
    while(scanf("%d", &rozmiar) == 1 && rozmiar > 0)
    {
        puts("podaj wartosc poczatkowa ");
        scanf("%d", &wartosc);
        wt = stworz_tablice(rozmiar, wartosc);
        if(wt)
        {
            pokaz_tablice(wt,rozmiar);
            free(wt);
        }
        puts("podaj liczbe elementow (< 1 - koniec )");
    }
    puts("koniec");
    
    return 0;
}
