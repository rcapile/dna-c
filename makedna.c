#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dnadef.h"

char letras[4] = {'A', 'C', 'G', 'T'};
int i;
FILE *fp;

void criadna(char *arq)
{
	int i;
	FILE *fp;
	const char *path = "input/";

	char *filepath = malloc(strlen(path) + strlen(arq) + 2);
	sprintf(filepath, "%s/%s", path, arq);
	 
	if ((fp = fopen(filepath, "w")) == NULL)
	{
		printf("Nao pode criar o arquivo %s.\n", arq);
		exit(1);
	}	else 	{
		printf("Escrevendo arquivo de DNA(%s)\n", arq);
		for (i = 0; i < MAX_DNA; i++)
			fprintf(fp, "%c", letras[rand() % 4]);
		fclose(fp);
	}
	free(filepath);
}

void main()
{
	criadna("cadeia0.dna");
	criadna("cadeia1.dna");
	criadna("cadeia2.dna");
	criadna("cadeia3.dna");
	criadna("cadeia4.dna");
	criadna("cadeia5.dna");
	criadna("cadeia6.dna");
	criadna("cadeia7.dna");
	criadna("cadeia8.dna");
	criadna("cadeia9.dna");

	if ((fp = fopen("input/seq.dna", "w")) == NULL)
	{
		printf("Nao pode criar o arquivo seq.dna.\n");
		exit(1);
	}
	else
	{
		printf("Escrevendo arquivo de DNA(seq.dna)\n");

		for (i = 0; i < MAX_SEQ; i++)
			fprintf(fp, "%c", letras[rand() % 4]);
		fclose(fp);
	}
}
