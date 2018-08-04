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
    
    printf("    zippo = %p      zippo + 1 = %p\n",
                zippo,          zippo+1 );
    
    printf("zippo[0] = %p   zippo[0] + 1 = %p\n",
            zippo[0],        zippo[0] + 1 );
    
    printf("   *zippo = %p      *zippo + 1 = %p\n",
               *zippo,           *zippo+1 );
    
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("        *( *( zippo+2 )+1 ) = %d\n", *(*( zippo+2)+1) );
    
                         /* WNIOSEK */
    
    // zippo == &zippo[0]
    // zippo[0] == &zippo[0][0]
    
    return 0;
}
