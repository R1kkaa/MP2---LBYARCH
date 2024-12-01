#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 0;
    int i = 0;
    double(*array)[3];
    printf("Input Array Size: ");
    scanf("%d", &n);
    printf("Input Matrix Rows, single float matrix values, space seperated Ex. (1, 2, 3)\n");
    array = malloc(sizeof(double[n][3]));
    int *results = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%lf, %lf, %lf", &array[i][0], &array[i][1], &array[i][2]);
    };
    printf("Outputs: Acceleration in m/s^2\n");
    for (i = 0; i < n; i++)
    {
        results[i] = calculateacceleration(array[i][1], array[i][0], array[i][2]);
        printf("Matrix: %d: %d\n", i, results[i]);
    };
    return 0;
}

int calculateacceleration(double final, double initial, double time)
{
    return round(((final - initial) / 3.6) / time);
}