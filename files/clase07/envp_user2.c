#include <stdio.h>
#include <string.h>

void main(int argc,char *argv[],char *envp[]) {
	int i=0;

	while(envp[i]!=NULL) {
		if(strstr(envp[i],"USER=")) {
			printf("%s\n", strstr(envp[i],"=")+1);
		}
		i++;
	}
}
