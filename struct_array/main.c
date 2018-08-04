//
//  main.c
//  struct_array
//
//  Created by Jakub Chojnacki on 08/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define maxtit 40
#define maxaut 40
#define maxbk 100

char *load(char *string, int num);

struct book {
    
    char title[maxtit];
    char writer[maxaut];
    float price;
};

int main(int argc, const char * argv[]) {
    
    struct book lib[maxbk];                      // declaring an array of structure elements
    
    int counter = 0;
    int index;
    
    puts("enter title [enter ends] : ");
    while(counter < maxbk && load(lib[counter].title, maxtit) != NULL && lib[counter].title[0] != 0x0)
    {
        puts("enter writer : ");
        load(lib[counter].writer, maxaut);
        puts("enter price : ");
        scanf("%f", &lib[counter++].price);
        
        while(getchar() != 0x0a)                            // clear in row
            continue;
        puts("enter another title : ");
    }
    if(counter > 0)
    {
        puts("here is the list : ");
        for(index = 0; index < counter; index++)
            printf("%s writer : %s, price : %.2f\n", lib[index].title, lib[index].writer, lib[index].price);
    }
    else
        puts("none.");
    
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
        found = strchr(string, 0x0a);
        if(found)
            *found = 0x0;
        else
            while(getchar() != 0x0a)
                continue;
    }
    
    return result;
}
