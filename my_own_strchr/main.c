//
//  main.c
//  my_own_strchr
//
//  Created by Jakub Chojnacki on 18/03/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define S_MAX 30

char *my_own_strchr(char *, char);

int main(int argc, const char * argv[]) {
    
    char znak;
    char *truth;
    char array_1[S_MAX] ="nigdy sie nie poddawaj";
    
    
    puts("podaj znak ktory chcesz sprawdzic:");
    znak = getchar();
    
    truth = my_own_strchr(array_1, znak);
    if(truth)
    {
        puts("ten znak znajduje sie w tablicy nr 1 !");
    }
    else
    {
        puts("ten znak nie znajduje sie w tablicy, sprobuj ponownie.");
    }
    
    return 0;
}
char *my_own_strchr(char *array, char znak)
{
   while(*array && *array != znak)
       ++array;
    
    return (char *)(znak == *array ? array : NULL);
    
}
