/*
Author: Lukas Juranek
Description: This Arduino project controls a two-wheeled robot with two ultrasonic sensors. The robot can be controlled with a keyboard, or set to self-drive and avoid obstacles. 
*/

#include <Servo.h>
Servo leftServo;
Servo rigthServo;

// Pins for the ultrasonic sensors
#define TRIG_PIN_RIGHT 4
#define ECHO_PIN_RIGHT 3
#define TRIG_PIN_LEFT 6
#define ECHO_PIN_LEFT 5
// Pins for the servos
#define RIGHT_SERVO_PIN 10
#define LEFT_SERVO_PIN 9

int SAFETY_DISTANCE = 10;  // cm
float MAIN_SPEED = 1.0;    // 0.0-1.0 used to slow down all the movements, affects the functionality beacasue the movements are based on time so slowing it down will make the robot make smaller movements and might make it act differently
bool selfdriving = true;
bool print_instructions = false;
bool print_debug_info = false;

void setup() {
    // Sets the pins to output or input
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(TRIG_PIN_RIGHT, OUTPUT);
    pinMode(ECHO_PIN_RIGHT, INPUT);
    pinMode(TRIG_PIN_LEFT, OUTPUT);
    pinMode(ECHO_PIN_LEFT, INPUT);
    Serial.begin(9600);
    // Assigns servo pins
    servos_attach();
    // Prints the instructions
    if (print_instructions) {
        print_keyboard_controls_instructions();
    }

    // Makes the led blink 3 times and moves the robot forward and backward
    if (selfdriving) {
        selfdriving_start_sequence();
    }
}

void loop() {
    // Careful, this is slows down the robot
    if (print_debug_info) {
        // Prints the distance from the left and right sensors
        print_sonar_info();
        delay(500);  // Makes the printing slower
    }

    // Runs the selfdriving if it is enabled
    // Checks the obstacle position and moves accordingly
    if (selfdriving) {
        seldriving_loop();
    }

    keyboard_controls(get_key_pressed());
}
