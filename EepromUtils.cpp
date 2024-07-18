#include "EepromUtils.h"

// ============================================
void writeUnsignedLongInEeprom(int address, unsigned long in_) {

  EEPROM.write(address, (in_ >> 24) & 0xFF);  // the AND operator (0xFF) to keep only the 8 bits that we want
  EEPROM.write(address + 1, (in_ >> 16) & 0xFF);
  EEPROM.write(address + 2, (in_ >> 8) & 0xFF);
  EEPROM.write(address + 3, in_ & 0xFF);
  EEPROM.commit();
  DPRINTLN("wrote unsigned long in EEPROM");
}
// ===========================================
unsigned long readUnsignedLongFromEeprom(int address) {
  DPRINTLN("read unsigned long from EEPROM ");
  return ((unsigned long)EEPROM.read(address) << 24) +
         ((unsigned long)EEPROM.read(address + 1) << 16) +
         ((unsigned long)EEPROM.read(address + 2) << 8) +
         (unsigned long)EEPROM.read(address + 3);
}
// ============================================
void writeCharArrayAndLenInEeprom(int address ,const char* inputPass) {
  byte len = strlen(inputPass);
  EEPROM.write(address, len);

  for (int i = 0; i < len; i++) {
    EEPROM.write(address + 1 + i, inputPass[i]);
  }
  EEPROM.commit();
  DPRINTLN("wrote state in EEPROM");
}
//==========================================
char* readCharArrayFromEeprom(int address) {
  int len = EEPROM.read(address);
  char result[len + 1];
  
  for (int i = 0; i < len; i++) {
    result[i] = EEPROM.read(address + 1 + i);
  }
  result[len] = '\0';
  DPRINT("result: ");
  DPRINTLN(result);
  return result;
}
//==========================================
void writeBoolInEeprom(int addr, bool bool_){
   EEPROM.write(addr, bool_);
   EEPROM.commit();
   DPRINTLN("wrote bool in EEPROM ");
}
// =========================================
bool readBoolFromEeprom(int addr){
  DPRINTLN("read bool from EEPROM ");
  return EEPROM.read(addr);
}
