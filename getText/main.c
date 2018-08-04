//
//  main.c
//  getText
//
//  Created by Jakub Chojnacki on 05/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sMax 30

char *load(char *string, int num);
void setPos(FILE *fileAdress, int index);

int main(int argc, const char * argv[]) {
    
    FILE *pFile;
    char *succeed;
    char fileName[sMax];
    char character;
    int index = 0;
    
    puts("allocate file name :");
    succeed = load(fileName, sMax);
    if(!succeed)
        fprintf(stderr,"ERROR: wrong file name\n");
    
    /* ask to open a file */
    if((pFile = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr,"ERROR: can not open file %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    puts("Enter line number :");
    while( (scanf("%d",&index) == 1) && index >= 1 && index <= 7)
    {
        rewind(pFile);
        setPos(pFile, index);
        
        while( (character = getc(pFile)) != EOF && character != 0x0a)
            putc(character,stdout);
        
        putchar(0x0a);
        putchar(0x0a);
        puts("Enter another line :");
    }
    
    fclose(pFile);
    puts("done.");
    
    return 0;
}

char *load(char *string, int num)
{
    char *result;
    char *found;
    
    result = fgets(string, num, stdin);
    if(result)
    {
        found = strchr(string, 0x0a);                        // seek for new line
        if(found)
            *found = 0x0;
        else
            while( getchar() != 0x0a )                          // cut extended characters
                continue;
    }
    
    return result;
}

void setPos(FILE *fileAdress, int num)
{
    long fPos = 0l;
    
    fPos = (long) num * sizeof(double);                                 // offset
    fseek(fileAdress, fPos, SEEK_SET);

}
