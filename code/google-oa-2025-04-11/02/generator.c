#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
const int mod = 998244353;

int main() {
    srand(time(NULL));  // Seed the random number generator

    for (int t = 0; t < N; ++t) {
        int size = (rand() % 100) + 1;  // Random size between 1 and 100
        printf("%d", size);

        for (int i = 0; i < size; ++i) {
            int element = (rand() % 2001) - 1000;  // Random element between -1000 and 1000
            printf(" %d", element);
        }

        printf("\n");
    }

    return 0;
}

