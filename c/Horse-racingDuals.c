#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int cmpfunc(const void *a, const void *b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    scanf("%d", &N);

    int st[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &st[i]);
    }

    qsort(st, N, sizeof(int), cmpfunc);
    int diff = INT_MAX;
    for (int i = 1; i < N; i++) {
        int d = abs(st[i] - st[i-1]);
        if (d == 0) {
            diff = 0;
            break;
        } else if (d < diff) {
            diff = d;
        }
    }

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");

    printf("%d\n", diff);

    return 0;
}
