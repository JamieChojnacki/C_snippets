//
//  main.c
//  strncat_konkatenacja_bufor
//
//  Created by Jakub Chojnacki on 01/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

// strncat okresla ile elementow drugiega arguementu ma zostac dopisane do pierwszego lancucha

#include <stdio.h>
#include <string.h>                 // strcat nalezy do biblioteki string

#define s_size 30
#define s_owady 17

char *load(char *string, int length);              // zwraca wskaznik do char(fgets) np NULL

int main(int argc, const char * argv[]) {
    
    char Kwiat[s_size];                                          // lanuch pierwszy
    char dodatek[] = " smierdza jak stare buty";                     // lancuch drugi
    char owady[s_owady];                                                // lancuch do strncat
    int free_space;                                                         // wolna przestrzen w tablicy
    
    puts("jakie kwiaty lubisz najbardziej?");
    load(Kwiat,s_size);
    if ( (strlen(dodatek) + strlen(Kwiat) + 1) <= s_size )             // sprawdzam czy wpisane dane nie przepelnia bufora
        strcat(Kwiat, dodatek);
    puts(Kwiat);

    puts("jakie owady lubisz?");
    load(owady, s_owady);                                           // teraz to samo ale dla strncat
    free_space = s_owady - (strlen(owady) - 1);                             // pamietam o znaku zerowym
        strncat(owady,dodatek,free_space);
    puts(owady);
    
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

