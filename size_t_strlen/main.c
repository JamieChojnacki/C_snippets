//
//  main.c
//  size_t_strlen
//
//  Created by Jakub Chojnacki on 05/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
   
    unsigned long znaki = 0;
    const char *string = "zgadnij ile mam znakow?";
    puts(string);
    
    znaki = strlen(string);
    printf("ilosc znakow to %lu\n", znaki);
    
    return 0;
}

