#include <stdio.h>

int main(void) {
	int a, b, *p, *q, **r, **s;
	
	p=q=NULL;
	r=s=NULL;

	a=9; b=4;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	p = &a ; q = &b;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	r = &p ; s = &q;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	**r = *q;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	*p = *q + **s;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	r = s ; q = p;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	* (&a) = * (&b);
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	b = a - **r + *p;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	*p = a;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	q = &b ; r = &p;
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	*q = *q - **s + **(&p);
	printf("%d %d %p %p %p %p\n",a,b,p,q,r,s);

	return 0;
}
