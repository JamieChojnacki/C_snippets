//
//  main.c
//  textFile_toupper
//
//  Created by Jakub Chojnacki on 04/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
  
    FILE *pSource;
    FILE *pDestination;
    char character;
    
    if((pSource = fopen("source", "r")) == NULL)
    {
        fprintf(stderr,"ERROR: input file access denied !\n");
        exit(EXIT_FAILURE);
    }
    
    if((pDestination = fopen("destination", "w")) == NULL)
    {
        fprintf(stderr,"ERROR: output file access denied !\n");
        exit(EXIT_FAILURE);
    }
    
    while((character = getc(pSource)) != EOF)
    {
        if(islower(character))
            character = toupper(character);
        putc(character, pDestination);
    }
    
    fclose(pSource);
    fclose(pDestination);
    
    return 0;
}
