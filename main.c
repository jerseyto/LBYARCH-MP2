#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

extern float getSDotx64(float* x, float* y, int n);

void generateRandomValues(float* x, int n) {
    for (int i = 0; i < n; ++i) {
        // Generate a new random value for each element
        x[i] = ((float)rand() / (float)(RAND_MAX)) * 10.0;
    }
}

float getSDot(float* a, float* b, int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i] * b[i];
    }
    return total;
}

int main() {
    size_t ARRAY_SIZE;
    srand((unsigned int)time(NULL));

    // Timer variables
    clock_t start, end;
    double time_taken;

    double c_avg_time[] = { 0.0, 0.0, 0.0 };
    double asm_avg_time[] = { 0.0, 0.0, 0.0 };
    int pow_values[] = { 20, 24, 28 };

    // Declare large arrays
    float* a;
    float* b;

    // C kernel loop
    for (int i = 0; i < 3; i++) {
        ARRAY_SIZE = 1 << pow_values[i];
        size_t vectorA = ARRAY_SIZE * sizeof(float);
        size_t vectorB = ARRAY_SIZE * sizeof(float);
        a = (float*)malloc(vectorA);
        b = (float*)malloc(vectorB);

        // Initialize vectors with random values
        generateRandomValues(a, ARRAY_SIZE);
        generateRandomValues(b, ARRAY_SIZE);

        printf("\n=================================================================\n");
        printf("                   VECTOR SIZE: 2^%d = %zu elements               \n", pow_values[i], ARRAY_SIZE);
        printf("=================================================================\n");

        for (int j = 0; j < 20; j++) {
            printf("\n------------------------------------------------------\n");
            printf("                    TEST NUMBER %d                         \n", j + 1);
            printf("------------------------------------------------------\n");

            // C kernel
            start = clock();
            float sdot = getSDot(a, b, ARRAY_SIZE);
            end = clock();
            time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
            printf("[C] SDot: %f\n", sdot);
            printf("Dot product using C took: %.6lf seconds\n", time_taken);
            c_avg_time[i] += time_taken;

            // x86-64 kernel
            start = clock();
            sdot = getSDotx64(a, b, ARRAY_SIZE);
            end = clock();
            time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;
            printf("[x86-64] SDot: %f\n", sdot);
            printf("Dot product using x86-64 took: %.6lf seconds\n", time_taken);
            asm_avg_time[i] += time_taken;

            printf("------------------------------------------------------\n");
        }

        c_avg_time[i] /= 20;
        asm_avg_time[i] /= 20;

        // Average execution times
        printf("\n=====================================================\n");
        printf("   AVERAGE EXECUTION TIMES FOR VECTOR SIZE 2^%d   \n", pow_values[i]);
        printf("=====================================================\n");
        printf("[C] Average Execution time: %.6lf seconds\n", c_avg_time[i]);
        printf("[x86-64] Average Execution time: %.6lf seconds\n", asm_avg_time[i]);

        // Free the allocated memory
        free(a);
        free(b);
    }

    // Final summary after all tests
    printf("\n=================================================================\n");
    printf("                      FINAL AVERAGE TIMES                      \n");
    printf("=================================================================\n");
    for (int i = 0; i < 3; i++) {
        printf("\nFor Vector Size 2^%d:\n", pow_values[i]);
        printf("[C] Average Execution time: %.6lf seconds\n", c_avg_time[i]);
        printf("[x86-64] Average Execution time: %.6lf seconds\n", asm_avg_time[i]);
        printf("-----------------------------------------------------------------\n");
    }

    return 0;
}
