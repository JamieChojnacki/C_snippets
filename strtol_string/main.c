//
//  main.c
//  strtol_string
//
//  Created by Jakub Chojnacki on 14/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 30

char *load(char *string, int length);

int main(int argc, const char * argv[]) {
    
    char liczba[LIMIT];
    char *koniec;
    long wartosc;
    
    puts("podaj liczbe, podaj pusty wiersz by zakonczyc");
    while( load(liczba, LIMIT) && liczba[0] != 0x0)
    {
        wartosc = strtol(liczba, &koniec, 10);          // &koniec zwraca adres do pierwszego znaku po liczbie
        printf("wartosc %ld poprzedza %s (%d)\n",           // np "10atom" to *koniec = 'a', koniec = "atom"
               wartosc, koniec, *koniec);
        
        wartosc = strtol(liczba, &koniec, 16);
        printf("wartosc %ld poprzedza %s (%d)\n",
               wartosc, koniec, *koniec);
    }
    
    return 0;
}

char *load(char *string, int length)
{
    char *wynik;
    int i = 0;
    
    wynik = fgets(string, length, stdin);
    if(wynik)                                   // wynik rozny od NULL
    {
        while( string[i] !=0x0a && string[i] != 0x0 )
            i++;
        if( string[i] == 0x0a )
            string[i] = 0x0;
        else                                // string[i] == '\0'
            while( getchar() != 0x0a )          // pomijaj dalszy ciag lancucha
                continue;
    }
    
    return wynik;
}

