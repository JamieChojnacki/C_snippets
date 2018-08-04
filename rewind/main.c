//
//  main.c
//  rewind
//
//  Created by Jakub Chojnacki on 23/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(int argc, const char * argv[]) {
    
    FILE *pSource;
    char signs[MAX];
    
    /* otwieramy plik do odczytu i zapisu */
    if( (pSource = fopen("source", "a+")) == NULL)
    {
        fprintf(stdin, "Nie udalo sie otworzyc pliku \"slowka\"\n");
        exit(EXIT_FAILURE);
    }
    puts("podaj slowa ktore maja zostac dodane do pliku");
    puts("aby zakonczyc wpisz #.");
    
    /* wpisujemy slowa ktore maja zostac dodane do pliku */
    while((fscanf(stdin, "%40s",signs) == 1) && (signs[0] != '#'))
        fprintf(pSource, "%s", signs);
    
    /* wyswietlamy zawartosc pliku */
    puts("zawartosc pliku :");
    rewind(pSource);                        // przejdz do poczatku pliku
    
    while( fscanf(pSource,"%s", signs) == 1)
        puts(signs);
    puts("gotowe");
    
    /* sprawdzanie czy udalo sie zamknac plik */
    if(fclose(pSource) != 0)
        fprintf(stderr, "Blad przy zamykaniu pliku!\n");

    return 0;
}
