//
//  funkcje.c
//  laczenie_plikow
//
//  Created by Jakub Chojnacki on 23/11/2017.
//  Copyright © 2017 James. All rights reserved.
//
// definiowanie funkcji oraz najwazniejsze obliczenia

#include <stdio.h>
#include "funkcje.h"

int menu(void)
{
    int kod, stan;
    printf("\n%s%s\n", GWIAZDKI, GWIAZDKI);
    printf("podaj numer hotelu \n");
    printf("1. Marek Anton              2. Olimpijski");
    printf("3. Marynarz                 4. Savoy");
    printf("5. koniec\n");
    printf("%s%s\n", GWIAZDKI, GWIAZDKI);
    
    while((stan = scanf("%d", &kod)) !=1 || (kod < 1 || kod > 5))       // odpornosc na idiotow zwiekszona
          {
              if(stan != 1)
                  scanf("%*s");                                         // odrzucamy wejscie nieliczbowe
              printf("podaj liczbe od 1 do 5\n");
          }
    return kod;                                                        // zwroc wartosc wpisana przez uzytkownika
}


int pobierz_noce(void)
{
    int noce;
    
    printf("ile nocy bedzie potrzebne ? \n");
    while(scanf("%d", &noce) != 1)                                     // jezeli nie udalo sie pobrac
    {
        scanf("%*s");                                                  // odrzucamy wejscie nieliczbowe
        printf("podaj calkowita \n");
    }
    
    return noce;                                                        // zwroc ilosc nocy
}


void pokaz_cene(double hotel, int noce)
{
    int n;
    double suma = 0.0;
    double przelicznik = 1.0;
    
    for (n = 1; n <= noce ; n++, przelicznik *= RABAT )             // liczy rabat za ilosc nocy  oraz cene
        suma += hotel * przelicznik;
    printf("calkowity koszt pobytu wynosi : %.2f $ \n", suma);

}
