#include <stdio.h>
#define N 10

int main()
{
	FILE *fp;
	int vec[N];
	int i,leido;

	fp=fopen("misnum.dat","r");
	leido=fread(vec,sizeof(int),N,fp);

	for(i=0;i<leido;i++) {
		printf("%d\n",vec[i]);
	}
}
