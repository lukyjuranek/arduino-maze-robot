#include <Servo.h>
Servo leftServo;
Servo rigthServo;

// Pins for the ultrasonic sensors
#define TRIG_PIN_RIGHT 4
#define ECHO_PIN_RIGHT 3
#define TRIG_PIN_LEFT 5
#define ECHO_PIN_LEFT 6
// TODO: check pins

int SAFETY_DISTANCE = 10; // cm
int MAIN_SPEED = 1;  // 0-1 used to slow down all the movements
int action = 0; // 0 - stop, 1 - forward, 2 - right, 3 - backward, 4 - left
// int obstacle_position = 0; // 0 - none, 1 - left, 2 - front, 3 - right
bool autopilot = false;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(TRIG_PIN_RIGHT, OUTPUT);
    pinMode(ECHO_PIN_RIGHT, INPUT);
    pinMode(TRIG_PIN_LEFT, OUTPUT);
    pinMode(ECHO_PIN_LEFT, INPUT);
    Serial.begin(9600);
    // Assign servo pins
    leftServo.attach(9);
    rigthServo.attach(10);
    // Check if servos are attached
    Serial.println(leftServo.attached());
    Serial.println(rigthServo.attached());

    Serial.println("Press w, a, s, d to move the robot");
    Serial.println("Press q to stop the robot");
    Serial.println("Press l to make the led blink");
    Serial.println("Press t to toggle the servos");
    Serial.println("Press a to toggle the autopilot");
}

void loop() {
    // Prints the distance from the left and right sensors
    Serial.print("Distance left: ");
    Serial.print(get_distance_cm(ECHO_PIN_LEFT, TRIG_PIN_LEFT));
    Serial.print(" Distance right: ");
    Serial.println(get_distance_cm(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT));
    Serial.print("Obstacle position: ");
    Serial.println(obstacle_position());

    // Prints the wall angle if there is a wall in front
    if(obstacle_position() == 2){
        Serial.println("Front wall angle: ");
        Serial.println(wall_angle());
    }

    // Changes the action based on the pressed key
    if (is_pressed('w')) {
        action = 1;
    } else if (is_pressed('d')) {
        action = 2;
    } else if (is_pressed('s')) {
        action = 3;
    } else if (is_pressed('a')) {
        action = 4;
    } else if (is_pressed('q')) {
        action = 0;
    } else if (is_pressed('l')) {
        led_blink(100);
    } else if (is_pressed('t')) {
        led_toggle();
    } else if (is_pressed('a')) {
        autopilot = !autopilot;
        Serial.println("Toggling autopilot. autopilot = " + String(autopilot));
    } else {
        action = 0;
    }

    // Executes the action
    switch (action) {
        case 0:
            stop();
            break;
        case 1:
            go_forward();
            break;
        case 2:
            turn_right();
            break;
        case 3:
            go_backward();
            break;
        case 4:
            turn_left();
            break;
        case 5:
            autopilot_loop();
            break;
        default:
            stop();
            break;
    }
}