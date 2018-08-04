//
//  main.c
//  liczba_dzielniki
//
//  Created by Jakub Chojnacki on 05/11/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    
    bool prime;
    unsigned long number;
    unsigned long div;
    
    printf("podaj liczbe\n");
    printf("podaj q aby zakonczyc\n");
    
    while(scanf("%ld",&number)==1){                                                         // begin while
        for(div = 2, prime = true; (div*div) <= number; div++)
        {                                                                                   // begin for
            if(number % div ==0)
            {
                if( (div*div) != number)                                                    // printf if not the same value
                    printf("%ld dzieli sie przez %ld i %ld \n", number, div, number/div);
                else
                    printf("%ld dzieli sie przez %ld \n\n", number, div);
                prime = false;
            }
        }                                                                                   // end for
        if(prime)
        printf("%ld jest liczba pierwsza\n", number);
        printf("podaj kolejna liczbe\n");
        printf("podaj q aby zakonczyc\n");
        
    }                                                                                       // end while
    printf("gotowe\n");
    return 0;
}
