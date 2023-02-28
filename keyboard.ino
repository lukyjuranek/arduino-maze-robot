char get_key_pressed() {
    while (Serial.available() != 0) {
        char key = Serial.read();
        Serial.println(key + " pressed");
        return key;
    }
}

void print_keyboard_controls_instructions() {
    Serial.println("Press w, a, s, d to move the robot");
    Serial.println("Press q to stop the robot");
    Serial.println("Press l to make the led blink");
    Serial.println("Press t to toggle the LED");
    Serial.println("Press i to toggle the selfdriving");
    Serial.println("Press e to detach the servos which stops the robot");
}

void keyboard_controls(char key_pressed) {
    // Changes the action based on the pressed key
    if (key_pressed == 'w') {
        go_forward();
        Serial.println("Moving forward");

    } else if (key_pressed == 'd') {
        rotate_right();
        Serial.println("Turning right");

    } else if (key_pressed == 's') {
        go_backward();
        Serial.println("Moving backward");

    } else if (key_pressed == 'a') {
        rotate_left();
        Serial.println("Turning left");

    } else if (key_pressed == 'q') {
        stop();
        Serial.println("Stopping");

    } else if (key_pressed == 'e') {
        servos_detach();
        Serial.println("Detaching servos");

    } else if (key_pressed == 'l') {
        led_blink(100);
        Serial.println("Blinking led");

    } else if (key_pressed == 't') {
        led_toggle();
        Serial.println("Toggling led");

    } else if (key_pressed == 'i') {
        // Toggles the selfdriving
        selfdriving = !selfdriving;
        Serial.println("Toggling selfdriving. selfdriving = " + String(selfdriving));
    }
}