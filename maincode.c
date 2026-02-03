#include <stdio.h>
#include <string.h>

#define DISP_WIDTH 15

/* prototypes */
void showCalculatorUI(const char *display);
double calculate(double a, double b, char op, int *ok);

int main()
{
    double a, b, result;
    char op;
    int ok;
    char display[64];

    /* ===== START ===== */
    showCalculatorUI("0");

    /* INPUT A */
    printf("\nEnter A: ");
    if (scanf("%lf", &a) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    snprintf(display, sizeof(display), "%.10g", a);
    showCalculatorUI(display);

    /* OPERATOR */
    printf("\nOperator (+ - * / %%): ");
    scanf(" %c", &op);
    snprintf(display, sizeof(display), "%.10g %c", a, op);
    showCalculatorUI(display);

    /* INPUT B */
    printf("\nEnter B: ");
    if (scanf("%lf", &b) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    snprintf(display, sizeof(display), "%.10g %c %.10g", a, op, b);
    showCalculatorUI(display);

    /* CALCULATE (ไม่ต้องกด =) */
    result = calculate(a, b, op, &ok);
    if (!ok) {
        showCalculatorUI("ERROR");
        return 0;
    }

    /* ===== SHOW RESULT IN CALCULATOR ===== */
    snprintf(display, sizeof(display), " %.10g", result);
    showCalculatorUI(display);

    /* PROGRAM END */
    return 0;
}

/* ===== functions below main ===== */

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

/*
   % = เปอร์เซ็นต์
   a % b = (a * b) / 100
*/
double calculate(double a, double b, char op, int *ok)
{
    *ok = 1;
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) { *ok = 0; return 0; }
            return a / b;
        case '%':
            return (a * b) / 100.0;
        default:
            *ok = 0;
            return 0;
    }
}
