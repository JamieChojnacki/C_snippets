//
//  main.c
//  fseek_ftell
//
//  Created by Jakub Chojnacki on 25/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define COM_D '\032'                               // EOF w plikach textowych mac command+d
#define DLAN 81

int main(int argc, const char * argv[]) {
 
    char file[DLAN];
    char character;
    FILE *pSource;
    long counter, end;
    
    puts("podaj nazwe pliku :");
    scanf("%80s", file);
    
    /* proba otworzenia pliku */
    if((pSource = fopen(file, "rb")) == NULL)               // tryb tylko do odczytu
    {
        printf("Nie mozna otworzyc pliku %s\n", file);
        exit(EXIT_FAILURE);
    }
    
    /* orientacja pliku */
    fseek(pSource, 0L, SEEK_END);                                // przechodzimy do konca pliku
    end = ftell(pSource);                                           // biezace polozenie w pliku
    
    /* odczyt pliku */
    for(counter = 0; counter <= end; counter++)
    {
        fseek(pSource, -counter, SEEK_END);                             // idz do tylu
        character = getc(pSource);
        if(character != COM_D && character != '\r')
            putchar(character);
    }
    putchar(0x0a);
    fclose(pSource);
    
    return 0;
}
