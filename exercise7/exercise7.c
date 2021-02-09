//
// Created by flori on 08.02.2021.
//

#include "exercise7.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int myarray[20] = {NULL};
int counticount = 0;

void fillarray(){
    int counter = 0, input= 0;
    do {
        printf("Please enter the next number.");
        scanf_s("%i", &input);
        if(input < 0){
            printf("Break set.");
            break;
        }
        else {
            myarray[counter] = input;
            counticount++;
        }
    }   while (input < sizeof(myarray)/sizeof(int));
}

void autofill(){
    for (int i = 0; i < 20; ++i) {
        myarray[i] = rand();
    }
    counticount = 20;
    printf("Array filled.\n");
}

void arraystats(){
    int min = INT_MAX, max = INT_MIN;
    long sum = 0;
    for (int i = 0; i < counticount; ++i) {
        sum += myarray[i];
        if (min > myarray[i]){ min = myarray[i]; }
        if (max < myarray[i]){ max = myarray[i]; }

    }
    printf("\n--Average of all inputs is: %f", (float )sum/counticount+1);
    printf("\n--Minimum number in Array: %i", min);
    printf("\n--Maximum number in Array: %i", max);
}

void sortarray(){
    // will use bubblesort technique
    short change = 1;
    int end = 0;
    int index = 0, helper = 0;
    while (change == 1){
        change = 0;
        for (int i = 0; i < counticount-end; ++i) {
            if (myarray[i] > myarray[i+1] && i +1 < counticount){
                helper = myarray[i];
                myarray[i] = myarray[i+1];
                myarray[i+1] = helper;
                change = 1;
            }
        }
        end--;
    }

}

void printarray(){
    printf("\n Array = ");
    for (int i = 0; i < sizeof(myarray)/sizeof(int ); ++i) {
        printf("\n --> %i",myarray[i] );
    }
}

void exercise7_start(){
    autofill();
    //fillarray();
    printarray();
    arraystats();
    sortarray();
    printarray();

}
