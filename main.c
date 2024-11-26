#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


void generateRandomValues(float* x, int n) {

	for (int i = 0; i < n; ++i) {
		// Generate a new random value for each element
		x[i] = ((float)rand() / (float)(RAND_MAX)) * 10.0;
		printf("%f\n", x[i]);

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
	unsigned long long int ARRAY_SIZE = 3;
	srand((unsigned int)time(NULL));	

	unsigned long long int vectorA = ARRAY_SIZE * sizeof(float);
	unsigned long long int vectorB = ARRAY_SIZE * sizeof(float);
	//printf("Number of elements: %");

	//timer variable
	clock_t start, end;
	double time_taken;

	//declare large array
	float* a;
	float* b;
	a = (float*)malloc(vectorA);
	b = (float*)malloc(vectorB);

	printf("Vector A:\n");
	generateRandomValues(a, ARRAY_SIZE);

	printf("\nVector B:\n");
	generateRandomValues(b, ARRAY_SIZE);

	float sdot = getSDot(a, b, ARRAY_SIZE);

	printf("\nSDot: %f", sdot);

	return 0;
}