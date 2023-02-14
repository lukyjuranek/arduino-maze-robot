void right_servo_run(int servo_velocity) {
    rigthServo.write(servo_velocity * MAIN_SPEED);
}

void left_servo_run(int servo_velocity) {
    servo_velocity = 180 - servo_velocity;
    leftServo.write(servo_velocity * MAIN_SPEED);
}

void go_forward() {
    left_servo_run(90);
    right_servo_run(90);
}

void go_backward() {
    left_servo_run(0);
    right_servo_run(0);
}

void turn_left() {
    left_servo_run(0);
    right_servo_run(90);
}

void turn_right() {
    left_servo_run(90);
    right_servo_run(0);
}

void stop() {
    // left_servo_run(0);
    // right_servo_run(0);
}