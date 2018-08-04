//
//  main.c
//  string_odwroc
//
//  Created by Jakub Chojnacki on 21/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void rotate(char * target);

int main(int argc, const char * argv[]) {
    
    
    char string[] = "space";
    
    puts(string);
    rotate(string);
    puts(string);
    
    return 0;
}


void rotate(char * target)
{
    long size;
    int index;
    char tmp_var;
    
    size = strlen(target);
    
    for(index = 0; index < (size - 1)/2; index++)
    {
        tmp_var = target[size - index - 1];
        target[size - index - 1] = target[index];
        target[index] = tmp_var;
    }
}

