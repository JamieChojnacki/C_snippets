//
//  main.c
//  funcStruct_returnStruct
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

char *load(char *string, int num);
void display(struct person);
struct person get(void);
struct person compute(struct person);

int main(int argc, const char * argv[]) {
   
    struct person man;
    man = get();
    man = compute(man);
    display(man);
    
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


struct person get(void)
{
    struct person temp;
    puts("enter name :");
    load(temp.name, DL);
    puts("enter surname :");
    load(temp.surname, DL);
    
    return temp;
}

struct person compute(struct person info)
{
    info.count = strlen(info.name) + strlen(info.surname);
    return info;
}


void display(struct person info)
{
    printf("name : %s, surname : %s, count : %ld\n", info.name, info.surname, info.count);
}

