//
//  main.c
//  structure_pointers
//
//  Created by Jakub Chojnacki on 08/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#define DL 20

struct pInfor
{
    char name[DL];
    char surname[DL];
};

struct man
{
    struct pInfor person;
    char fav_meal[DL];
    char prof[DL];
    float salary;
};



int main(int argc, const char * argv[]) {
    
    struct man dude[2] = {                                      // initialize structure
        {{"Chip", "Hyperlink"},
            "strowberry cream",
            "lawyer",
            32000.00
        },
        {{"Barry", "Nels"},
            "spaghetti",
            "student",
            300.00
        }
    };
    
    struct man *pDude;
    printf("adres #1 : %p #2 : %p\n", &dude[0], &dude[1]);
    pDude = &dude[0];
    printf("pointer #1 : %p #2 : %p\n", pDude, pDude + 1);
    printf("pDude -> salary : %.2f$ && (*pDude).salary : %.2f$\n", pDude -> salary, (*pDude).salary);
    pDude++;
    printf("pDude -> fav_meal : %s\n", pDude -> fav_meal);
    
    printf("%s\n", pDude ->person.name);
    
    return 0;
}
