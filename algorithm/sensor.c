void check_surrounding(int* path, int* available, int* sensor_data) {
    available[0] = 0;
    int threshold = 50;

    for (int i = 0; i < 8; i++){
        if (i == 0 && sensor_data[i] >= threshold) {
            available[0] = available[0] + 1;
            available[available[0]] = path[i];
        }
        else if (i < 4 && sensor_data[i-1] >= threshold && sensor_data[i] >= threshold) {
            available[0] = available[0] + 1;
            available[available[0]] = path[i];
        }
        else if (i == 4 && sensor_data[i-1 >= threshold]) {
            available[0] = available[0] + 1;
            available[available[0]] = path[i];
        }
        else if (i < 7 && sensor_data[i-2] >= threshold && sensor_data[i-1] >= threshold) {
            available[0] = available[0] + 1;
            available[available[0]] = path[i];
        }
        else if (sensor_data[i-2] >= threshold && sensor_data[0] >= threshold) {
            available[0] = available[0] + 1;
            available[available[0]] = path[i];
        }
    }
}

int rotate_to_check(int* rotation_done, int* sensor_data){
    int threshold = 50;
    int rotation = 20;

    if (sensor_data[0] >= threshold) {
        return 0;
    }
    else if (sensor_data[3] >= threshold) {
        return 180;
    }

    if (*rotation_done >= 360) {
        return -9;
    }
    else {
        *rotation_done = *rotation_done + 20;
        return -1;
    }
}