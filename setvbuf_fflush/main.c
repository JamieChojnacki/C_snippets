//
//  main.c
//  setvbuf_fflush
//
//  Created by Jakub Chojnacki on 26/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    
    long file_size;
    char buffer[BUFSIZ];                // BUFSIZ - minimal value describing buffer size for current library
    FILE *pSource;
    
    /* openning file attempt */
    if( (pSource = fopen("source","w+")) == NULL)
    {
        fprintf(stderr,"nie mozna otworzyc pliku");
        exit(EXIT_FAILURE);
    }

    /* setting temporary buf */
    if((setvbuf(pSource, buffer, _IOFBF, BUFSIZ))!= 0 )                 // buffer could not be set
    {
        perror("setvbuf()");                                                // if NULL send error link to stderr
        fprintf(stderr,"setvbuf() failed in file %s at line # %d\n", __FILE__, __LINE__ - 3);
        exit(EXIT_FAILURE);
    }
    
    /* Exhibit the contents of buffer. */
    fputs("aaa",pSource);
    printf("%s\n",buffer);
    fputs("bbb",pSource);
    printf("%s\n",buffer);
    fputs("ccc",pSource);
    printf("%s\n",buffer);
    file_size = ftell(pSource);                         // size of current file
    printf("file_size = %ld\n", file_size);
    fflush(pSource);                                        // flushing buffer
    printf("%s\n",buffer);
    fputs("ddd",pSource);
    printf("%s\n",buffer);
    fputs("eee",pSource);
    printf("%s\n",buffer);
    
    /* flush buffer and rewind file */
    rewind(pSource);
    char buf[20];
    fgets(buf, sizeof buf, pSource);
    printf("%s\n",buf);
    
    fclose(pSource);
    
    return 0;
}

/* mode : */
/* _IOFBF - full buffering */
/* _IOLBF - line buffering */
/* _IONBF - no buffering size, size of the buffer */
