//
//  main.c
//  for_$
//
//  Created by Jakub Chojnacki on 29/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

void dolar(void);           // funkcja dolar $$$$
void znaki(void);           // funkcja znaki ABCD...
void znak_minus_jeden(void);

int main(int argc, const char * argv[]) {
    
    //dolar();                       // wywolaj funkcje dolar
    //puts("\n");
    
    //znaki();                         // wywolaj funkcje znaki
   // puts("\n");
    
    znak_minus_jeden();                // wywolaj funkcje znaki
    puts("\n");
    
    return 0;
}                                                       // koniec main

void dolar(void)
{                                                       // poczatek funkcji dolar
    int value = 6;
    int rzad, kolumna;
    
    for (rzad = 0; rzad < value; rzad ++)      // funkcja wykonujaca 6 iteracji
    {                                                    //
        for (kolumna = 0; kolumna < rzad ; kolumna ++)   // rzad rosnie o jeden co kazda iteracja
       {
        printf("$");
        
    }
    printf("\n");
}
}                                                       // koniec funkcji dolar

void znaki(void)                                        // poczatek funkcji znaki
{
    const int value = 9;
    
    int raw;
    char ch;
    for (raw = 0 ; raw < value; raw ++)
    {
        for (ch = 'A'; ch < ('A' + raw); ch ++)         // zacznij od A i nastepnie dodaj wartosc
            printf("%c",ch);                            // wyswietl wartosc
        printf("\n");
    }
    
}                                                       // koniec funkcji znaki


void znak_minus_jeden(void)                             // DOKONCZYC
{                                                       // poczatek funkcji
    const int value = 9;
    
    int raw;
    char ch, letter;
    for (raw = 0 , letter = 'A'; raw < value; raw ++, letter++)
    {
        for (ch = letter; ch < ('B' + raw ); ch++)         // zacznij od A i nastepnie dodaj wartosc
            printf("%c",ch);                            // wyswietl wartosc
        printf("\n");

    }
}                                                       // koniec funkcji


