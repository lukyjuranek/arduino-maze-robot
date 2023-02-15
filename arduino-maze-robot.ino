#include <Servo.h>
Servo leftServo;
Servo rigthServo;

// Pins for the ultrasonic sensors
#define TRIG_PIN_RIGHT 2
#define ECHO_PIN_RIGHT 1
#define TRIG_PIN_LEFT 4
#define ECHO_PIN_LEFT 3

int SAFETY_DISTANCE = 15; // cm
float MAIN_SPEED = 1.0; // 0-1 used to slow down all the movements
String action = ""; // stop, forward, right, backward, left
// int obstacle_position = 0; // 0 - none, 1 - left, 2 - front, 3 - right
bool autopilot = false;
char key_pressed;

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
    Serial.println("Press w, a, s, d to move the robot");
    Serial.println("Press q to stop the robot");
    Serial.println("Press l to make the led blink");
    Serial.println("Press t to toggle the servos");
    Serial.println("Press i to toggle the autopilot");
    Serial.println("Press e to detach the servos which stops the robot");
}

void loop() {
    Serial.print("Action: " + action);
    Serial.print(" ServoL: " + leftServo.read());
    Serial.println(" ServoR: " + rigthServo.read());

    // Prints the distance from the left and right sensors
    Serial.print("SonarL: " + String(get_distance_cm(ECHO_PIN_LEFT, TRIG_PIN_LEFT)));
    Serial.print(" SonarR: " + String(get_distance_cm(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT)));
    Serial.print("Obstacle pos: " + String(obstacle_position()));

    // Prints the wall angle if there is a wall in front
    if (obstacle_position() == "front") {
        Serial.print(" Wall angle: " + String(wall_angle()));
    }
    Serial.println();

    delay(200);

    key_pressed = get_key_pressed();
    Serial.print(key_pressed + " pressed");

    // Changes the action based on the pressed key
    if (key_pressed == 'w') {
        action = "forward";
        go_forward();
        Serial.println("Moving forward");

    } else if (key_pressed == 'd') {
        action = "right";
        rotate_right();
        Serial.println("Turning right");

    } else if (key_pressed == 's') {
        action = "backward";
        go_backward();
        Serial.println("Moving backward");

    } else if (key_pressed == 'a') {
        action = "left";
        rotate_left();
        Serial.println("Turning left");

    } else if (key_pressed == 'q') {
        action = "stop";
        stop();
        Serial.println("Stopping");

    } else if (key_pressed == 'e') {
        action = "detach_servos";
        servos_detach();
        Serial.println("Detaching servos");

    } else if (key_pressed == 'l') {
        led_blink(100);
        Serial.println("Blinking led");

    } else if (key_pressed == 't') {
        led_toggle();
        Serial.println("Toggling led");

    } else if (key_pressed == 'i') {
        autopilot = !autopilot;
        Serial.println("Toggling autopilot. autopilot = " + String(autopilot));
        
    } else {
        ;
    }

    if (autopilot) {
        autopilot_loop();
    }

    //
    //    // Make the switch stataement into and if else
    //    if (action == 0) {
    //        stop();
    //    } else if (action == 1) {
    //        go_forward();
    //    } else if (action == 2) {
    //        rotate_right();
    //    } else if (action == 3) {
    //        go_backward();
    //    } else if (action == 4) {
    //        rotate_left();
    //    } else if (action == 5) {
    //        autopilot_loop();
    //    } else {
    //        stop();
    //    }
}
