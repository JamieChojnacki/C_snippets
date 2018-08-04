//
//  main.c
//  strcmp_porownanie_lancuchow
//
//  Created by Jakub Chojnacki on 04/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 40
#define ODPOWIEDZ "GRANT"

char *load(char *string, int length);

int main(int argc, const char * argv[]) {
    
    char proba[MAX];
    puts("kto jest pochowany w grobowcu granta?");
    load(proba, MAX);
    
    while(strcmp(proba, ODPOWIEDZ) != 0)                                // jezeli jest 0 to lancuchy maja taka sama zawartosc !
    {
        puts("zla odpowiedz!");                     // sprobuj jeszcze raz jezeli podales zla odpowiedz
        load(proba, MAX);
    }
    puts("brawo !");
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
        {
            string[i] = toupper(string[i]);                         // zamieniamy wszystko na duze litery
            i++;
        }
        if( string[i] == 0x0a )
            string[i] = '\0';
        else                                // string[i] == '\0'
            while( getchar() != 0x0a )          // pomijaj dalszy ciag lancucha
                continue;
    }
    
    return wynik;
}
