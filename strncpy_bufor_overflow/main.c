//
//  main.c
//  strcmp_dim2
//
//  Created by Jakub Chojnacki on 04/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define ROZMIAR_CELU 7
#define ROZMIAR 40
#define GRAN 5
#define KONIEC "koniec"                 // komenda do zakonczenia wczytywania

char *load(char *string, int length);

int main(int argc, const char * argv[]) {
    
    char vslowa[GRAN][ROZMIAR_CELU];
    char temp[ROZMIAR];
    int i = 0;
    printf("podaj %d slow zaczynajacych sie na v:\n", GRAN);
    while(i < GRAN && load(temp, ROZMIAR))
    {
        if(temp[0] != 'v')
            printf("%s nie zaczyna sie na \"v\"\n", temp);
        else
        {
            strncpy(vslowa[i], temp, ROZMIAR_CELU - 1);     // trzeci argument okresla max rozmiar kopiowanego lancucha
            vslowa[i][ROZMIAR_CELU - 1] = '\0';
            i++;
        }
    }
    puts("Oto przyjete slowa: ");
    for(int j = 0; j < GRAN; j++)
        puts(vslowa[j]);
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

