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

void exercise4_binarysum(){
    unsigned  char mychar = 3;
    printf("%c", &mychar );
}

