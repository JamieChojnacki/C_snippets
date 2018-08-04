//
//  main.c
//  szerokosc i dokladnosc
//
//  Created by Jakub Chojnacki on 01/06/2017.
//  Copyright © 2017 James. All rights reserved.
//

#define PI 3.141592 // definiuje stala PI

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    unsigned int szerokosc, dokladnosc; //zmienne
    
    printf("podaj szerokosc pola\n");
    scanf("%d",&szerokosc);
    fflush(stdout);
    printf("PI=%*f\n",szerokosc,PI);
    
    printf("podaj dokladnosc\n");
    scanf("%d",&dokladnosc);
    printf("wartosc PI = %*.*f\n",szerokosc,dokladnosc,PI);
    
    getchar();
   
    return 0;
}
