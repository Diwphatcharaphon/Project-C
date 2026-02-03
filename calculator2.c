#include <stdio.h>
#include <string.h>

#include "ui.h"
#include "calculator.h"

int main()
{
    double a, b, result;
    char op;
    int ok;
    char display[64];

    showCalculatorUI("0");

    printf("\nEnter A: ");
    if (scanf("%lf", &a) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    snprintf(display, sizeof(display), "%.10g", a);
    showCalculatorUI(display);

    printf("\nOperator (+ - * / %%): ");
    scanf(" %c", &op);
    snprintf(display, sizeof(display), "%.10g %c", a, op);
    showCalculatorUI(display);

    printf("\nEnter B: ");
    if (scanf("%lf", &b) != 1) {
        printf("Invalid input\n");
        return 0;
    }
    snprintf(display, sizeof(display), "%.10g %c %.10g", a, op, b);
    showCalculatorUI(display);

    result = calculate(a, b, op, &ok);
    if (!ok) {
        showCalculatorUI("ERROR");
        return 0;
    }

    snprintf(display, sizeof(display), " %.10g", result);
    showCalculatorUI(display);

    return 0;
}
