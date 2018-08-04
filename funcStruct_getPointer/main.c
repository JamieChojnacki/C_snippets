//
//  main.c
//  funcStruct_getPointer
//
//  Created by Jakub Chojnacki on 10/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define DL 30

struct person
{
    char name[DL];
    char surname[DL];
    long count;
};

void get(struct person *);
void compute(struct person *);
void display(const struct person*);
char *load(char *string, int num);


int main(int argc, const char * argv[]) {
   
    struct person man;
    get(&man);
    compute(&man);
    display(&man);
    
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


void get(struct person *wst)
{
    puts("enter name :");
    load(wst -> name, DL);
    puts("enter surname :");
    load(wst -> surname, DL);
}

void compute(struct person *wst)
{
    wst -> count = strlen(wst -> name) + strlen(wst -> surname);
}


void display(const struct person *wst)
{
    printf("name : %s, surname : %s, count : %ld\n", wst -> name, wst -> surname, wst -> count);
}
