//
//  main.c
//  strcmp_dim2
//
//  Created by Jakub Chojnacki on 04/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define GRAN 100
#define ROZMIAR 81
#define KONIEC "koniec"                 // komenda do zakonczenia wczytywania

char *load(char *string, int length);

int main(int argc, const char * argv[]) {
    
    char wejscie[GRAN][ROZMIAR];
    int licznik = 0;
    
    printf("wpisz maksymalnie %d wierszy, wpisanie \"koniec\" zakonczy wczytywanie\n", GRAN);
    
    while(load(wejscie[licznik], ROZMIAR) != NULL && licznik < GRAN &&  // wpisaujemy az do osiaganiecia ktoregos z warunkow
          strcmp(wejscie[licznik], KONIEC) != 0 )                               // jezeli wpiszemy koniec - to program zostanie przerwany
    {
        licznik ++;
    }
    
    printf("podano %d lancuchow", licznik);
    putchar(0x0a);
    
    return 0;
}

char *load(char *string, int length)
{
    char *wynik;
    int i = 0;
    
    wynik = fgets(string, length, stdin);
    if(wynik)                                   // wynik rozny od NULL
    {
        while( string[i] !=0x0a && string[i] != '\0' )
            i++;
        if( string[i] == 0x0a )
            string[i] = '\0';
        else                                // string[i] == '\0'
            while( getchar() != 0x0a )          // pomijaj dalszy ciag lancucha
                continue;
    }
    
    return wynik;
}
