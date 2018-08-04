//
//  main.c
//  struct_malloc
//
//  Created by Jakub Chojnacki on 10/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DL 81

struct person
{
    char *name;                         /* adres is not located in structure */
    char *surname;                      /*             - || -                */
    long count;
};

void get(struct person *);
void compute(struct person *);
void display(const struct person*);
char *load(char *string, int num);
void pFree(struct person*);


int main(int argc, const char * argv[]) {
    
    struct person man;
    get(&man);
    compute(&man);
    display(&man);
    pFree(&man);
    
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
            while(getchar()!= 0x0a)
                continue;
    }
    return result;
}


/* malloc use */
void get(struct person *wst)
{
    char temp[DL];           /* strings will be copied to temp array */
    
    puts("enter name :");
    load(temp, DL);
    /* allocate memory */
    wst -> name = (char *) malloc(strlen(temp) + 1);
    /* copy to structure */
    strcpy(wst -> name, temp);
    
    puts("enter surname :");
    load(temp, DL);
    /* allocate memory */
    wst -> surname = (char *) malloc(strlen(temp) +1 );
    /* copy to structure */
    strcpy(wst -> surname, temp);
    
}

void compute(struct person *wst)
{
    wst -> count = strlen(wst -> name) + strlen(wst -> surname);
}


void display(const struct person *wst)
{
    printf("name : %s, surname : %s, count : %ld\n", wst -> name, wst -> surname, wst -> count);
}

void pFree(struct person *wst)
{
    free(wst -> name);
    free(wst -> surname);
}
