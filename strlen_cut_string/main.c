//
//  main.c
//  strlen_cut_string
//
//  Created by Jakub Chojnacki on 01/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define s_size 49               // max rozmiar lancucha 49

void cut(char *string, unsigned int length);

int main(int argc, const char * argv[]) {
    
    char text[] = "Wyjasnienia powinny byc tak proste jak to mozliwe, ale nie prostsze.";
    
    puts(text);
    cut(text, s_size);
    puts(text);
    puts("a to jest reszta lancucha : ");
    puts(text + (s_size + 1) );                     // wyswietlamy reszte lancucha
                                                        // s_size + 1 jest adresem 51 komorki lancucha, czyli space
    
    return 0;
}

void cut(char *string, unsigned int length)
{
    if (strlen(string) > length)
        *(string + length) = '\0';          // zakoncz lancuch na 49 znaku czyli ',' = '\0'
}
