#include <stdio.h>

void main(void)
{
unsigned long num;
unsigned long factorial(unsigned long);
printf("Ingrese el numero del que desea el factorial: ");
scanf("%u",&num);
printf("El resultado es: %u\n",factorial(num));
}

unsigned long factorial(n)
unsigned long n;
{
unsigned long res=1,i;
if((n==0)||(n==1)) return(1);
for (i=2;i<(n+1);i++) res=res*i;
return(res);
}
