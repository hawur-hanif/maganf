//unfinished
void inverse_kinematics(float* leg_position, float x, float y, float z) {
    // x, y sumbu horizontal, z sumbu vertikal
    float leg_bot = 3.0;
    float leg_top = 2.0;
    int leg_nums = leg_position[0];
    
    float base = atan2(y, x) * (180 / 3.1415);

    float l = sqrt(x*x + y*y);
    
    float h = sqrt(l*l + z*z);

    float phi = atan(z/l) * (180 / 3.1415);

    float theta = acos(((leg_top*leg_top) + (h*h) - (leg_bot*leg_bot)) / (2*leg_top*h)) * (180 / 3.1415);
    float gamma = acos(((h*h) + (leg_bot*leg_bot) - (leg_top*leg_top)) / (2*leg_bot*h)) * (180 / 3.1415);

    leg_position[(leg_nums-1)*3 + 1] = base;
    leg_position[(leg_nums-1)*3 + 2] = phi + theta;
    leg_position[(leg_nums-1)*3 + 3] = - theta - gamma;

    leg_position[0] = leg_position[0] + 1;
}

void to_normal_angle(float* leg_position, float* leg_angle) {
    float rest_top = 81.1845; // 2.0, -0.5
    float rest_bot = -136.821;

    for (int i = 1; i<19 ; i++){
        if (i % 3 == 2){
            leg_angle[i] = rest_top - leg_position[i]; // rotate clockwise
        } else if (i % 3 == 0){
            leg_angle[i] = leg_position[i] - rest_bot; // rotate counterclockwise
        } else{
            leg_angle[i] = leg_position[i];
        }
    }
}
