//
//  main.c
//  rekurencja
//
//  Created by Jakub Chojnacki on 22/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
void rekurencja(int n);                                                     // UWAGA kazdy nowy poziom rekurencji ma wlasna zmienna n
                                                                            // ktora jest indywidualna dla tego poziomu
                                                                            // n == 1 poziomu 1 ma inny adres niz n == 1 poziomu 2

int main(int argc, const char * argv[]) {
 
    rekurencja(1);                                                          // przekazujemy funkcji argument 1
    return 0;                                                               // nastepnie bedzie ona wywolywala sama siebie gdy n+1
}

void rekurencja(int n)                                                      /*  ! patrz strona 380 Prata !  */
{
    printf("Poziom %d: adres zmiennej n: %p\n", n,&n);                     // argument formalny otrzymuje wartosc 1
    if(n < 4)                                                               // 1 < 4 wiec wywolanie funkcji gora i dol poziom 2
        rekurencja(n+1);                                                    // z argumentem n+1 czyli 2 i tak az do wartosci i poziomu 4
    printf("POZIOM %d: ADRES ZMIENNEJ n: %p\n", n,&n);                     // gdy n == 4 warunek w petli false, return i powrot do poziomu 3,
                                                                            // poniewaz on wywolal poziom 4
}                                                                           // kazdy kolejny poziom zostal wywolany przez poziom nizej, wiec
                                                                            // jest on kolejno wywolywany az do poczatkowego stanu
