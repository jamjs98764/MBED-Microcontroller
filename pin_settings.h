#include "mbed.h"
/* Specifying States and variables */

Serial pc(USBTX, USBRX);
AnalogIn light_pin(PTB0);  
DigitalOut buzzer_enable(PTD7);
Rtc_Ds1307 rtc(PTE0, PTE1);
AnalogIn voltage_input(PTC2);
DigitalIn change_alarm(PTA5);
DigitalIn change_time(PTA6);
DigitalIn change_min(PTC16);
DigitalIn change_hour(PTA8);
//TextLCD lcd(p15, p16, p17, p18, p19, p20); 
//TextLCD lcd(PTC1, PTC2, PTB3, PTB2, PTB1, PTB0); 