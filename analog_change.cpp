//OBSOLETE: We have moved functions into main()

/*

Two functions to set hour and minute hand



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

*/