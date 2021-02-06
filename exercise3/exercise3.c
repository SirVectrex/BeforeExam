//
// Created by flo on 06.02.21.
//

#include "exercise3.h"
#include "Printer.h"
#include "stdio.h"

extern unsigned short register1;
extern unsigned short register2;
extern unsigned short register3;

void exercise3_start(){
    unsigned short Output_Timing = 100; // 1100100
    unsigned char LineFeed_Handling = 2; // 10
    unsigned char Space_Handling = 1; // 1 -> / 0b 0000 1100 1000 1001
    unsigned char Page_Size;
    unsigned char Junk_Size;
    unsigned char Char_Size;
    unsigned char End_Page;
    unsigned char Start_Page;
/*
* Hier input handling einfügen
*/
    register1 = Output_Timing;                      // 0b 0000 0000 0000 0000
    register1 <<= 3;
    register1 = register1 | LineFeed_Handling;
    register1 = register1 << 2;
    register1 = register1 | Space_Handling;
    printf("Register 1: %i", register1);

    register2 = Page_Size;
    register2 <<= 6;
    register2 |= Junk_Size;
    register2 <<= 4;
    register2 |= Char_Size;

    register3 = End_Page;
    register3 <<= 7;
    register3 |= Start_Page;
/*
* Register2 setzen
* Register3 setzen
*/
// Pfad anpassen! '\' muss escaped werden '\\'
    // startPrinter("C:\\C-Standard.txt");

    return;
}



/*
 * Register:       0b 0000 0000 0000 0000
 * Input    : 0b 0000 1111 1111 1111
 *  --->   :          1111 1111 1110 0000
 *
 *
 *
 */