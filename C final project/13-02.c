#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double drand(void) {
    return (double)rand() / (double)RAND_MAX;
}

int main() {
    double x; double y;
    double counter = 0;
    for (int i = 1; i < 100000; i++) {
        x = 2 * drand();
        y = 2 * drand();
        if ((sqrt(pow(1 - x, 2) + pow(1 - y, 2))) <= 1) {
            counter++;
        }
    }
    double pi = counter / 100000 * 4;
    printf("%f", pi);
}