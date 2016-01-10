#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int R;
    scanf("%d", &R);
    int L;
    scanf("%d", &L);

    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    char res[4096] = {0};
    sprintf(res, "%d ", R);
    for (int i=1; i<L; ++i) {
        int cnt = 0, n = 0;
        char rc[4096] = {0}, *st = res, *tok = strchr(st, ' ');
        while (tok != NULL) {
            char nc[10] = {0};
            strncpy(nc, st, tok-st);
            if (n != atoi(nc)) {
                if (cnt) {
                    if (rc[0]) sprintf(rc, "%s %d %d", rc, cnt, n);
                    else sprintf(rc, "%d %d", cnt, n);
                }
                cnt = 1;
                n = atoi(nc);
            } else {
                cnt++;
            }
            st = tok+1;
            tok = strchr(st, ' ');
        }
        if (cnt) {
            if (rc[0]) sprintf(rc, "%s %d %d ", rc, cnt, n);
            else sprintf(rc, "%d %d ", cnt, n);
        }
        strcpy(res, rc);
        //printf("%s\n", rc);
    }

    if (res[strlen(res)-1] == ' ') res[strlen(res)-1] = '\0';
    printf("%s\n", res);

    return 0;
}
