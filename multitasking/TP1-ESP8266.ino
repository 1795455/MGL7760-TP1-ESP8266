// This example shows how two finite state machines can be used to simulate
// multitasking on an arduino. Two LED's are turned on and off at irregular
// intervals; the finite state machines take care of the transitions.

#include "Fsm.h"

//#define led_BLUE D4
//#define led_RED D2

#define led_BLUE 2
#define led_RED 4

int lastMillis_led_RED;
int timeStateOff_led_RED = 1700;
int timeStateOn_led_RED  = 200;

int lastMillis_led_BLUE;
int timeStateOff_led_BLUE = 1000;
int timeStateOn_led_BLUE  = 1000;

void on_led_RED_on_enter();
void on_led_RED_on_state();
void on_led_RED_on_exit();

void on_led_RED_off_enter();
void on_led_RED_off_state();
void on_led_RED_off_exit();

void on_led_BLUE_on_enter();
void on_led_BLUE_off_enter();


//State state_led_RED_on(&on_led_RED_on_enter, &on_led_RED_on_state, &on_led_RED_on_exit);
//State state_led_RED_off(&on_led_RED_off_enter, &on_led_RED_off_state, &on_led_RED_off_exit);

State state_led_RED_on(&on_led_RED_on_enter,NULL,NULL);
State state_led_RED_off(&on_led_RED_off_enter,NULL,NULL);


State state_led_BLUE_on(&on_led_BLUE_on_enter, NULL, NULL);
State state_led_BLUE_off(&on_led_BLUE_off_enter, NULL, NULL);

Fsm fsm_led_RED(&state_led_RED_off);
Fsm fsm_led_BLUE(&state_led_BLUE_off);


void on_led_BLUE_on_enter() {
    Serial.println("on_led_BLUE_on_enter");
    //lastMillis_led_BLUE=millis();
    digitalWrite(led_BLUE, HIGH);
    //digitalWrite(LED_BUILTIN, LOW);
}

void on_led_BLUE_off_enter() {
    Serial.println("on_led_BLUE_off_enter");
    digitalWrite(led_BLUE, LOW);
    //digitalWrite(LED_BUILTIN, HIGH);
}

void on_led_RED_on_enter() {
    Serial.println("on_led_RED_on_enter");
    //lastMillis_led_BLUE=millis();
    digitalWrite(led_RED, HIGH);
}

void on_led_RED_off_enter() {
    Serial.println("on_led_RED_off_enter");
    digitalWrite(led_RED, LOW);
}




void setup() {
    Serial.begin(9600);

    pinMode(led_BLUE, OUTPUT);
    pinMode(led_RED, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    fsm_led_RED.add_timed_transition(&state_led_RED_off, &state_led_RED_on, timeStateOff_led_RED, NULL);
    fsm_led_RED.add_timed_transition(&state_led_RED_on, &state_led_RED_off, timeStateOn_led_RED, NULL);
    
    fsm_led_BLUE.add_timed_transition(&state_led_BLUE_off, &state_led_BLUE_on, timeStateOff_led_BLUE, NULL);
    fsm_led_BLUE.add_timed_transition(&state_led_BLUE_on, &state_led_BLUE_off, timeStateOn_led_BLUE, NULL);
    
}


void loop() {
    fsm_led_RED.run_machine();
    fsm_led_BLUE.run_machine();

    // Test GIT 
    // Test 02

    // Commmit GIT 


}

//cd C:/Users/hhrui/OneDrive/Documents/GitHub/MGL7760-TP1-ESP8266/multitasking
// test pull

