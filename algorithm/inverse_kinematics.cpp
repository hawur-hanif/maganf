#include <iostream>
#include <math.h>
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

int main() {
    int length_leg_position = 20;
    int total_legs = 6;
    float leg_position[length_leg_position];
    leg_position[0] = 1;

    float x_pos[6];
    float y_pos[6];
    float z_pos[6];

    for(int i = 0; i<total_legs ; i++){
        x_pos[i] = 0.0;
        y_pos[i] = 2.0;
        z_pos[i] = -0.5;
    }

    for (int i = 0; i < total_legs; i++){
        if ((int)leg_position[0] >= 7) {
            leg_position[0] = 1.0;
        }
        inverse_kinematics(leg_position, x_pos[i], y_pos[i], z_pos[i]);
    }

    for (int i=0; i<total_legs; i++){
        std::cout << leg_position[i*3 + 1] << " " << leg_position[i*3 + 2] << " " << leg_position[i*3 + 3] << "\n";
    }
    
}
