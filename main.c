/**
 *
 * @author Filip Tomek
 * @date 22.11.2020
 * @name Zadanie 2C
 * @version 1.3
 * @standard ANSI C99
 * @brief Program is designed to generate random floating point number, then convert it to Q number format and then
 *        convert it again to floating point number. Its function is to calculate average difference between generated
 *        floating point number and converted floating point number.
 *
 *        Program will print error message, when:
 *        - sum of coefficients m and n != 16
 *        - average is greater than MaxAverage
 *
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

double Random(int a, int b);
int float2Q(double a, int b);
double Q2float(int a, int b);

int main() {

    int m, n, Q, p = 1000, a = 1;
    double f, f1, difference, sum = 0, average, MaxAverage;

    printf("Enter coefficients m and n: \n");

    while (a == 1) {         // this loop will last, until m + n == 16

        scanf("%d %d", &m, &n);

        if (m + n != 16)
            printf("Invalid input! Sum of entered coefficients must be 16! Please enter valid coefficients!\n");

        else
            a = 0;
    }

    srand(time(NULL));

    for (int i = 0; i < p; i++) {
        f = Random(m, n);
        Q = float2Q(f, n);
        f1 = Q2float(Q, n);

        difference = fabs(f - f1);

        sum = sum + difference;
    }

    MaxAverage = pow(2,(-n));
    average = sum / p;

    if (average <= MaxAverage)
        printf("Average difference between generated float. numbers and calculated float. numbers is %f\n", average);

    else
        printf("Unexpected error has occurred. Please, restart the program.\n");

    return 0;
}

/* Generator of random floating point number */
double Random(int a, int b) {
    double x = (pow(2, a) - pow(2, (-b)));      //Calculating to what maximum range i can generate random number

    return ((double) rand() / (double) (RAND_MAX + 1) * x);         //Generating random number in range < 0 ; x >
}

/* Convertor from floating point number to Q number format */
int float2Q(double a, int b) {
    return round (a * pow(2,b));
}

/* Convertor from Q number format to floating point number */
double Q2float(int a, int b) {
    return a / pow(2, b);
}