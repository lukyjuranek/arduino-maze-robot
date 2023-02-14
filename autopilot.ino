void autopilot_loop() {
    if(obstacle_position == 0){
        // If there is no obstacle, go forward
        go_forward();
    } else if(obstacle_position == 1){
        // If there is an obstacle on the left, turn right
        turn_right();
    } else if(obstacle_position == 2){
        // If there is an obstacle in front, turn left
        turn_left();
    } else if(obstacle_position == 3){
        // If there is an obstacle on the right, turn left
        turn_left();
    }
}