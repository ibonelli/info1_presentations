float areaCirculo(float r)
{
	float supCir;
	supCir = 3.14 * r * r;
	return supCir;
}

#include <stdio.h>

void main(void)
{
  float area, radio = 2;

  area = areaCirculo(radio);
  printf("area de circulo de radio %f = %f\n", radio, area);
}

/*
 * Otro ejemplo
 * 

#include <stdio.h>
float areaCirculo(float);

void main(void)
{
  printf("area de circulo de radio 2 = %f\n", areaCirculo(2));
}

 */
