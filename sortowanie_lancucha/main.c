//
//  main.c
//  sortowanie_lancucha
//
//  Created by Jakub Chojnacki on 05/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define ROZMIAR 80                  //max dlugosc lancucha wraz z \0
#define GRAN 20                 // max liczba wierszy

char *load(char *string, int length);                   // prot wczytywania lancuchow
void srtlan(char *lancuchy[], int num);                     // prot. sortowania

int main(int argc, const char * argv[]) {
    
    char dane[GRAN][ROZMIAR];
    char *wsk_lan[GRAN];
    int licz = 0;
    int k;
    printf("podaj maksymalnie %d wieszy a ja je uporzadkuje", GRAN);
    puts("aby zakonczyc nacisnij ENTER w nowym wierszu");
    
    while(licz < GRAN && load(dane[licz], ROZMIAR) && dane[licz][0] != 0x0)
    {
        wsk_lan[licz] = dane[licz];             // przypisz kazdemu wskaznikowi lancuch
        licz++;
    }
    
    srtlan(wsk_lan, licz);                          // zacznij sortowanie WSKAZNIKOW
    puts("\nuporzadkowana lista:\n");
    for(k = 0; k < licz; k++)                           // wypisz sortowanie
        puts(wsk_lan[k]);
    
    return 0;
}

/* ---------------------------------------------- */

void srtlan(char *lancuchy[], int num)                          // funkcja sortujaca ASCII alfabetycznie (wskazniki)
{
    
    char *temp;
    int dol, szuk;
    
    for(dol = 0; dol < num - 1; dol++)
        for(szuk = dol + 1; szuk < num; szuk++)
            if(strcmp(lancuchy[dol], lancuchy[szuk]) > 0)       // wynik > 0 oznacza, ze znak w lancuchu 1 wyprzedza znak w lancuchu 2 (ASCII)
            {                                                       // znaki znajdujace sie na tych samych pozycjach w lancuchach
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }
}

/* ---------------------------------------------- */

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
