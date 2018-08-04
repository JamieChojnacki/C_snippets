//
//  main.c
//  l_male_duze_licz
//
//  Created by Jakub Chojnacki on 15/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    
    char sign;
    int count_low = 0;
    int count_upper = 0;
    int count_other = 0;
    
    printf("wpisz zdanie, ctr + D aby zakonczyc\n");
    while((sign = getchar())!= EOF)
    {                                                                               // 1.begin
        
        putchar(sign);
if(sign == '\n')                                                                    // pomijaj znak nowej linii
        continue;
        
    if (islower(sign))                                                              // jezeli jest mala litera
        count_low++;
        
        if (isupper(sign))                                                          // jezelu jest duza litera
            count_upper++;
        
            if(isspace(sign))                                                       // jezeli jest bialym znakiem
                count_other++;
        
    }                                                                              // 1.end
    printf("male litery: \t duze litery: \t inne znaki: \n");
    printf("%4d \t\t\t %4d \t\t\t %4d", count_low, count_upper, count_other);
    putchar('\n');

    return 0;
}
