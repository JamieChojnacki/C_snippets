//
//  main.c
//  fgets_fputs
//
//  Created by Jakub Chojnacki on 24/02/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#define DLUGOSC 14

int main(int argc, const char * argv[]) {
    
    char slowa[DLUGOSC];
    
    puts("wprowadz lancuch.");
    fgets(slowa, DLUGOSC, stdin);
    printf("wprowadzony lancuch (dwa razy: z puts() i fputs()) : \n");
    puts(slowa);                                                                // puts dodaje znak nowej linii
    fputs(slowa,stdout);
    puts("wprowadz kolejny lancuch");
    fgets(slowa, DLUGOSC, stdin);
    printf("wprowadzony lancuch (dwa razy: z puts() i fputs()) : \n");
    puts(slowa);
    fputs(slowa, stdout);
    puts("gotowe");
    
    return 0;
}
