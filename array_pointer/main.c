//
//  main.c
//  array_pointer
//
//  Created by Jakub Chojnacki on 16/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#define MAX 10

int main(int argc, const char * argv[]) {
    int value[10] = {[5] = 6,7,8,9,1};
    int index;
    
    for (index = 0; index < MAX ; index++)
        printf("index %d wartosc : %3d\n",index+1, *(value + index));
                                                                            // value == &value[0], (value + 1) == value[1]
                                                                            // *(value + 1) == value[1]
    putchar('\n');
    return 0;
}
