//
//  main.c
//  static_function
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int counter;
void function(void);

int main(int argc, const char * argv[]) {
    
    srand( (unsigned int) (time(0)) );
    int loop = rand() % 5;
    
    for(int i = 0; i < loop; i ++)
        function();
    
    printf("funkcja zostala wywolana %d razy\n", counter);
    
    return 0;
}

void function(void)
{
    counter ++;
    puts("here comes magic !");
}
