//
//  main.c
//  dec_bin_rekurencja
//
//  Created by Jakub Chojnacki on 23/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
void do_binary(unsigned long num);

int main(int argc, const char * argv[]) {
    
    unsigned long liczba;
    printf("podaj liczbe\n");
    while(scanf("%lu",&liczba) ==1 )
    {
        printf("odpowiednik dwojkowy: \n");
        do_binary(liczba);
        putchar('\n');
        printf("podaj liczbe calkowita lub zakoncz program \n");
    }
    
    return 0;
}

void do_binary(unsigned long num)
{
    int conv;
    conv = num % 2;                                         // sprawdzamy czy liczba jest podzielna przez 2, mozliwy wynik to 0 lub 1
    if(num >= 2 )                                           // jezeli po operacji modulo num >= 2 to wywolaj funkcje kolejny raz
        do_binary( num / 2 );                               // funkcja dziala az do momentu kiedy conv ma wartosc 1
    putchar( conv == 0 ? '0' : '1' );                       // rekurencja ma charakter koncowy, dlatego poziomy zostana wywolane od
                                                            // ostatniego do pierwszego, dzieki czemu uzyskamy przeniesienie
                                                            // pierwszego wyniku na sam koniec
}
