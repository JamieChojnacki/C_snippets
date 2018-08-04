//
//  main.c
//  delete_space_string
//
//  Created by Jakub Chojnacki on 22/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define LENGTH 80
#define LAYERS 9

char *load(char *target, int bufor);
void delete_space(char (*string)[LENGTH]);

int main(int argc, const char * argv[]) {
    
    int index = 0;
    int counter = 0;
    char book[LAYERS][LENGTH];
    
    while(index < LAYERS && load(book[index], LENGTH) && book[index][0] != 0x0)
    {
        index++;
        counter++;
    }
    
    delete_space(book);
    for(int k = 0; k < counter; k++)
        printf("%s\n", book[k]);
    
    return 0;
}


char *load(char *target, int bufor)
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

void delete_space(char (*string)[LENGTH])
{
    int layer;
    int column;
    
    for(layer = 0; layer < LAYERS; layer++)
        for(column = 0; column < LENGTH - 1; column++)
        {
            if( *(*(string + layer) + column) == 0x20)
                *(*(string + layer) + column) = 0x08;
            if(*(*(string + layer) + column) == 0x0a)
                break;
        }
    
}

