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
