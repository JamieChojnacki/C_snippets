//
//  main.c
//  load_single_string
//
//  Created by Jakub Chojnacki on 14/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define S_MAX 30

void load(char *p_source, int size);

int main(int argc, const char * argv[]) {
    
    char source[S_MAX];
    
    puts("podaj zdanie, enter konczy wczytywanie");
    load(source, S_MAX);
    
    fputs(source, stdout);
    putchar(0x0a);
    
    return 0;
}

void load(char *p_source, int size)
{
    char c;
    char temp[size];
    char *p_temp;
    char *found;
    
    p_temp = temp;
    
    while( (c = getchar()) != 0x0a)
    {
        putchar(c);
        *p_temp++ = c;
    }
    putchar(0x0a);

    found = strchr(temp, 0x20);                     // szukamy spacji
    if(found)
        *found = 0x0;
    strcpy(p_source, temp);                             // zwracamy skopiowany lancuch do momentu znaku zerowego
    
}
