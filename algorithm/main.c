#include <math.h>
#include <stdio.h>
#include "inverse_kinematics.c"
#include "sensor.c"
#include "linear_interpolation.c"

int main() {
    int length_leg_position = 20;
    int total_legs = 6;
    float leg_position[length_leg_position];
    float leg_angle[length_leg_position];
    leg_position[0] = 1; //kaki ke-

    int path[8] = {0, 45, 90, 135, 180, 225, 270, 315}; // arah mata angin
    int available_path[9]; //indeks 0 untuk jumlah jalan yang ada 
    int rotation_check = 0;

    float rest_pos[3] = {0.0, 2.0, -0.5};
    float up_pos[3] = {0.0, 2.0, -1.0};
    float down_pos[3] = {0.0, 3.0, -2.0};

    // posisi yang diinginkan, mengacu pada koordinat kartesian kuadran 4(panjang vektor x+y menjadi sumbu-x dan z menjadi sumbu y) dengan pusat 0,0
    float x_pos[6];
    float y_pos[6];
    float z_pos[6];

    for(int i = 0; i<total_legs ; i++){
        x_pos[i] = 0.0;
        y_pos[i] = 2.0;
        z_pos[i] = -1.0;
    }

    for (int i = 0; i < total_legs; i++){
        if ((int)leg_position[0] >= 7) {
            leg_position[0] = 1.0;
        }
        inverse_kinematics(leg_position, x_pos[i], y_pos[i], z_pos[i]);
    }

    for (int i=0; i<total_legs; i++){
        printf("%f %f %f \n", leg_position[i*3 +1], leg_position[i*3 + 2], leg_position[i*3 + 3]);
    }

    to_normal_angle(leg_position, leg_angle);
    for (int i=0; i<total_legs; i++){
        printf("%f %f %f \n", leg_angle[i*3 +1], leg_angle[i*3 + 2], leg_angle[i*3 + 3]);
    }
    
    int data[6] = {100, 100, 100, 100, 100, 100};
    check_surrounding(path, available_path, data);
    for (int i=1; i <= available_path[0]; i++) {
        printf("%d ", available_path[i]);
    }
}