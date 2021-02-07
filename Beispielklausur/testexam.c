//
// Created by flori on 07.02.2021.
//

#include "testexam.h"
#include "stdio.h"

unsigned short Reg_SSEG;

void testexam_bitoperators(){
    char todisplay = NULL;
    printf("Please enter the digit to display");
    scanf_s("%i", &todisplay);
    switch (todisplay) {
        case 5:{
            // Reg_SSEG = REG_SSG & --> äquivalent zu Reg_SSEG &= ...
            Reg_SSEG = Reg_SSEG & ~0b0000000000000001;// ausschalten
            Reg_SSEG = 0b1101101000000000; // 1101 1010 0000 0000
            // change to 5 ( turn on 4,5,7,2,1) -> turn bit 15, 14, 12, 11, 9 to '1' -> 0b 1101 1010 0000 0000
            Reg_SSEG = Reg_SSEG | ~0b0000000000000001;// anschalten
        }
        case 6:{
            Reg_SSEG = Reg_SSEG & ~0b0000000000000001;// ausschalten
            Reg_SSEG = 0b1111101000000000; // 1101 1010 0000 0000
            // change to 6 ( turn on 4,5,6,7,2,1) -> turn bit 15, 14,13, 12, 11, 9 to '1' -> 0b 1111 1010 0000 0000
            Reg_SSEG = Reg_SSEG | ~0b0000000000000001;// anschalten
        }
        case 7:{
            Reg_SSEG = Reg_SSEG & ~0b0000000000000001;// ausschalten
            Reg_SSEG = 0b1010010000000000; // 1101 1010 0000 0000
            // change to 5 ( turn on 4,3,2) -> turn bit 15, 13, 10 to '1' -> 0b 1010 0100 0000 0000
            Reg_SSEG = Reg_SSEG | ~0b0000000000000001;// anschalten
        }
        default:{
            printf("Please enter a valid number");
        }

    }
}

void testexam_fields_and_strings_pointerversion(char * mystring){
    char * ptr1 = mystring;
    char * ptr2 = mystring +1;
    while (*ptr1 != '\0'){
        if(*ptr1 != ' ' && *ptr2 != ' ' && *ptr2 != '\0'){
            char helpptr = *ptr2;
            *ptr2 = *ptr1;
            *ptr1 = helpptr; // ERROR
            ptr1 += 2;
            ptr2 +=2;
        }
        else{
            ptr2++;
            ptr1++;
        }
    }
    printf("New string = %s", mystring);

}

void testexam_fields_and_strings_pointerversion_start(){
    char txt_to_change[] = "hTsi si osem hstiyt ettx";
    testexam_fields_and_strings_pointerversion(txt_to_change);
    printf("%s", txt_to_change);
}

void testexam_fiels_and_strings_arrayversion(char message[]){
    int counter = 0;
    char helper = 0;
    printf("%s\n", message);
    while(message[counter] != '\0'){
        if(message[counter] != ' ' && message[counter+1] != ' ' && message[counter+1] != '\0') {
            char helper = message[counter];
            message[counter] = message[counter + 1];
            message[counter + 1] = helper;
            counter += 2;
        }
        else{
            counter++;
        }
    }
    printf("Output:\n%s", message);
}

void testexam_fields_and_strings_arrayversion_start(){
    char txt_to_change[] = "hTsi si osem hstiyt ettx";
    testexam_fiels_and_strings_arrayversion(txt_to_change);
    printf("\nNew orig dest: %s", txt_to_change);
}

struct  MotorData_t{
    unsigned FahrGestNr;
    short Hubraum;
    short Leistung;
    unsigned Kilometer;
    char Zylinder;
};

struct ExterieurData_t{
    unsigned FahrGestNr;
    unsigned Farbe;
    unsigned AnzTueren;
    unsigned Laenge;
    // will miss out on rest as not needed
};

// will only init field of 100 (nobody got time and ram for more)
struct MotorData_t Motordata[100] = {NULL};
struct ExterieurData_t ExterieurData[100] = {NULL};

struct pricetag{
    int Hubraum;
    int Kilometerstand;
    int Leistung;
    int FarbID;
    short Tueren;

};

struct pricetag testexam_datastructs(int FGNR){
    static struct pricetag mypricetag;
    int motorindex = -1, extindex = -1;
    for (int i = 0; i < 100; ++i) {
        if(Motordata[i].FahrGestNr == FGNR){
            motorindex == i;
        }
        if (ExterieurData[i].FahrGestNr == FGNR){
            extindex = i;
        }
        if (extindex != -1 && motorindex != -1){
            break;
        }
    }
    mypricetag.FarbID = ExterieurData[extindex].Farbe;
    mypricetag.Hubraum = Motordata[motorindex].Hubraum;
    mypricetag.Kilometerstand = Motordata[motorindex].Kilometer;
    mypricetag.Leistung = Motordata[motorindex].Leistung;
    mypricetag.Tueren = ExterieurData[extindex].AnzTueren;

    return mypricetag;

}