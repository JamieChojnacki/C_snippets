//
//  main.c
//  tab_vs_tab[0]_pointers
//
//  Created by Jakub Chojnacki on 06/01/2018.
//  Copyright © 2018 James. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5,7} };
    
    int ( *pt)[2];                      // pt wskazuje do tablicy dwoch elementow typu int
    pt = zippo;
    
    printf("    pt = %p      pt + 1 = %p\n",
           pt,          pt + 1 );
    
    printf("pt[0] = %p   pt[0] + 1 = %p\n",
           pt[0],        pt[0] + 1 );
    
    printf("   *pt = %p      *pt + 1 = %p\n",
           *pt,           *pt + 1 );
    
    printf("pt[0][0] = %d\n", pt[0][0]);
    printf("  *pt[0] = %d\n", *pt[0]);
    printf("    **pt = %d\n", **pt);
    printf("      pt[2][1] = %d\n", pt[2][1]);
    printf("        *( *( pt+2 )+1 ) = %d\n", *(*( pt+2)+1) );

    
// *( *( zippo + m ) + n) == zippo[m][n]
// *( *( pt + m ) + n ) == pt[m][n]
    
    // int * pax[2]   !=   int (* pax)[2]     !!!
    
    return 0;
}

