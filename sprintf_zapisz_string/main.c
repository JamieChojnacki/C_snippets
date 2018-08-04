//
//  main.c
//  sprintf_zapisz_string
//
//  Created by Jakub Chojnacki on 05/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#define MAX 20

char *load(char *string, int length);

int main(int argc, const char * argv[]) {
    
    char imie[MAX];
    char nazwisko[MAX];
    char formal[2*MAX +10];
    double wygrana;
    
    puts("podaj imie");
    load(imie,MAX);
    puts("podaj nazwisko");
    load(nazwisko, MAX);
    puts("podaj wygrana ilosc pieniedzy");
    scanf("%lf", &wygrana);
    sprintf(formal, "%s, %-19s : %6.2f zl", nazwisko, imie, wygrana);   // zapisz dane do lancucha
    puts(formal);                                                           // wypisz powstaly lancuch
    
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

