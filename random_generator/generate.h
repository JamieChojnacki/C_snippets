//
//  generate.h
//  random_generator
//
//  Created by Jakub Chojnacki on 17/04/2018.
//  Copyright © 2018 James. All rights reserved.
//

#ifndef generate_h
#define generate_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define OBJECTS 1000                             // ilosc obiektow


void gamble(void);
void counter(unsigned int *generated);
void change_seed(void);
void result(void);

typedef unsigned int MyVariable;

#endif /* generate_h */
