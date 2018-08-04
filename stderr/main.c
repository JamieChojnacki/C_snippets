//
//  main.c
//  stderr
//
//  Created by Jakub Chojnacki on 20/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>         // dla exit
#include <string.h>

#define DL 40

int main(int argc, const char * argv[]) {
   
    FILE *pSource;
    FILE *pTarget = NULL;
    
    int ch;
    char nazwa[DL];             // miejsce na nazwe pliku
    int licznik = 0;
    
    if(argc < 2)
    {
        fprintf(stderr,"Sposob uzycia : %s nazwa pliku\n", argv[0]);    // stderr - wskaznik wyjscia dla bledow
        exit(EXIT_FAILURE);
    }
    
    /* plik wejsciowy */
    if( (pSource = fopen(argv[1], "r")) == NULL)
       {
           fprintf(stderr,"nie moglem otworzyc pliku \"%s\".\n", argv[1]);
           exit(EXIT_FAILURE);
       }
    
    /* przygotowanie pliku wynikowego */
    strncpy(nazwa, argv[1], DL - 5);
    nazwa[DL - 5] = 0x0;
    strcat(nazwa, ".red");                      // dodaje .red do nazwy
    
    /* otwieranie pliku do zapisu */
    if( (pTarget = fopen(nazwa, "w")) == NULL)
    {
        fprintf(stderr, "Nie mozna utworzyc pliku wyjsciowego.\n");
        exit(EXIT_FAILURE);
    }
    
    /* kopiowanie danych */
    while( (ch = getc(pSource)) != EOF)
        if( (++licznik % 3) == 0)
            putc(ch, pTarget);                       // zapisuje co 3ci znak w pliku wyjsciowym
    
    /* sprzatanie */
    if(fclose(pSource) != 0 || fclose(pTarget) != 0)
        fprintf(stderr,"Blad przy zamykaniu plikow.\n");
    
    return 0;
}


/* kompilacja -> kopiowanie adresu wyswietlonego przez terminal -> (terminal) directory to terminal */
/* ln -s (wklejamy teraz adres z kompilatora) - stworzony zostaje hard link */
/* odpalamy ./stderr source i gotowe  */
