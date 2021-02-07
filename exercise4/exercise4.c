//
// Created by flo on 06.02.21.
//

#include "exercise4.h"
#include "stdio.h"

void exercise4_salesman(){
    int amount = 0;
    float price = 0;
    printf("Please enter how many DVD's you'd love to buy: ");
    scanf("%i", &amount);
    if(amount > 99){
        price = (amount * 0.8) * 0.92;
    }
    else if(amount > 49){
        price = (amount * 0.8) * 0.95;
    }
    else if(amount > 9){
        price = (amount * 0.8) * 0.97;
    }
    else{
        price = (amount * 0.8);
    }
    printf("Please pay: %.2f", price);
}

void exercise4_day_calc(){
    int tag = 7;
    int monat = 2;
    int jahr = 2021;

    if(monat <= 2){
        monat = monat +12;
        jahr = jahr -1;
    }

    int weekday = (tag + 2 * monat + (3 * monat + 3 )/5 + jahr + jahr / 4 - jahr / 100 + jahr/ 400 +1  ) % 7;
    printf("%i", weekday);
}

void exercise4_binarysum(unsigned  char summ1, unsigned char summ2){
    int overflow = 0;
    unsigned int sum = 0;
    for (int i = 0; i < 8; ++i) {
        int current = (summ1 >> i & 1) & (summ2 >> i & 1);
        //printf("Current: %i", current);
        if( (current == 1 && overflow == 1)){
            sum = overflow << i;
            overflow = 1;
        }
        else if(current == 1 && overflow == 0){
            sum = overflow << i;
            overflow = 1;
        }
        else if(current == 0 && overflow == 1){
            sum = overflow << i;
            overflow = 0;
        }
        else if(current == 0 && overflow == 0){
            int adder = (summ1 >> i & 1) | (summ2 >> i & 1);
            sum = sum | adder << i;
            overflow = 0;
        }

    }
    printf("Summary is: %i", sum);
}

void exercise4_callbinarysumm(){
    unsigned  char summ1 = 0b00000100; // 0b 0011 1100
    unsigned char summ2 = 0b00000001; // 0b 0000 0001 -> 0b 0000 0010
    exercise4_binarysum(summ1, summ2);
}

