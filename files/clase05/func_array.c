#define N 4
#include <stdio.h>

float promedioArray (int D[ ], int num_elementos) {
    long prom = 0;
    int i;
    for (i=0; i < num_elementos; i++)
        prom = prom + (long) D[i];
    return ((float) prom / (float) num_elementos);
}

void main(void) {
	int i, D[N];
	float f;
    for (i=0; i < N; i++) {
		scanf("%d", &D[i]);
	}
	f = promedioArray(D,N);
	printf("promedio %f\n", f);
	printf("comienzo del vector D %p\n", D);
}
