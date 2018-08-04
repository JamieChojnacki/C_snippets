//
//  main.c
//  suma_el_tablicy
//
//  Created by Jakub Chojnacki on 31/10/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
   
    const int size = 8;
    int offset_1, offset_2;
    int array_1[size], array_2[size];
    
    printf("podaj 8 wartosci do tablicy\n");
    for(offset_1 = 0; offset_1 <size; offset_1 ++){                              // begin 1
        scanf("%d", &array_1[offset_1]);                                         // assign values to array
    }                                                                            // end 1
    printf("offset: \t wartosc :\n");
    for(offset_1 = 0; offset_1 <size; offset_1++){                              // begin
            printf("%4d \t %5d\n", offset_1, array_1[offset_1]);                // paint offset & value
    }
    
    for (offset_2 = 0,offset_1 = 0; offset_2 < size; ++offset_1, ++offset_2)     // begin 2
        array_2[offset_2] = array_2[offset_2 - 1] + array_1[offset_1];           // assign summ of the previous elements
    
    
        printf("offset: \t wartosc :\n");
    for (offset_2 = 0; offset_2 < size; offset_2++)
        printf("%4d \t %5d\n", offset_2, array_2[offset_2]);                    // print sum of the elements
    
    return 0;
}
