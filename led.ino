void led_on() {
    digitalWrite(LED_BUILTIN, HIGH);
}

void led_off() {
    digitalWrite(LED_BUILTIN, LOW);
}

void led_blink(int time) {
    led_off();  // in case it was on already
    delay(time);
    led_on();
    delay(time);
    led_off();
}

void led_toggle() {
    if (digitalRead(LED_BUILTIN) == HIGH) {
        led_off();
    } else {
        led_on();
    }
}