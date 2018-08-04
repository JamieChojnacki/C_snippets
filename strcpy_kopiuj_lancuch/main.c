//
//  main.c
//  strcpy_kopiuj_lancuch
//
//  Created by Jakub Chojnacki on 04/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define ROZMIAR 40
#define GRAN 5

char *load( char *string, int size);

int main(int argc, const char * argv[]) {
    char vslowa[GRAN][ROZMIAR];
    char slowa[ROZMIAR];
    int i = 0;
    
    printf("podaj %d slow zaczynajacych sie na v\n", GRAN);
    
        while( load(slowa, GRAN) && i < GRAN)
        {
            if (slowa[0] != 'v')                        // jezeli nie zaczyna sie na v to opluj
                puts("nie zaczyna sie na v");
            else
            {
    strcpy(vslowa[i], slowa);               // skopiuj do tablicy  docelowej
                i++;
            }
        }
    
    puts("oto przyjete slowa :");
    for (int j = 0; j < GRAN; j++)
        printf("%s\n", *(vslowa + j) );
    
    return 0;
}

char *load( char *string, int size)
{
    char *p_string;
    int counter = 0;
    
    p_string = fgets(string, size, stdin);
    if(p_string)
    {
        while(string[counter] != 0x0a && string[counter] != '\0')
        counter++;
            if (string[counter] == 0x0a)
                string[counter] = '\0';
            else
                while( getchar() != 0x0a )
                    continue;
    }

    return p_string;
}
