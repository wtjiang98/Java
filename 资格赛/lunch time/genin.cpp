#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define MAXB 1000
#define MAXN 100

int main(int argc, char* argv[]) {
    freopen("0.in.clm", "w", stdout);

    int T = 50;
    printf("%d\n", T);

    srand( (unsigned)time( NULL ) );
    for (int t = 0; t < T; t++) {

        int B = rand() % MAXB;
        int N = rand() % MAXN;
        printf("%d\n%d\n", B, N);

        srand( (unsigned)time( NULL ) );
        for (int i = 0; i < N; i++) {

            int score = rand() % MAXB;
            int cost = rand() % MAXB;
            printf("%d %d\n", score, cost);
        }
    }

    return 0;
}
