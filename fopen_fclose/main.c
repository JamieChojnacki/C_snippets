//
//  main.c
//  fopen_fclose
//
//  Created by Jakub Chojnacki on 18/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>             // prototyp funkcji exit

int main(int argc, char *argv[])
{
    int ch;                            // zachowuje kolejne odczytane znaki
    FILE *pFile;                            // "wskaznik plikowy"
    unsigned long licznik = 0;
    
    if (argc != 2)
    {
        printf("Sposob uzycia : %s nazwa pliku\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if( (pFile = fopen(argv[1], "r")) == NULL)
    {
        printf("Nie mozna otworzyc %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    while( (ch = getc(pFile)) != EOF)
    {
        putc(ch, stdout);
        licznik++;
    }
    fclose(pFile);
    printf("Plik %s zawiera %lu znakow \n", argv[1], licznik);
    
    return 0;
}
