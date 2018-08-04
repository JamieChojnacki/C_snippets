//
//  main.c
//  choose_?:
//
//  Created by Jakub Chojnacki on 05/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    int value_1;
    int value_2;
    int max;
    
    value_1 = (rand()%5)+1;
    value_2 = (rand()%5)+1;
    
    max = (value_1 > value_2) ? value_1 : value_2;                              // if ( value_1 > value_2 ) max = value_1
                                                                                // else max = value_2
    
    printf("liczby to %d oraz %d\n", value_1,value_2);
    printf("zatem wieksza jest %d\n", max);
    
    return 0;
}
