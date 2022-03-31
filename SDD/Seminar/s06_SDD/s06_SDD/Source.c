#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Elev
{
	char* nume;
	int nrMatricol;
}Elev;

typedef struct Nod Nod;

struct Nod
{
	Elev informatie;
	Nod* urmator;
	Nod* precedent;
};

typedef struct ListaDubluInlantuita
{
	Nod* primul;
	Nod* ultimul;
}LDI;

//initializare elevi
Elev initializare(const* nume, int nrMatricol)
{
	Elev e;
	e.nume = (char*)malloc((strlen(nume) + 1) * sizeof(char));
	strcpy_s(e.nume, (strlen(nume) + 1), nume);
	e.nrMatricol = nrMatricol;
	return e;
}

void inserareInceput(LDI* lista, Elev e)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->precedent = NULL;
	nou->urmator = (*lista).primul;
	nou->informatie = e;

	if ((*lista).primul)
	{
		(*lista).primul->precedent = nou;
		(*lista).primul = nou;
	}
	else
	{
		(*lista).primul = nou;
		(*lista).ultimul = nou;
	}
}

LDI inserareInceput2(LDI lista, Elev e)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->precedent = NULL;
	nou->urmator = lista.primul;
	nou->informatie = e;

	if (lista.primul)
		lista.primul->precedent = nou;
	else
		lista.ultimul = nou;
	lista.primul = nou;

	return lista;
}

void inserareFinal(LDI* lista, Elev e)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->urmator = NULL;
	nou->informatie = e;
	nou->precedent = (*lista).ultimul;
	if ((*lista).ultimul)
		(*lista).ultimul->urmator = nou;
	else
		(*lista).primul = nou;
	(*lista).ultimul = nou;
}
LDI inserareFinal2(LDI lista, Elev e)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->urmator = NULL;
	nou->informatie = e;
	nou->precedent = lista.ultimul;
	if (lista.ultimul)
		lista.ultimul->urmator = nou;
	else
		lista.primul = nou;
	lista.ultimul = nou;

	return lista;
}

void afisareElev(Elev e)
{
	printf("Elevul %s are numarul matricol %d\n", e.nume, e.nrMatricol);
}

void afisareListaInceput(LDI lista)
{
	Nod* n = lista.primul;
	while (n)
	{
		afisareElev(n->informatie);
		n = n->urmator;
	}
}

void afisareListaSfarsit(LDI lista)
{
	Nod* n = lista.ultimul;
	while (n)
	{
		afisareElev(n->informatie);
		n = n->precedent;
	}
}

void stergereLista(LDI* lista)
{
	Nod* n = lista->primul;
	if (lista->primul)
	{
		while (n->urmator != NULL)
		{
			free(n->informatie.nume);
			n = n->urmator;
			free(n->precedent);
		}
		free(n->informatie.nume);
		free(n);
		lista->primul = NULL;
		lista->ultimul = NULL;
	}
}

void inserarePePozitieData(LDI* lista, int pozitie, Elev elev)
{
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->informatie = elev;
	Nod* p = (*lista).primul;
	int index = 0;
	while (p && index < pozitie)
	{
		p = p->urmator;
		index++;
	}
	if (p)
	{
		nou->precedent = p;
		nou->urmator = p->urmator;
		p->urmator = nou;
		if (nou->urmator)
			nou->urmator->precedent = nou;
	}
	else
	{
		inserareFinal(lista, elev);
	}
}

void main()
{
	LDI lista;
	lista.primul = NULL;
	lista.ultimul = NULL;

	inserareInceput(&lista, initializare("Ionescu", 1));
	inserareInceput(&lista, initializare("Popescu", 2));
	inserareInceput(&lista, initializare("Alexandrescu", 3));

	lista = inserareInceput2(lista, initializare("Roberta", 4));
	lista = inserareInceput2(lista, initializare("Lavinia", 5));
	lista = inserareInceput2(lista, initializare("Isa", 6));

	printf("Afisare lista de la inceput:\n");
	afisareListaInceput(lista);
	printf("\nAfisare lista de la sfarsit:\n");
	afisareListaSfarsit(lista);

	LDI lista2;
	lista2.primul = NULL;
	lista2.ultimul = NULL;

	inserareFinal(&lista2, initializare("Ionescu", 1));
	inserareFinal(&lista2, initializare("Popescu", 2));
	inserareFinal(&lista2, initializare("Alexandrescu", 3));

	lista2 = inserareFinal2(lista2, initializare("Roberta", 4));
	lista2 = inserareFinal2(lista2, initializare("Lavinia", 5));
	lista2 = inserareFinal2(lista2, initializare("Isa", 6));

	printf("\nAfisare lista de la inceput:\n");
	afisareListaInceput(lista2);
	printf("\nAfisare lista de la sfarsit:\n");
	afisareListaSfarsit(lista2);

	stergereLista(&lista);
	printf("\nAfisare lista de la inceput:\n");
	afisareListaInceput(lista);
	printf("\nAfisare lista de la sfarsit:\n");
	afisareListaSfarsit(lista);

	inserarePePozitieData(&lista2, 3, initializare("Calin", 7));
	printf("\nAfisare lista de la inceput:\n");
	afisareListaInceput(lista2);
	printf("\nAfisare lista de la sfarsit:\n");
	afisareListaSfarsit(lista2);
}