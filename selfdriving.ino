void selfdriving_loop() {
    String obstacle = obstacle_position();

    if (obstacle == "none") {
        go_forward();
    } else if (obstacle == "left") {
        rotate_right();
    } else if (obstacle == "right") {
        rotate_left();
    } else if (obstacle == "front") {
        // If there is an obstacle in front, try turning left or right
        rotate_left();
        delay(500);  // Wait for turn to complete
        obstacle = obstacle_position();
        if (obstacle != "front") {
            // If turning left cleared the obstacle, continue in new direction
            go_forward();
        } else {
            // Otherwise, try turning right
            rotate_right();
            delay(500);
            obstacle = obstacle_position();
            if (obstacle != "front") {
                // If turning right cleared the obstacle, continue in new direction
                go_forward();
            } else {
                // Otherwise, reverse
                go_backward();
                delay(500);
            }
        }
    } else {
        // If the obstacle position is not recognized, stop
        // This should never happen but is here to detect bugs in my code
        stop();
    }
    delay(100);
}

void selfdriving_start_sequence() {
    // Makes the led blink 3 times and moves the robot forward and backward
    for (int i = 0; i < 3; i++) {
        led_blink(500);
        // delay(1000);
    }
    go_forward();
    delay(1000);
    go_backward();
    delay(1000);
    stop();
    delay(1000);
}