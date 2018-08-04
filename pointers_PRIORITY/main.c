//
//  main.c
//  pointers_PRIORITY
//
//  Created by Jakub Chojnacki on 16/12/2017.
//  Copyright © 2017 James. All rights reserved.
//

#include <stdio.h>

int data_1[2] = {100,200};
int data_2[2] = {300,400};

int main(int argc, const char * argv[]) {
    
    int *p1, *p2, *p3;
    
    p1 = p2 = data_1;                   // &data_1[0] zostaje przypisana wskaznikom 1 i 2
    p3 = data_2;                            // &data_2[0] zostaje przypisana wskaznikowi 3
    
    printf("    *p1 = %4d,     *p2 = %4d,     *p3 = %4d\n",
                    *p1,            *p2,        *p3 );
    printf("  *p1++ = %4d,   *++p2 = %4d,  *(p3)++ =%4d\n",
                    *p1++,        *++p2,        *(p3)++ );
    printf("    *p1 = %4d,     *p2 = %4d,     *p3 = %4d\n",
                    *p1,            *p2,        *p3 );
    return 0;
}
