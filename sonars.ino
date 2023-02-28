long get_distance_cm(int trig_pin, int echo_pin) {
    long duration, distance_cm;
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
    duration = pulseIn(echo_pin, HIGH);
    // int distance = duration * 0.034 / 2;
    distance_cm = (duration / 2) / 29.1;
    return distance_cm;
}

String obstacle_position() {
    // returns: none, left, front or right
    double distance_left = get_distance_cm(TRIG_PIN_LEFT, ECHO_PIN_LEFT);
    double distance_right = get_distance_cm(TRIG_PIN_RIGHT, ECHO_PIN_RIGHT);
    if (distance_left < SAFETY_DISTANCE && distance_right < SAFETY_DISTANCE) {
        return "front";
    } else if (distance_left < SAFETY_DISTANCE) {
        return "left";
    } else if (distance_right < SAFETY_DISTANCE) {
        return "right";
    }
    return "none";
}

void print_sonar_info() {
    Serial.print("SonarL: " + String(get_distance_cm(TRIG_PIN_LEFT, ECHO_PIN_LEFT)));
    Serial.print(" SonarR: " + String(get_distance_cm(TRIG_PIN_RIGHT, ECHO_PIN_RIGHT)));
    Serial.println(" Obstacle pos: " + String(obstacle_position()));
}
