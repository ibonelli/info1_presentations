#define X1 2
#define Y1 2
#define Z1 2

#define X2 3
#define Y2 3
#define Z2 3

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main(void)
{

int v[X1][Y1][Z1]={{{1,2},{3,4}},{{5,6},{7,8}}};
int m[X2][Y2][Z2];
int i,j,k;

for(i=0;i<X1;i++)
	for(j=0;j<Y1;j++)
		for(k=0;k<Z1;k++)
			printf("[%p]: %d\n",&(v[i][j][k]),v[i][j][k]);

printf("=================\n");

srandom(time(NULL));

for(i=0;i<X2;i++)
	for(j=0;j<Y2;j++)
		for(k=0;k<Z2;k++)
			m[i][j][k]=(int)random();

for(i=0;i<X2;i++)
	for(j=0;j<Y2;j++)
		for(k=0;k<Z2;k++)
			printf("[%p]: %d\n",&(m[i][j][k]),m[i][j][k]);

}
