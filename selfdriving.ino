void seldriving_loop() {
    if(obstacle_position() == "none"){
        // If there is no obstacle, go forward
        go_forward();
    } else if(obstacle_position() == "left"){
        // If there is an obstacle on the left, turn right
        rotate_right();
    } else if(obstacle_position() == "front"){
        // If there is an obstacle in front, turn left
        go_backward();
    } else if(obstacle_position() == "right"){
        // If there is an obstacle on the right, turn left
        rotate_left();
    }
}

void selfdriving_start_sequence(){
    // Makes the led blink 3 times with 1 s delay and rotates left and back
    for (int i = 0; i < 3; i++) {
        led_blink(500);
        delay(1000);
    }
    rotate_left();
    delay(1000);
    stop();
    rotate_right();
    delay(1000);
    stop();

}