#include <stdio.h>

#define SAMPLE_FREQ 8000
#define BUFF_LEN 1024

int arr[] = {1, 2, 3, 4, 5, 6};
int fs = SAMPLE_FREQ;
int fo = 0.5 * SAMPLE_FREQ;

int in_loop_index = 0;
int skip_flag = 0;
int buff[BUFF_LEN];

void output_sample(int out) {
    printf("%d ", out);
}

void main() {
    while(1) {
        buff[in_loop_index] = arr[in_loop_index % 6];
        
        if (fo > fs) {
            for (int i = 0; i < (fo / fs); i++) {
                output_sample(buff[in_loop_index]);
            }
        } else if (fo < fs) {
            if (skip_flag) {
                output_sample(buff[in_loop_index]);
                skip_flag = 0;
            } else {
                skip_flag = 1;
            }
        } else {
            output_sample(buff[in_loop_index]);
        }

        if (in_loop_index++ == (BUFF_LEN - 1)) {
            in_loop_index = 0;
        }

    }
}

