struct alumno {
	char nom[20];
	char ape[20];
	int edad;
	long legajo;
};

void add_null_str(char *str, int size);
void print_alumno(struct alumno aux);
