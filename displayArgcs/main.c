//
//  main.c
//  displayArgcs
//
//  Created by Jakub Chojnacki on 04/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    FILE *fp;
    int ch;
    
    if(argc == 1)
    {
        printf("usage : %s, file1, file 2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    for(int i = 1; i < argc; i++)
    {
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            fprintf(stderr,"could not open file %s\n", argv[i]);
            exit(EXIT_FAILURE);
            
        }
        while((ch = getc(fp)) != EOF)
            putc(ch, stdout);
        
        fclose(fp);
    }
    return 0;
}
