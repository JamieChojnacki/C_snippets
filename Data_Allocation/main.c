//
//  main.c
//  Data_Allocation
//
//  Created by Jakub Chojnacki on 14/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int obszar_statyczny = 30;
const char *lcz = "Literal ciagu znakow";

int main(int argc, const char * argv[]) {
    
    int obszar_automatyczny = 40;
    char ciag_automatyczny[] = "Automatyczny przydzial tablicy znakow";
    int *wski;
    char *wskl;
    
    wski = (int *)malloc(sizeof(int));
    *wski = 35;
    wskl = (char *)malloc(strlen("Ciag przydzielany dynamicznie") + 1);
    strcpy(wskl, "Ciag przydzielany dynamicznie");
    
    printf(" Obszar_statyczny : %d pod adresem : %p\n",
           obszar_statyczny, &obszar_statyczny);
    printf(" Obszar_automatyczny : %d pod adresem : %p\n",
           obszar_automatyczny, &obszar_automatyczny);
    
    printf(" *wski : %d pod adresem : %p\n",*wski, wski);
    printf(" %s pod adresem : %p\n",lcz, lcz);
    printf(" %s pod adresem : %p\n",ciag_automatyczny, ciag_automatyczny);
    printf(" %s pod adresem : %p\n",wskl, wskl);
    
    free(wski);
    free(wskl);
    
    return 0;
}

/* Dane statyczne zajmuja wraz z literalami jeden obszar pamieci */
/* Dane automatyczne drugi */
/* Dane przydzielane dynamicznie trzeci - memory heap (free store) */
