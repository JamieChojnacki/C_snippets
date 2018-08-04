//
//  main.c
//  fread_fwrite
//
//  Created by Jakub Chojnacki on 30/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 4096
#define DLAN 50

void writeIn( FILE *source, FILE *target );
char *load(char *, int);

int main(int argc, const char * argv[]) {
  
    FILE *pSource = NULL;
    FILE *pTarget;
    int files = 0;
    char targetFile[DLAN];
    char sourceFile[DLAN];
    int character;
    
    /* target source allocations */
    puts("Type target identity");
    load(targetFile, DLAN);
    
    if((pTarget = fopen(targetFile, "a")) == NULL)
    {
        fprintf(stderr, "openning file %s error", targetFile);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(pTarget, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fprintf(stderr,"can not allocate output buffer");
        exit(EXIT_FAILURE);
    }
    
    /* source file allocation */
    puts("load first source identity, (blank ends)");
    while( load(sourceFile, DLAN) && sourceFile[0] != 0x0)
    {
      if(strcmp(sourceFile, targetFile) == 0)
          fputs("invalid file identity", stderr);
        else if((pSource = fopen(sourceFile, "r")) == NULL)
            fprintf(stderr,"%s input file access denied", sourceFile);
        else{
            if(setvbuf(pSource, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fprintf(stderr,"input buffer access denial");
                continue;
            }
            writeIn(pSource, pTarget);
            if(ferror(pSource) != 0)
                fprintf(stderr,"ERROR: READOUT %s", sourceFile);
            if(ferror(pTarget) != 0)
                fprintf(stderr,"ERROR: WRITEDOWN %s", targetFile);
            fclose(pSource);
            files ++;
            printf("File %s writedown SUCCEEDED\n", sourceFile);
            puts("enter next file identity");
        }
    }
    printf("FINISHED. %d files added", files);
    rewind(pTarget);
    printf("%s contains :\n",targetFile);
    
    while((character = getc(pTarget)) != EOF)
        putchar(character);
    
    puts("END.");
    fclose(pTarget);

    return 0;
}

/* load characters grom stdin */
char *load(char *string, int num)
{
    char *result;
    char *found;
    
    result = fgets(string,num,stdin);
    if(result)
    {
        found = strchr(string, 0x0a);                    // lets check if new line
        if(found)
            *found = 0x0;
        else
            while(getchar() != 0x0a)
                continue;
    }
    return result;
}


/* write file containment to target file */
void writeIn( FILE *source, FILE *target )
{
    size_t bytes;
    static char temp[BUFSIZE];                                              // buf allocation
    while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
        fwrite(temp, sizeof(char), bytes, target);
    
}
