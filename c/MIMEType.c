#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // Number of elements which make up the association table.
    scanf("%d", &N);
    int Q; // Number Q of file names to be analyzed.
    scanf("%d", &Q);

    char exts[N][101]; // file extensions
    char mts[N][501]; // MIME types
    for (int i = 0; i < N; i++) {
        scanf("%s%s", exts[i], mts[i]); fgetc(stdin);
    }

    for (int i = 0; i < Q; i++) {
        char FNAME[501]; // One file name per line.
        fgets(FNAME, 501, stdin); // One file name per line.
        strtok(FNAME, "\n");

        bool found = false;
        const char *f = strrchr(FNAME, '.');
        if (f) {
            const char *ext = f+1;
            for (int i=0; i<N; ++i) {
                if (strcasecmp(ext, exts[i]) == 0) {
                    printf("%s\n", mts[i]);
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            printf("UNKNOWN\n");
        }
    }

    return 0;
}
