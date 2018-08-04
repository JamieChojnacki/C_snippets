//
//  main.c
//  fgets_NULL
//
//  Created by Jakub Chojnacki on 25/02/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define DLUGOSC 14

void OK( char *p_slowo );
void BETTER( char *p_slowo );

int main(int argc, const char * argv[]) {
    
    char slowo[DLUGOSC];
    //OK( slowo );
    BETTER( slowo );
    return 0;
}

/* void OK( char *p_slowo )
// ten sposob pobiera jednorazowo 14 znakow, wiec moze prowadzic do przepelnienia bufora !
{
    while(fgets(p_slowo, DLUGOSC, stdin) != NULL && *(p_slowo + 0) != 0x0a)         // jezeli jest koncem pliku, lub pierwszy wczytany znak \n
        fputs(p_slowo, stdout);
    
    puts("gotowe");

}*/

void BETTER( char *p_slowo )
// ten sposob chroni nas przed mozliwym przepelnieniem bufora !
{
    
    int i;
    while(fgets(p_slowo, DLUGOSC, stdin) != NULL && *(p_slowo + 0) != 0x0a)
    {
        i = 0;
        while(*(p_slowo + i) != 0x0a && *(p_slowo + i) !='\0')          // poszukujemy znaku nowego wiersza
            i++;
                if(*(p_slowo + i) == 0x0a)                                  // znaleziono znak nowego wiersza
                    *(p_slowo + i) = '\0';                                      // zamien na znak puty
        else // slowo[i] juz wynosi '\0'
            while( getchar()!= 0x0a )                       // pozbywamy sie nadmiaru informacji, jezeli na wejsciu sa jeszcze jakies dane
                continue;
        fputs(p_slowo,stdout);
        putchar(0x0a);
    }
    puts("gotowe");
}
