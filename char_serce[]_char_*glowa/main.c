//
//  main.c
//  char_serce[]_char_*glowa
//
//  Created by Jakub Chojnacki on 05/02/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    char serce[] = "Kocham Hanie";                                          // zainicjalizowana tablica = kopia lancucha
    char *glowa = "Kocham Manie";                                               // wskazanie na lancuch stworzony na etapie konsolidacji
    
    // wypiszemy pierwsze 6 znakow
    for(int i = 0; i < 6; i++)
        putchar( *(serce + i) );
    putchar(0x0a);
    for(int i = 0; i < 6; i++)
        putchar( *(glowa + i) );
    putchar(0x0a);
    
    // sposob wywolania tylko dla postaci wskaznika :
    
    while(*(glowa) != '\0')                                         // zatrzymaj na koncu lancucha
        putchar( *(glowa++) );                                          // wyswietl znak, zwieksz znak
    
    putchar(0x0a);
    
    // teraz roznica w rozmiarze ! :
    
    printf("rozmiar serce : %zd\n", sizeof( serce) );                   // rozmiar to 13 slow czyli 13 bajtow
    printf("rozmiar glowa : %zd\n", sizeof( glowa) );                       // rozmiar to jeden wskaznik typu char czyli 8 bajtow
    
    // do wyswietlania lancucha uzywaj tylko wskaznikow ! jezeli natomiast chcesz modyfikowac znak, to tablica
    
    return 0;
}

    // serce == &serce[0]
        // serce[0] == *serce == 'K'
            // serce moze zostac zmodyfikowane np serce[7] = H
                // glowa nie moze zostac zmodyfikowana, poniewaz przechowuje adres
