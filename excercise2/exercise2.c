//
// Created by flo on 06.02.21.
//

#include "exercise2.h"
#include "stdio.h"
#include "math.h"

void exercise2_calculator(){
    // part 1;
    int res1 = pow(5,2) + 3* 5 + 17;
    printf("First equation with x = 5: %i\n", res1);

    // part 2;
    int res2 = (2-3) / (1+2*(3 / pow(0+3, 3)));
    printf("Second equation with a = 2, b = 1, c = 3, d = 0: %i\n", res2);

    // part 3;
    int mvyvar = 3 * (5 <= 12); // will multiply with boolean (0 || 1) of logical exp.
    printf("Third equation with a = 5, b = 12: %i\n", mvyvar);

    //part 4; // commented as it wont work. SIGSEPE ERROR
    //const int nulldivisorconst = 0;
    //int nulldivisor = 0;
    // printf("What happens when i devide by Zero as a const? %i\n", 5 / nulldivisorconst);
    // printf("And what will happen, if i devide by a zero as a var?: %i\n", 3 / nulldivisor);

    // part 5;
    const float nulldivisorconst = 0.0;
    float nulldivisor = 0.0;
    printf("What happens when i devide by Zero as a const? %f\n", 5 / nulldivisorconst);
    printf("And what will happen, if i devide by a zero as a var?: %f\n", 3 / nulldivisor);
    printf("inf means infinite - output after division by float 0.0\n");

}
int* senary_addition(int senary1[], int senary2[]){
    static int erg[4] = {NULL};
    int overflow = 0;
    for (int i = 3; i > -1 ; --i) {
        if (senary1[i] + senary2[i] + overflow>= 6){
            (printf("Sum of %i and %i would be: %i"));
            erg[i] = ( senary1[i] + senary2[i] + overflow ) % 6;
            erg[i+1] = ( senary1[i] + senary2[i] + overflow ) - 6;
        }
        else{
            erg[i] = (senary2[i] + senary1[i] + overflow);
        }
    }
}

void exercise2_conversion(){
    int senary[4] = {1,2,3,4}; // means Senary XXXX ->[0][1][2][3]
    int senary2[4] = {0,2,0,0};
    int decimalconv = senary[0] * (6 ^ 4) + senary[1] * (6 ^3) + senary[2] * (6 ^ 2) + senary[1] * (6 ^ 1) + senary[3];
    printf("Your decimal is: %i", decimalconv);
    printf("Addition with 0: %i ", senary_addition(senary, senary2)[1]);

}
