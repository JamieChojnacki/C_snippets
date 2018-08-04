//
//  main.c
//  getchar(string_array)
//
//  Created by Jakub Chojnacki on 17/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define LIMIT 40

void single_word(char *);
void copy_char(char *,int);

int main(int argc, const char * argv[]) {
   
    char string[] = "kuba zaczyna pakowac na silowni";
    char target[LIMIT];
    
    single_word(string);
    copy_char(target, LIMIT);
    
    return 0;
}


void single_word(char *string)
{
    char *point;
    
    fputs(string, stdout);
    putchar(0x0a);
    
    point = strchr(string, 0x20);
    
    if(point)
        *point = 0x0;
    
    fputs(string, stdout);
    putchar(0x0a);
}

void copy_char(char *target, int maximum)
{
    char c;
    int i = 0;
    while( (c = getchar())!= 0x0a && i < maximum)
    {
        *(target + i) = c;
        i++;
    }
    fputs(target, stdout);
    putchar(0x0a);
    
}
