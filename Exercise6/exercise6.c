//
// Created by flori on 08.02.2021.
//

#include "exercise6.h"
#include "stdio.h"
#include "math.h"


void exercise6_armstrong(){
    int total= 0;
    double  powed = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                // printf(" - %i,%i,%i", i, j, k);
                total = 100* i + 10 * j + 1 * k;
                powed = (pow(i,3) + pow(j,3) + pow(k,3));
                //printf(" - %i,%i,%i->%i, %i", i, j, k, (int)powed, total);
                if( total == (int)powed){
                    printf("\nDAMN BRO - ONE ARMSTRONG BLOODY ASS NUMBER IS %i\n", total );
                }
            }
        }

    }
}