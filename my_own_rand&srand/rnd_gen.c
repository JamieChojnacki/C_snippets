//
//  rnd_gen.c
//  my_own_rand&srand
//
//  Created by Jakub Chojnacki on 10/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

// przenosny algorytm ANSII C

static unsigned long int value = 1;          // ziarno generatora zapamietane

int my_own_rand( void )
{   /* magiczna formula generujaca liczby pseudolosowe */
    
    value = value * 1103515245 + 12345;
    
    return (unsigned int)(value/65536) % 32768;                     // zwracamy wartosc losowa
}

void my_own_srand( unsigned int seed )                                  // funkcja ktora resetuje ziarno
{
    value = seed;
}
