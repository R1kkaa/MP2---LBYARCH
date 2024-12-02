#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void generate_random_inputs(double (*array)[3], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        array[i][0] = (rand() % 200) + 0.0;         // Initial Velocity
        array[i][1] = array[i][0] + (rand() % 100); // Final Velocity
        array[i][2] = (rand() % 50) + 1.0;          // Time
    }
}

void display_inputs(double (*array)[3], int n)
{
    int i;
    printf("Array Size: %d rows\n", n);
    printf("Randomized Matrix Rows (Initial Velocity, Final Velocity, Time):\n");
    for (i = 0; i < n; i++)
    {
        printf("%d: %.2f, %.2f, %.2f\n", i + 1, array[i][0], array[i][1], array[i][2]);
    }
    printf("\n");
}

void performance_test(int n, int iterations)
{
    double(*array)[3] = malloc(sizeof(double[n][3]));
    int *results = malloc(n * sizeof(int));

    generate_random_inputs(array, n);
    display_inputs(array, n);

    double total_time = 0.0;
    int iter;

    for (iter = 0; iter < iterations; iter++)
    {
        clock_t start = clock();
        int i;

        for (i = 0; i < n; i++)
        {
            results[i] = calculateacceleration(array[i][1], array[i][0], array[i][2]);
        }

        clock_t end = clock();
        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    printf("Acceleration Results (in m/s^2, converted to integers):\n");
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Row %d: %d m/s^2\n", i + 1, results[i]);
    }

    printf("\nAverage execution time for %d rows over %d iterations: %lf seconds\n", n, iterations, total_time / iterations);

    free(array);
    free(results);
}

void manual()
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
}

int calculateacceleration(double final, double initial, double time)
{
    return round(((final - initial) / 3.6) / time);
}

int main()
{
    // manual(); // manual input
    performance_test(10, 30); // execution testing
}