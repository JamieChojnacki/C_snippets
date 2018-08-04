//
//  main.c
//  *load( *char)
//
//  Created by Jakub Chojnacki on 14/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>                             // prototyp strchr

/* #define SIZE_MAX 100 */

char *load(char *target, int bufor);
char *load_strchr(char *target, int bufor);             // przyklad z wykorzystaniem fukncji strchr

int main(int argc, const char * argv[]) {
    
    /*
     
     char string_array[SIZE_MAX]
     
     while( load(string_array, SIZE_MAX) )
     do something
     ...
     
     */
    
    return 0;
}

char *load(char *target, int bufor)
{
    char *result;                               // zwracamy wskaznik
    
    result = fgets(target, bufor, stdin);               // jezeli nie uda sie pobrac, to result == NULL
    if(result)                                              // wynik rozny od NULL
    {
        while(*target !=0x0a && *target != 0x0)
            target++;
        if(*target == 0x0a)                                     // zamien znak nowego wiersza na znak zerowy
            *target = 0x0;
        else
            while( getchar() != 0x0a )                          // pomijamy nadmiarowe znaki
                continue;
            
    }
    
    return result;
}

char *load_strchr(char *target, int bufor)
{
    char *result;
    char *found;
    
    result = fgets(target, bufor, stdin);               // jezeli nie uda sie pobrac, to result == NULL
    if(result)                                              // wynik rozny od NULL
    {
        found = strchr(target, 0x0a);                           // szukamy znaku nowego wiersza
        if(found)                                                   // jezeli udalo sie znalezc
            *found = 0x0;                                               // to pod adres trafia znak zerowy
        else
            while( getchar() != 0x0a )                          // pomijamy nadmiarowe znaki
                continue;
        
    }
    
    return result;
    
    
}
