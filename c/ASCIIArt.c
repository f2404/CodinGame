#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    scanf("%d", &L);
    int H;
    scanf("%d", &H); fgetc(stdin);
    char T[257];
    fgets(T, 257, stdin);
    for (int i = 0; i < 257; ++i) {
        T[i] = toupper(T[i]);
        if (T[i] == 10) T[i] = 0;
    }
    const int Tlen = strlen(T);

    char chars[H][1025];
    memset(chars, 0, sizeof(char) * H * 1025);
    for (int i = 0; i < H; ++i) {
        char ROW[1025];
        fgets(ROW, 1025, stdin);
        strcpy(chars[i], ROW);
    }

    for (int i = 0; i < H; ++i) {
        char res[1025] = {0};
        for (int j = 0, z = 0; j < Tlen; ++j) {
            char c = T[j];
            int n = (c >= 'A' && c <= 'Z') ? c - 'A' : 26;
            for (int k = n*L; k < n*L+L; ++k) {
                res[z++] = chars[i][k];
            }
        }
        printf("%s\n", res);
    }

    return 0;
}
