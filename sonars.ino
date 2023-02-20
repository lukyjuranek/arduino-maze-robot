double get_distance_cm(int trig_pin, int echo_pin) {
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    long duration = pulseIn(echo_pin, HIGH);
    // int distance = duration * 0.034 / 2;
    long distance_cm = duration / 2 * 29.1;
    return distance_cm;
}

double wall_angle(){
    // Calculates the wall angle from the left and right sensors distance
    int distance_left = get_distance_cm(ECHO_PIN_LEFT, TRIG_PIN_LEFT);
    int distance_right = get_distance_cm(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT);
    int angle = 0;
    if (distance_left > distance_right) {
        angle = 90 - (distance_left - distance_right);
    } else if (distance_left < distance_right) {
        angle = 90 + (distance_right - distance_left);
    }

}

String obstacle_position() {
    // 0 - none, 1 - left, 2 - front, 3 - right
    double distance_left = get_distance_cm(ECHO_PIN_LEFT, TRIG_PIN_LEFT);
    double distance_right = get_distance_cm(ECHO_PIN_RIGHT, TRIG_PIN_RIGHT);
    if (distance_left < SAFETY_DISTANCE && distance_right < SAFETY_DISTANCE) {
        return "front";
    } else if (distance_left < SAFETY_DISTANCE) {
        return "left";
    } else if (distance_right < SAFETY_DISTANCE) {
        return "right";
    }
    return "none";
}
