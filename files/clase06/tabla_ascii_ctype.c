#define full 15

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Casos no contemplados:
//		isspace(), tolower() & toupper()

char ctype_fv(int fn, unsigned char c) {
	switch (fn) {
		case 0:
			if(isalnum(c)) return c;
			else return '.';
			break;
		case 1:
			if(isalpha(c)) return c;
			else return '.';
			break;
		case 2:
			if(isascii(c)) {
				if(iscntrl(c)) return 'c';
				else return c;
			} else
				return '.';
			break;
		case 3:
			if(iscntrl(c)) return 'C';
			else return '.';
			break;
		case 4:
			if(isprint(c)) return c;
			else return '.';
			break;
		case 5:
			if(islower(c)) return c;
			else return '.';
			break;
		case 6:
			if(isupper(c)) return c;
			else return '.';
			break;
		case 7:
			if(isdigit(c)) return c;
			else return '.';
			break;
		case 8:
			if(isxdigit(c)) return c;
			else return '.';
			break;
		case 9:
			if(ispunct(c)) return c;
			else return '.';
			break;
		case 15:
			if(iscntrl(c)) return '.';
			else return c;
			break;
		default:
			return '.';
			break;
	}
}

void ctype_fn(int fn, char *str) {
	switch (fn) {
		case 0:
			strcpy(str, "isalnum()");
			break;
		case 1:
			strcpy(str, "isalpha()");
			break;
		case 2:
			strcpy(str, "isascii()");
			break;
		case 3:
			strcpy(str, "iscntrl()");
			break;
		case 4:
			strcpy(str, "isprint()");
			break;
		case 5:
			strcpy(str, "islower()");
			break;
		case 6:
			strcpy(str, "isupper()");
			break;
		case 7:
			strcpy(str, "isdigit()");
			break;
		case 8:
			strcpy(str, "isxdigit()");
			break;
		case 9:
			strcpy(str, "ispunct()");
			break;
		case 15:
			strcpy(str, "full");
			break;
		default:
			strcpy(str, "undefined...");
			break;
	}
}

void show_table(int fn, int limit) {
	int i, j;
	unsigned char c, c2s;
	char str[15];
	ctype_fn(fn, str);
	printf("\nTabla ASCII - %s\n", str);
	printf("Sume el valor de la fila con el de la columna para obtener el codigo\n\n");
	printf("     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n\n");
	for (i = 0; i < limit; i++) {
		printf("%4d", i*16);
		for(j = 0; j < 16; j++) {
			c = 16*i + j;
			c2s = ctype_fv(fn, c);
			printf("%2c ", c2s);
		}
		printf("\n\n");
	}
}

int main(void) {
	int i;
	for(i=0;i<10;i++) {
		system("clear");
		show_table(i, 8);
		printf("Presione una tecla para continuar...");
		getchar();
	}
	// La parte extendida no anda, hace falta usar unicode
	//		man 3 mbstowcs
	//		wchar_t es el tipo de dato usado para unicode char
	//system("clear");
	//show_table(full, 16);
	return 0;
} 
