//
//  main.c
//  strchr_find_sign
//
//  Created by Jakub Chojnacki on 13/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define GRANICA 80

void Duze_Litery(char *);                       // zamieniamy na duze litery
int Licz_inter(const char *);                     // zliczamy interpunkcje


int main(int argc, const char * argv[]) {
    
    char wiersz[GRANICA];
    char *found;
    puts("podaj wiersz");
    fgets(wiersz, GRANICA, stdin);
    
    found = strchr(wiersz, 0x0a);               // strchr zwraca wskaznik do miejsca w ktorym znajduje sie znak nowej linii
    if(found)                                   // jezeli wskaznik != null
        *found = 0x0;                                // zamien na znak zerowy
    Duze_Litery(wiersz);
    printf("wpisany wiersz zawiera %d znakow interpunkcyjnych\n",Licz_inter(wiersz) );
    puts(wiersz);
    
    return 0;
}
void Duze_Litery(char *lan)
{
    while(*lan)                         // jezeli rozne od znaku zerowego
    {
        *lan = toupper(*lan);
        lan++;
    }
    
}

int Licz_inter(const char *lan )
{
    int licz = 0;
    
    while(*lan)
    {
        if( ispunct(*lan) )                     // jezeli jest znakiem interp. licz + 1
            licz++;
        lan++;;
    }
    
    return licz;
    
}
