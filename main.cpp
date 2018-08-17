#include "mbed.h"

//Define buttons
InterruptIn button_red(p5);
InterruptIn button_green(p6);
InterruptIn button_blue(p7);

//Define LED colors
PwmOut led_red(p21);
PwmOut led_green(p22);
PwmOut led_blue(p23);

void inc_red() {
    
    float pwm;
    
    //Read in current PWM value and increment it
    pwm = led_red.read();
    pwm += 0.1f;
    if (pwm > 1.0f) {
        pwm = 0.0f;
    }
    led_red.write(pwm);
    wait(0.1);
}

void inc_green() {
    
    float pwm;
    
    //Read in current PWM value and increment it
    pwm = led_green.read();
    pwm += 0.1f;
    if (pwm > 1.0f) {
        pwm = 0.0f;
    }
    led_green.write(pwm);
    wait(0.1);
}

void inc_blue() {
    
    float pwm;
    
    //Read in current PWM value and increment it
    pwm = led_blue.read();
    pwm += 0.1f;
    if (pwm > 1.0f) {
        pwm = 0.0f;
    }
    led_blue.write(pwm);
    wait(0.1);
}

    
int main() {
    
    //Initialize all LED colors as off
    led_red.write(0.0f);
    led_green.write(0.0f);
    led_blue.write(0.0f);
    
    //Define three interrupts - one for each color
    button_red.fall(&inc_red);
    button_green.fall(&inc_green);
    button_blue.fall(&inc_blue);
    
    // Do nothing! We wait for an interrupt to happen
    while(1) {
    }
}
