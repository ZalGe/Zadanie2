#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


/**
 * Deklaracia funkcii
 */
double Random(int a, int b);
int float2Q();
double Q2float();

/**
 * Funkcia main
 */
int main() {

    int m, n, Q;
    double f, f1, difference, sum, average;
    double array [10];

    printf("Enter coefficients m and n: \n");
    scanf("%d %d", &m, &n);

    if (m + n != 16)
        printf("Invalid input! Please enter valid coefficients.\n");

    else
    {
        srand(time(NULL));

        for (int i = 0; i < 10; i++) {
            f = Random(m, n);
            Q = float2Q(f, n);
            f1 = Q2float(Q, n);
            difference = f - f1;
            array[i] = difference;
            double x = pow(2, -n);

            printf("%f %d %f %f %f %f \n", f, Q, f1, difference, array[i], x);


        }
    }

    return 0;
}

/**
 * Definicia funkcii
 * generovanie nahodneho cisla
 */
double Random(int a, int b)
{
    double x = (pow(2, a) - pow(2, (-b)));
    double r = ((double) rand() / (double) (RAND_MAX + 1) * x);

    return r;
}

int float2Q(double a, int b)
{
    int c = ceil(a * pow(2,b));

    return c;
}

double Q2float(int a, int b)
{
    double c = a / pow(2, b);

    return c;
}