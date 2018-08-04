//
//  main.c
//  var_static
//
//  Created by Jakub Chojnacki on 08/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

// roznica miedzy zmienna automatyczna a statyczna

#include <stdio.h>
void check_status(void);

int main(int argc, const char * argv[]) {
    
    int counter;
    for(counter = 0; counter < 3; counter ++)
    {
        printf("iteracja nr : %d :\n", counter);
        check_status();
    }
    
    return 0;
}

void check_status(void)
{
    int automatic_var = 1;
    static int static_var = 1;
    
    printf("automatyczna = %d, a statyczna = %d\n", automatic_var ++, static_var ++);
    
}
// statyczne zmienne nie sa niszczone - sa zapisywana w pamieci statycznej
