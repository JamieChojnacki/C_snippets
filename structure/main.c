//
//  main.c
//  structure
//
//  Created by Jakub Chojnacki on 07/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define mTIT 41
#define mAUT 31

char *load(char *string, int num);

/* structure template */
struct book
{
    char title[mTIT];
    char writer[mAUT];
    float price;
    
};


int main(int argc, const char * argv[]) {
   
    struct book library;
    puts("enter tittle:");
    load(library.title, mTIT );
    puts("enter author");
    load(library.writer, mAUT );
    puts("enter price");
    scanf("%f", &library.price);
    
    printf("%s : \"%s\" (%.2f euro)\n", library.writer, library.title, library.price);
    
    /* creating pointer to structure */
    struct book *pValue;
    pValue = &library;
    
    printf("library.price = %.2f\n", pValue -> price);
    return 0;
}


char *load(char *string, int num)
{
    char *result;
    char *found;
    
    result = fgets(string, num, stdin);
    if(result)
    {
        found = strchr(string, 0x0a);
        if(found)
            *found = 0x0;
        else
            while(getchar() != 0x0a)
                continue;
    }
    
    return result;
}
