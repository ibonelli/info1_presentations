#include <string.h>
#include <stdio.h>

int main()
{
	char str[80] = "123;456;789;ABC;DEF;GHI";
	char s[2] = ";";
	char *token;
	int i, len;

	printf( "Direccion del string: %p\n", str);

	len = strlen(str);
	printf("=============================\n");
	for(i=0; i<=len; i++){
		printf("%2d, %x, %c\n",str[i],str[i],str[i]);
	}
	printf("=============================\n");

	/* get the first token */
	token = strtok(str, s);

	/* walk through other tokens */
	while( token != NULL ) 
	{
		printf( " %s\n", token );
		printf( "\taddress_token: %p\n", token );
 
		token = strtok(NULL, s);
	}

	printf("=============================\n");
	for(i=0; i<=len; i++){
		printf("%2d, %x, %c\n",str[i],str[i],str[i]);
	}
	printf("=============================\n");

	return(0);
} 
