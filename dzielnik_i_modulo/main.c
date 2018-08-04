//
//  main.c
//  dzielnik_i_modulo
//
//  Created by Jakub Chojnacki on 17/08/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int modulo=0;

int main(int argc, const char * argv[]) {
    
    long dzielna=0,wynik=0;
    
    printf("podaj modulo :\n");
    scanf("%d",&modulo);
    
    printf("podaj dzielna :\n");
    scanf("%ld",&dzielna);
    
    wynik = dzielna % modulo;
    
    printf("%ld mod %d = %ld\n",dzielna,modulo,wynik);
    
    getchar();

    return 0;
}
