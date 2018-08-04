//
//  geek.c
//  dice_srand_time
//
//  Created by Jakub Chojnacki on 11/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "geek.h"
#include <stdio.h>
#include <stdlib.h>                         // rand

int liczba_rzutow = 0;

static int rzucaj(int scianki)
{
    int oczka;
    oczka = rand() % scianki + 1;
    ++liczba_rzutow;
    
    return oczka;
}

int rzucaj_n_razy(int rzuty, int scianki)
{
    int k;
    int suma = 0;
    
    if(scianki < 2)
    {
        puts("wymagane sa conamniej 2 scianki");
        return - 2;
    }
    
    if(rzuty < 1)
    {
        puts("wymagany conajmniej 1 rzut");
        return - 1;
    }
    
    for(k = 0; k < rzuty; k++)
        suma += rzucaj(scianki);
    
    return suma;
}
