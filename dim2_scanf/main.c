//
//  main.c
//  dim2_scanf
//
//  Created by Jakub Chojnacki on 04/02/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

#define ELEMENTS 5

void copy_elements(double value_in_1,double value_in_2,double value_in_3,double value_in_4,double value_in_5,double(*target)[ELEMENTS],int index );
double avg(double (*array)[ELEMENTS], int which);

int main(int argc, const char * argv[]) {
    
    double value_1, value_2, value_3, value_4, value_5;
    double v_avg = 0l;
    double array[3][ELEMENTS];
    
    for(int i = 0; i < 3; i++)
    {
        printf("podaj 5 licz typu float dla %d tablicy\n", i);
        if( (scanf("%lf,%lf,%lf,%lf,%lf", &value_1, &value_2, &value_3, &value_4, &value_5) ) == 5 )
        {
            copy_elements(value_1, value_2, value_3, value_4, value_5, array, i);
        }
        else{
            printf("podales za malo elementow!\n");
            break;
        }
    }
    
    for(int tab = 0; tab < 3; tab++)
        for(int el = 0; el < ELEMENTS; el++)
            printf("[%d][%d] = %lf\n", tab, el, *(*(array + tab) + el) );
    
    v_avg = avg(array, 3);
    
    printf("srednia wynosi %.3lf", v_avg);
    
    putchar(0x0a);
    
    return 0;
}

void copy_elements(double value_in_1,double value_in_2,double value_in_3,double value_in_4,double value_in_5,double(*target)[ELEMENTS],int index )
{
    switch(index)
    {
        case 0:
            *(*(target + index) + 0) = value_in_1;
            *(*(target + index) + 1) = value_in_2;
            *(*(target + index) + 2) = value_in_3;
            *(*(target + index) + 3) = value_in_4;
            *(*(target + index) + 4) = value_in_5;
            break;
        case 1:
            *(*(target + index) + 0) = value_in_1;
            *(*(target + index) + 1) = value_in_2;
            *(*(target + index) + 2) = value_in_3;
            *(*(target + index) + 3) = value_in_4;
            *(*(target + index) + 4) = value_in_5;
            break;
        case 2:
            *(*(target + index) + 0) = value_in_1;
            *(*(target + index) + 1) = value_in_2;
            *(*(target + index) + 2) = value_in_3;
            *(*(target + index) + 3) = value_in_4;
            *(*(target + index) + 4) = value_in_5;
            break;
        default:
            break;
    }
    
}


double avg(double (*array)[ELEMENTS], int which)
{
    double out = 0l;
    double summ = 0l;;
    int choice = 0;
    
    printf("srednia z ktorej tablicy?\n (0,1,2)\n");
    scanf("%d", &choice);
    
    for(int index = 0; index < ELEMENTS; index++)
        summ += *(*(array + choice) + index);

    out = summ/ ELEMENTS;
    
    return out;
}
