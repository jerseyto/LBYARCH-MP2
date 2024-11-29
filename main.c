#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS

extern void getSDotx64(float* x, int n);

void generateRandomValues(float* x, int n) {

	for (int i = 0; i < n; ++i) {
		// Generate a new random value for each element
		x[i] = ((float)rand() / (float)(RAND_MAX)) * 10.0;
		//printf("%f\n", x[i]);

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
	unsigned long long int ARRAY_SIZE = 536870912;
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

	//initialize vectors
	//printf("Vector A:\n");
	generateRandomValues(a, ARRAY_SIZE);

	//printf("\nVector B:\n");
	generateRandomValues(b, ARRAY_SIZE);

	//c kernel
	start = clock();
	float sdot = getSDot(a, b, ARRAY_SIZE);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

	printf("\n[C] SDot: %f", sdot);
	printf("\nDot product using C took: %lf secs\n", time_taken);



	//x86-64 
	////re-init array
	//for (int i = 0; i < ARRAY_SIZE; i++)
	//	x[i] = 4.5f;

	//x86-64 kernel
	/*start = clock();
	getSDotx64(a, b, ARRAY_SIZE);
	end = clock();
	time_taken = ((double)(end - start)) * 1000 / CLOCKS_PER_SEC;

	printf("\n[x86-64] SDot: %f", sdot);
	printf("\nDot product using x86-64 took: %lf secs\n", time_taken);*/

	return 0;
}
