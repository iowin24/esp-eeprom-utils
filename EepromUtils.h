#ifndef EepromUtils_h
#define EepromUtils_h
  
#include <FS.h> 
#include <EEPROM.h>

#define DEBUG   //If you comment this line, the DPRINT & DPRINTLN lines are defined as blank.
#ifdef DEBUG    //Macros are usually in all capital letters.
#define DPRINT(...)    Serial.print(__VA_ARGS__)     //DPRINT is a macro, debug print
#define DPRINTLN(...)  Serial.println(__VA_ARGS__)   //DPRINTLN is a macro, debug print with new line
#define DPRINTLN5SEC(...)  dprintlnEvery5Sec(__VA_ARGS__)   //DPRINTLN is a macro, debug print with new line

#else
#define DPRINT(...)     //now defines a blank line
#define DPRINTLN(...)   //now defines a blank line
#define DPRINTLN5SEC(...)  //now defines a blank line
#endif


void writeUnsignedLongInEeprom(int address, unsigned long diffSec_) ;

unsigned long readUnsignedLongFromEeprom(int address);

void writeCharArrayAndLenInEeprom(int address ,const char* inputPass);

char* readCharArrayFromEeprom(int address);

void writeBoolInEeprom(int addr, bool bool_);

bool readBoolFromEeprom(int addr);

#endif