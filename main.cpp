#include "TextLCD.h"
#include "mbed.h"
#include "Rtc_Ds1307.h"
//#include "analog_change.cpp"
#include "pin_settings.h"


//Declare functions//
int light_state();  //Compare brightness with nominal brightness of lit room
int buzzer_state(Rtc_Ds1307::Time_rtc &arg1 , Rtc_Ds1307::Time_rtc &arg2); //Compare time with alarm time


int alarm_minute(AnalogIn v_input) {
    while(1) {
               
        float voltage;
        int minutes;
        voltage = v_input.read();
        
        //printf("percentage voltage = %f\n\r",voltage);
        if (voltage >= 0.0 && voltage < 0.08){
            minutes = 0;
            }
        else if (voltage >= 0.08 && voltage < 0.28){
            minutes = 5;
            }
        else if (voltage >= 0.28 && voltage < 0.38){
            minutes = 10;
            }
        else if (voltage >= 0.38 && voltage < 0.50){
            minutes = 15;      
            }
        else if (voltage >= 0.50 && voltage < 0.64){
            minutes = 20;
            }
        else if (voltage >= 0.64 && voltage < 0.78){
            minutes = 25;
            }
        else if (voltage >= 0.78 && voltage < 0.82){
            minutes = 30;
            }
        else if (voltage >= 0.82 && voltage < 0.85){
            minutes = 35;
            }
        else if (voltage >= 0.85 && voltage < 0.88){
            minutes = 40;
            }
        else if (voltage >= 0.88 && voltage < 0.91){
            minutes = 45;
            }
        else if (voltage >= 0.91 && voltage < 0.95){
            minutes = 50;
            }
        else {
            minutes = 55;
            }

        //pc.printf("Minutes: %d \n\r",minutes );
//        pc.printf("abc");
//        wait(1);
        
        return minutes;
    }
}


int alarm_hour(AnalogIn v_input) {
    while(1) {
               
        float voltage;
        int hours;
        voltage = v_input.read();
        
        //printf("percentage voltage = %f\n\r",voltage);
        if (voltage >= 0.0 && voltage < 0.08){
            hours = 12;
            }
        else if (voltage >= 0.08 && voltage < 0.28){
            hours = 1;
            }
        else if (voltage >= 0.28 && voltage < 0.38){
            hours = 2;
            }
        else if (voltage >= 0.38 && voltage < 0.50){
            hours = 3;      
            }
        else if (voltage >= 0.50 && voltage < 0.64){
            hours = 4;
            }
        else if (voltage >= 0.64 && voltage < 0.78){
            hours = 5;
            }
        else if (voltage >= 0.78 && voltage < 0.82){
            hours = 6;
            }
        else if (voltage >= 0.82 && voltage < 0.85){
            hours = 7;
            }
        else if (voltage >= 0.85 && voltage < 0.88){
            hours = 8;
            }
        else if (voltage >= 0.88 && voltage < 0.91){
            hours = 9;
            }
        else if (voltage >= 0.91 && voltage < 0.95){
            hours = 10;
            }
        else {
            hours = 11;
            }

        //pc.printf("Hours: %d \n\r",hours );
//        pc.printf("abc");
//        wait(1);
        
        return hours;
    }
}
 
/* Setting time structure */
Rtc_Ds1307::Time_rtc tm1 ; //current time data structure
Rtc_Ds1307::Time_rtc atm ; //alarm time data structure


/* 
Main function, which includes:
i. LCD Display updating with time increment
ii. Controls Buzzer State
iii. Detects Light Sensor State
iv. Changes alarm time
*/
 
int main() {
    
    pc.printf("Enter the current time (hours 0..23)\n\r");  //Request hour
    pc.scanf("%d", &tm1.hour);                          //User enters hour
    pc.printf("Enter the current time (minutes 0..59)\n\r");//Request minutes
    pc.scanf("%d", &tm1.min);                           //User enters minutes
    pc.printf("Enter the current time (seconds 0..59)\n\r");//Request seconds
    pc.scanf("%d", &tm1.sec);                           //User enters seconds

    pc.printf("Set the alarm time (hours 0..23)\n\r");   //Request alarm hour
    pc.scanf("%d", &atm.hour);                       //User enters alarm hour
    pc.printf("Set the alarm time (minutes 0..59)\n\r"); //Request alarm minutes
    pc.scanf("%d", &atm.min);                        //User enters alarm minutes
    pc.printf("Set the alarm time (seconds 0..59)\n\r"); //Request alarm seconds
    pc.scanf("%d", &atm.sec);                        //User enters alarm seconds
    
    pc.printf("Performing write operation\n\r");     //Writing time to memory
    
    rtc.setTime(tm1,true, true);
    
    rtc.getTime(tm1);
    
    //Local Variables
    int buzzer = 0;
    int light = 0;
      
     //Time counter
    for ( ; ; )
    {
        //Determine alarm state
        printf("Change_time is: %d\n\r", change_time.read());
        printf("Change_alarm is: %d\n\r", change_alarm.read());
        printf("Change_min is: %d\n\r", change_min.read());
        printf("Change_hour is: %d\n\r", change_hour.read());
        printf("Analog voltage input is: %f \n\r", voltage_input.read());
        
        if (change_alarm == 1 ) {       
            if ( change_min == 1 ){
                int changed_min = alarm_minute(voltage_input);
                atm.min = changed_min;
                }
            else {
                int changed_hour = alarm_hour(voltage_input);
                atm.hour = changed_hour;
                }
        }
        
        if (change_time == 1 ) {       
            if ( change_min == 1 ){
                int changed_min = alarm_minute(voltage_input);
                tm1.min = changed_min;
                }
            else {
                int changed_hour = alarm_hour(voltage_input);
                tm1.hour = changed_hour;
                }
            rtc.setTime(tm1,true, true);
        }
        
        rtc.getTime(tm1);
        printf("Current second time is: %d\n\r", tm1.sec);
        printf("Alarm minute time is: %d\n\r", atm.min);
        buzzer = buzzer_state(atm,tm1);
        light = light_state();
        if (buzzer == 1 && light == 1) {
            buzzer_enable = 1;
            }
        wait (5);
        
        
    }
}


/* Function for light sensor*/

//Function returns 0 when the light is on and 1 when the light is off//
//An LDR is used to measure the brightness of the alarm clock's surroundings
//In dimly lit conditions, brightness>0.8. In a bright room, brightness~0.6

int light_state() {
    
    //Declare local variables//
    int state = 0;
    
    float brightness = light_pin;   //Create brightness
if (brightness < 0.8){              //Compare brightness level with
        state = 0;                  //nominal lit room conditions
        }                           //Return 0 if light is on 
    else{
        state = 1;                  //Return 1 if light is off
    }
    return state;
}
     
/* END */



/* Function for buzzer ON/OFF */

//Function returns 1 when time==alarm time and 0 when time!=alarm time//

int buzzer_state(Rtc_Ds1307::Time_rtc &arg1 , Rtc_Ds1307::Time_rtc &arg2) {

    //Declare local variables//
    int state = 0;
        
    if( arg1.sec == arg2.sec && arg1.min == arg2.min && arg1.hour == arg2.hour ) {
        state = 1;           //buzzer is switched on when time == alarm time
        }
    else{
        state = 0;            //otherwise the alarm is switched off
        }
    return state;
}





/*END*/