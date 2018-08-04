//
//  main.c
//  copy_binary
//
//  Created by Jakub Chojnacki on 04/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define piNumbers 5

int main(int argc, const char * argv[]) {
    
    FILE *pSource;
    FILE *pTarget;
    
    size_t bytes;
    
    double pi[piNumbers];
    
    
    /* attempt opening output file */
    if((pTarget = fopen("target", "wb")) == NULL)
    {
        fprintf(stderr, "ERROR: can not open out file\n");
        exit(EXIT_FAILURE);
    }
    
    /* attempt opening input file */
    if((pSource = fopen("source", "rb")) == NULL)
    {
        fprintf(stderr, "ERROR: can not open input file\n");
        exit(EXIT_FAILURE);
    }
    
    /* how many bytes */
    
    rewind(pSource);
    fseek(pSource, 0L, SEEK_END);
    bytes = ftell(pSource);
    
    fread(pi, sizeof(double), bytes, pSource);
    fwrite(pi, sizeof(double), bytes, pTarget);
    
    fclose(pSource);
    fclose(pTarget);
    
    puts("done.");
    
    return 0;
}
