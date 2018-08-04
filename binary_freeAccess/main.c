//
//  main.c
//  binary_freeAccess
//
//  Created by Jakub Chojnacki on 01/05/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DL_TAB 1000

int main(int argc, const char * argv[]) {
   
    double numbers[DL_TAB];
    double value;
    const char * file = "numbers";
    int i;
    long findIndex;
    FILE *InOut;
    
    /* creating array values */
    for(i = 0; i < DL_TAB; i++)
        numbers[i] = 100.0 * i +1.0 / (i + 1);
    
    /* file openning attempt */
    if((InOut = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr,"ERROR : file can not be oppened\n");
        exit(EXIT_FAILURE);
    }
    
    /* rewriting values to binary file */
    fwrite(numbers, sizeof(double), DL_TAB, InOut);
    fclose(InOut);
    if((InOut = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr,"ERROR : free access denied\n");
        exit(EXIT_FAILURE);
    }
    
    /* display value */
    printf("type index from 0 - %d\n", DL_TAB - 1);
    while( (scanf("%d", &i) == 1) && i >= 0 && i <= DL_TAB)
    {
        findIndex = (long) i * sizeof(double);                  // my index
        findIndex = fseek(InOut, findIndex, SEEK_SET);              // go to index
        fread(&value, sizeof(double), 1, InOut);
        printf("value at index : %f\n", value);
        printf("insert index :\n");
    }
    
    /* clean */
    fclose(InOut);
    puts("cya");

    return 0;
}
