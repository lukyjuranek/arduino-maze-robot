void servos_attach() {
    // Attach servos if they are not attached
    if (!leftServo.attached()){
        leftServo.attach();
    }

    if (!rigthServo.attached()){
        rigthServo.attach();
    }
}

void servos_detach() {
    // Detach servos if they are attached
    if (leftServo.attached()){
        leftServo.detach();
    }

    if (rigthServo.attached()){
        rigthServo.detach();
    }
}

void right_servo_run(int servo_velocity) {
    servo_velocity = 180 - servo_velocity;
    rigthServo.write(servo_velocity * MAIN_SPEED);
}

void left_servo_run(int servo_velocity) {
    leftServo.write(servo_velocity * MAIN_SPEED);
}

void go_forward() {
    servos_attach();
    left_servo_run(180);
    right_servo_run(180);
}

void go_backward() {
    servos_attach();
    left_servo_run(0);
    right_servo_run(0);
}

void rotate_left() {
    servos_attach();
    left_servo_run(0);
    right_servo_run(180);
}

void rotate_right() {
    servos_attach();
    left_servo_run(180);
    right_servo_run(0);
}

void stop() {
    servos_attach();
    left_servo_run(90);
    right_servo_run(90);
}
