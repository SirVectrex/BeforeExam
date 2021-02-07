//
// Created by flori on 07.02.2021.
//

#include "mainstruct.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void mainstruct_build(){
    struct airplane{
        char manufacturer[20];
        char model[10];
        int seats;
        int amount;
    };

    struct airline{
        char name[40];
        char country[30];
        struct airplane fleet[20];
    };
    struct airline myairlines[5];
    printf("%i", sizeof(struct airline));
    struct airline * lufthansa = calloc(1 , sizeof(struct airline));
    strcpy_s(lufthansa->name,sizeof(lufthansa->name),"Lufthansa AG");
    printf("%s",lufthansa->name);

}