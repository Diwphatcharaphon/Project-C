#include <stdio.h>
#include <string.h>
#include "ui.h"

void showCalculatorUI(const char *display)
{
    char buf[DISP_WIDTH + 1];
    int len = strlen(display);

    if (len > DISP_WIDTH) {
        strncpy(buf, display + len - DISP_WIDTH, DISP_WIDTH);
        buf[DISP_WIDTH] = '\0';
    } else {
        strcpy(buf, display);
    }

    printf("*---------------------------------*");
    printf("\n|      Project Calculator         |");
    printf("\n*---------------------------------*");

    printf("\n-----------------");
    printf("\n|%*s|", DISP_WIDTH, buf);
    printf("\n-----------------");
    printf("\n| <- AC   %%     |");
    printf("\n| 7   8   9   / |");
    printf("\n| 4   5   6   x |");
    printf("\n| 1   2   3   - |");
    printf("\n| 0   .   =   + |");
    printf("\n-----------------\n");
}