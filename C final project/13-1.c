#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    int p[n];
    int c = 2;
    while (c <= n) {
        p[c] = 1;
        c++;
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == 1) {
            int j = i;
            while ((j * i) <= n) {
                p[j * i] = 0;
                j++;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (p[i] == 1) printf("%i ", i);
    }

}