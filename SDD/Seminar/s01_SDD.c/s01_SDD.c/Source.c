#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b)
{
	//Metoda 1
	int aux = *a;
	*a = *b;
	*b = aux;
	//Metoda 2
	//*a=*a+*b;
	//*b=*a-*b;
	//*a=*a-*b;
}

void citireVector(int* n, int** v)
{
	printf("Introduceti numarul de elemente: ");
	scanf("%d", n);

	*v = (int*)malloc(*n * sizeof(int));
	for(int i=0;i<*n;i++)
		scanf("%d", &(*v)[i]);
}

int main()
{
	int a = 10;
	double b = 3.5;
	char c = 'C';
	c += 1;
	a = a + 'C';

	printf("%c\n", c);
	printf("%f\n", b);
	printf("%d\n\n", a);
	
	char* str = (char*)malloc(4 * sizeof(char));
	str[0] = 65;
	str[1] = 66;
	str[2] = 67;
	str[3] = 0;

	//Afiseaza ABC
	printf("%s\n\n", str);

	scanf("%d", &a);
	printf("%d\n\n", a);


	int var1 = 10;
	int var2 = 15;
	swap(&var1, &var2);
	printf("%d %d\n\n", var1, var2);

	int n;
	int* v;

	citireVector(&n, &v);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);

	return 0;
}