/**
 *
 * @author Filip Tomek
 * @date 27.10.2020
 * @name Zadanie 2C
 * @version 1.2
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

/**
 * Prototype of functions
 */

double Random(int a, int b);
int float2Q(double a, int b);
double Q2float(int a, int b);

/**
 * Main function
 */

int main() {

    int m, n, Q, p = 1000;
    double f, f1, difference, sum = 0, average, MaxAverage;

    printf("Enter coefficients m and n: \n");

    do {
        scanf("%d %d", &m, &n);

        if (m + n != 16)
            printf("Invalid input! Sum of entered coefficients must be 16! Please enter valid coefficients.\n");

        else {
            srand(time(NULL));

            for (int i = 0; i < p; i++) {
                f = Random(m, n);
                Q = float2Q(f, n);
                f1 = Q2float(Q, n);

                if (f - f1 < 0)
                    difference = -(f - f1);
                else
                    difference = f - f1;

                sum = sum + difference;
            }

            MaxAverage = pow(2,(-n));
            average = sum / p;

            if (average <= MaxAverage)
                printf("Average difference between generated float. numbers and calculated float. numbers is %f\n", average);

            else
                printf("Unexpected error has occurred. Please, restart the program.\n");
        }
    }
    while (m + n != 16);     // If the condition is true, then it will print error message and you have to provide a new input

    return 0;
}

/**
 * Definition of functions
 */

/* Generator of random floating point number */
double Random(int a, int b) {
    double x = (pow(2, a) - pow(2, (-b)));      //Calculating to what maximum range i can generate random number
    double r = ((double) rand() / (double) (RAND_MAX + 1) * x);     //Generating random number in range < 0 ; x >

    return r;
}

/* Convertor from floating point number to Q number format */
int float2Q(double a, int b) {
    int c;
    double n = a * pow(2,b);

    if ((n + 0.5) >= ceil(n))         //If the number n is equal or greater than XXX.5 (X represents other digits),
        c = ceil(n);                  //then it will round up

    else
        c = floor(n);                 //If it is less than XXX.5, then it will round down

    return c;
}

/* Convertor from Q number format to floating point number */
double Q2float(int a, int b) {
    double c = a / pow(2, b);

    return c;
}