//
//  main.c
//  putchar_getchar
//
//  Created by Jakub Chojnacki on 05/11/2017.
//  Copyright © 2017 James. All rights reserved.
//
#include <ctype.h>
#include <stdio.h>
#define space 0x20                               // apo - space - apo   0x20 space SPC

int main(int argc, const char * argv[]) {
    
    char input;
    
    while((input = getchar())!= 0x0a)                        // char is succeded then check if not \n
    {                                            // begin
        if(input == space)
            putchar(input);
        else{
            putchar(input+1);
            input = getchar();
        }
    }                                            // end
    putchar(input);
    return 0;
}
