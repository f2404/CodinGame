#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BITS 7

void char2hex(unsigned char c, char *h) {
	for (size_t i = 0; i < BITS; ++i) {
		size_t p = 1 << (BITS-1-i);
		if (c / p) {
			h[i] = '1';
			c -= p;
		} else {
			h[i] = '0';
		}
	}
}

int main()
{
    char MESSAGE[101];
    fgets(MESSAGE, 101, stdin);
    strtok(MESSAGE, "\n");
    //printf("%d %s\n", strlen(MESSAGE), MESSAGE);

    char hexs[701] = {0}, coded[2048] = {0};
    size_t len = strlen(MESSAGE);
    for (size_t i = 0; i < len; ++i) {
        char *h[BITS+1] = {0};
        char2hex(MESSAGE[i], h);
        strcat(hexs, h);
    }
    //printf("%s\n", hexs);

    len = strlen(hexs);
    strcpy(coded, (hexs[0] == '1') ? "0 0" : "00 0");
    for (size_t i = 1; i < len; ++i) {
        if (hexs[i] != hexs[i-1]) {
            strcat(coded, " ");
            strcat(coded, (hexs[i] == '1') ? "0 0" : "00 0");
        } else {
            strcat(coded, "0");
        }
    }
    printf("%s\n", coded);

    return 0;
}
