//
//  main.c
//  metrifyText
//
//  Created by Jakub Chojnacki on 04/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define LLEN 70

void fget(char * string, int n, FILE *file);

int main(int argc, char *argv[])
{
    FILE *file1, *file2;
    char tmp[LLEN];
    
    if (argc < 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if ((file1 = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((file2 = fopen(argv[2], "r")) == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    
    while (1)
    {
        tmp[0] = 0x0;
        fget(tmp, LLEN, file1);
        printf("%-*s\t", LLEN, tmp);
        
        tmp[0] = 0x0;
        fget(tmp, LLEN, file2);
        printf("%-*s\n", LLEN, tmp);
        
        if (feof(file1) && feof(file2))
            break;
    }
    
    return 0;
}

void fget(char * string, int n, FILE *file)
{
    // wrapper for fgets - replaces
    // first newline with null character
    
    fgets(string, n, file);
    
    while (*string != 0x0)
    {
        if (*string == 0x0a)
        {
            *string = 0x0;
            break;
        }
        string++;
    }
}
