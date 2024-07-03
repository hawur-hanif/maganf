//unfinished

float convert_x(int pos_num, float x, float y) {
    float pi = 3.1415;
    switch (pos_num) {
        case 1 :
            x = x * cos(-pi/3) - y * sin(-pi/3) - 4;
            break;
        case 2 :
            x = x * cos(0) - y * sin(0) - 4;
            break;
        case 3 :
            x = x * cos(pi/3) - y * sin(pi/3) - 4;
            break;
        case 4 :
            x = x * cos(2* (pi/3)) - y * sin(2* (pi/3)) - 4;
            break;
        case 5 :
            x = x * cos(pi) - y * sin(pi) - 4;
            break;
        case 6 :
            x = x * cos(-2* (pi/3)) - y * sin(-2* (pi/3)) - 4;
            break;
        default :
            break;
    }
    return x;
}

float convert_y(int pos_num, float x, float y) {
    float pi = 3.1415;
    switch (pos_num) {
        case 1 :
            y = y * cos(-pi/3) + x * sin(-pi/3);
            break;
        case 2 :
            y = y * cos(0) + x * sin(0);
            break;
        case 3 :
            y = y * cos(pi/3) + x * sin(pi/3);
            break;
        case 4 :
            y = y * cos(2 * (pi/3)) + x * sin(2 * (pi/3));
            break;
        case 5 :
            y = y * cos(pi) + x * sin(pi);
            break;
        case 6 :
            y = y * cos(-2 * (pi/3)) + x * sin(-2 * (pi/3));
            break;
        default :
            break;
    }
    return y;
}

float convert_z (float z) {
    return z - 2.0;
}

void inverse_kinematics(float* leg_position, float x, float y, float z) {
    // x, y sumbu horizontal, z sumbu vertikal
    float leg_bot = 3.0;
    float leg_top = 2.0;
    int leg_nums = leg_position[0];

    float angle_to_x = atan2(3.5, 2) * (180/3.1415);
    float rotate_from_self = 90 - angle_to_x;

    float xt = x;
    x = convert_x(leg_nums, x, y);
    y = convert_y(leg_nums, xt, y);
    z = convert_z(z);

    printf("%f %f %f \n", x, y, z);
    
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
