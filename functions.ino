bool is_pressed(char key) {
    while (Serial.available() != 0) {
        char character = Serial.read();
        if (character == key) {
            return true;
        }
    }
}