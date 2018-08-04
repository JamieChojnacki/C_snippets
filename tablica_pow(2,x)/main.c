//
//  main.c
//  tablica_pow(2,x)
//
//  Created by Jakub Chojnacki on 31/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    const int value = 2, size = 8;
    int index, offset;
    int power_2[size];
    
    for(offset = 0, index = 1; offset < size; offset ++, index ++)
        power_2[offset] = pow(value, index);
    
    
    do{
        --offset;
        printf("%d \t %d\n",offset,power_2[offset]);
    }while(offset != 0);
    return 0;
}
