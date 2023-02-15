char get_key_pressed() {
    while (Serial.available() != 0) {
        char key = Serial.read();
        Serial.println(key + " pressed");
        return key;
    }
}