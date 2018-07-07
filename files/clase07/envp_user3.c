#include <stdio.h>
#include <string.h>

void main(int argc, char *argv[], char *envp[]) {
	int i=0;
	char *str1="Hola ";
	char *str2=", que queres hacer hoy?\n";
	char *nom;

	while(envp[i]!=NULL) {
		if(strstr(envp[i],"USER") != NULL) {
			nom = strchr(envp[i],'=') + 1;
		}
		i++;
	}

	printf("%s%s%s", str1, nom, str2);
}
