//
//  generate.c
//  random_generator
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include "generate.h"

MyVariable h_1;
MyVariable h_2;
MyVariable h_3;
MyVariable h_4;
MyVariable h_5;
MyVariable h_6;
MyVariable h_7;
MyVariable h_8;
MyVariable h_9;
MyVariable h_10;


void gamble(void)
{
    unsigned int random;
    random = (rand() % 10) + 1;
    
    counter(&random);
}


void change_seed(void)
{
    srand((unsigned int) time(0));
}


void counter(unsigned int *generated)
{
    if(*generated == 1)
        h_1 ++;
    if(*generated == 2)
        h_2 ++;
    if(*generated == 3)
        h_3 ++;
    if(*generated == 4)
        h_4 ++;
    if(*generated == 5)
        h_5 ++;
    if(*generated == 6)
        h_6 ++;
    if(*generated == 7)
        h_7 ++;
    if(*generated == 8)
        h_8 ++;
    if(*generated == 9)
        h_9 ++;
    if(*generated == 10)
        h_10 ++;
    
}

void result(void)
{
    printf("wartosc 1 wygenerowana : %d razy\n",h_1);
    printf("wartosc 2 wygenerowana : %d razy\n",h_2);
    printf("wartosc 3 wygenerowana : %d razy\n",h_3);
    printf("wartosc 4 wygenerowana : %d razy\n",h_4);
    printf("wartosc 5 wygenerowana : %d razy\n",h_5);
    printf("wartosc 6 wygenerowana : %d razy\n",h_6);
    printf("wartosc 7 wygenerowana : %d razy\n",h_7);
    printf("wartosc 8 wygenerowana : %d razy\n",h_8);
    printf("wartosc 9 wygenerowana : %d razy\n",h_9);
    printf("wartosc 10 wygenerowana : %d razy\n",h_10);

}
