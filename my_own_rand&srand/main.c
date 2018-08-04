//
//  main.c
//  my_own_rand&srand
//
//  Created by Jakub Chojnacki on 10/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

extern void my_own_srand( unsigned int );
extern int my_own_rand( void );

int main(int argc, const char * argv[]) {
    
    int number;
    unsigned seed;
    
    puts("podaj wartosc ziarna");
    while( scanf("%u", &seed) == 1 )
    {
        my_own_srand(seed);         /* reset ziarna */
        for(number = 0; number < 5; number++)
            printf("%d\n", my_own_rand());
        puts("podaj nastepna wartosc ziarna (k to koniec) :");
    }
    puts("gotowe");
    return 0;
}
