void autopilot_loop() {
    if(obstacle_position() == "none"){
        // If there is no obstacle, go forward
        go_forward();
    } else if(obstacle_position() == "left"){
        // If there is an obstacle on the left, turn right
        rotate_right();
    } else if(obstacle_position() == "front"){
        // If there is an obstacle in front, turn left
        rotate_left();
    } else if(obstacle_position() == "right"){
        // If there is an obstacle on the right, turn left
        rotate_left();
    }
}