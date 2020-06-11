#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GAP_MAX 4
#define MAX_DNA 100001
#define MAX_SEQ 11

char *seq;
FILE *saida;

void buscaDNA(char *dna, char *seq)
{
	int i, j, k, l, gap, m;
	m = 0;
	for (i = 0; i < strlen(dna); i++)
	{
		if (dna[i] == seq[0])
		{
			j = 1;
			gap = 0;
			l = 0;
			while ((j < strlen(seq)) && (gap <= GAP_MAX))
			{
				if (dna[i + j + gap] == seq[j])
				{
					j++;
				}
				else
				{
					gap++;
				}
				l++;
			}
			if (j == strlen(seq))
			{
				for (k = 0; k <= l; k++)
				{
					printf("%c", dna[i + k]);
				}
				printf(" (gap = %i)\n", gap);
				m++;
			}
		}
	}
	printf("Foram achadas %d sequencias\n", m);
}

void busca(char *arqdna)
{
	char *dna;
	FILE *fp;

	dna = (char *)malloc(MAX_DNA);

	const char *path = "input/";
	char *filepath = malloc(strlen(path) + strlen(arqdna) + 2);
	sprintf(filepath, "%s/%s", path, arqdna);

	if ((fp = fopen(filepath, "r")) == NULL)
	{
		printf("Nao pode abrir o arquivo %s.\n", filepath);
		exit(1);
	}

	fgets(dna, MAX_DNA, fp);

	fclose(fp);

	printf("Procurando a sequencia: %s (%zu aminoacidos) na cadeia:%s (%zu aminoacidos)\n", seq, strlen(seq), arqdna, strlen(dna));

	buscaDNA(dna, seq);
}

void main()
{
	FILE *fp;

	if ((saida = fopen("serial.out", "w")) == NULL)
	{
		printf("Nao foi possivel abrir o arquivo para a saida dos resultados.\n");
		exit(1);
	}

	seq = (char *)malloc(MAX_SEQ);
	if ((fp = fopen("input/seq.dna", "r")) == NULL)
	{
		printf("Nao pode abrir o arquivo da sequenca a ser procurada.\n");
		exit(1);
	}

	fgets(seq, MAX_SEQ, fp);
	fclose(fp);

	/*inicio da busca nas varias cadeias*/
	busca("cadeia0.dna");
	busca("cadeia1.dna");
	busca("cadeia2.dna");
	busca("cadeia3.dna");
	busca("cadeia4.dna");
	busca("cadeia5.dna");
	busca("cadeia6.dna");
	busca("cadeia7.dna");
	busca("cadeia8.dna");
	busca("cadeia9.dna");

	fclose(saida);
}
