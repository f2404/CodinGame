#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    // game loop
    while (1) {
        int spaceX;
        int spaceY;
        scanf("%d%d", &spaceX, &spaceY);
        int mh = INT_MIN, mp = -1;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.
            scanf("%d", &mountainH);
            if (mountainH > mh) {
                mh = mountainH;
                mp = i;
            }
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");
        if (spaceX == mp) printf("FIRE\n");
        else printf("HOLD\n"); // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
    }

    return 0;
}
