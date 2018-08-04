//
//  main.c
//  strcat_konkatenacja_lancucha
//
//  Created by Jakub Chojnacki on 01/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

// argumenty - 2 lancuchy, kopia drugiega argumentu jest dolaczana do konca pierwszego
// wynik zostaje przypisany do pierwszego lancucha (jest nim adres pierwszego znaku) i jest typu *char

#include <stdio.h>
#include <string.h>                 // strcat nalezy do biblioteki string

#define s_size 80

char *load(char *string, unsigned int length);              // zwraca wskaznik do char(fgets) np NULL

int main(int argc, const char * argv[]) {
    
    char Kwiat[s_size];                                          // lanuch pierwszy
    char dodatek[] = " smierdza jak stare buty";                     // lancuch drugi
    
    puts("jakie kwiaty lubisz najbardziej?");
    
    if( load(Kwiat,s_size) )
    {
        strcat(Kwiat, dodatek);
        puts(Kwiat);
        puts(dodatek);
    }
    
    return 0;
}

char *load(char *string, unsigned int length)
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
