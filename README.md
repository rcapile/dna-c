Busca de seqüências em cadeias de DNA
=====================================

Este trabalho avalia o tempo de busca de uma seqüência de 10 aminoácidos em uma cadeia de DNA com 100.000 aminoácidos. É feita uma comparação com o MPI.

Nós queremos mostrar a eficiência da paralelização na procura de seqüências de aminoácidos em uma cadeia de DNA. A cadeia normal de DNA possui milhões de aminoácidos. Desse modo o paralelização seria uma soluções excelente para os algoritmos de busca serial, reduzindo bastante o tempo de procura.

ALGORITMO
---------

O Algoritmo que utilizamos foi desenvolvido especialmente para este trabalho para achar uma seqüência de DNA dentro de uma cadeia de DNA. Dado uma cadeia de DNA a seqüência e procurada de forma que possa haver espaços entre os aminoácidos do DNA (gap). Isto e com gap=1 procurando pela seqüência ACCA podemos ter as seguintes opções: A_CCA,AC_CA, AC_CA ou ACC_A. O melhor caso e quando existe apenas as seqüências sem gap (ACCA) e o pior caso e quando não existir a seqüência. Este algoritmo não distingue a posição da dos aminoácidos na seqüência, apenas o numero do gap. O algoritmo da busca é o seguinte:

```C
int buscaDNA(char *dna, char *seq)
{
    int i, j, k, l, gap;
    int seqlen, fim;
    k = 0;
    fim = strlen(dna);
    seqlen = strlen(seq);
    for (i = 0; i < fim; i++)
    {
        if (dna[i] == seq[0])
        {
            j = 1;
            gap = 0;
            l = 0;
            while ((j < seqlen) && (gap <= GAP_MAX))
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
            if (j == seqlen)
            {
                k++;
            }
        }
    }

    return k; /*retorna o numero de sequencias encontradas*/
}
```

O algoritmo pega 1 primeiro aminoácidos e percorre a cadeia  até encontrar a primeira ocorrência daquele aminoácido. Ao encontrar, continua percorrendo a cadeia até encontrar o próximo aminoácido da seqüência, reduzindo o número de gap a cada aminoácido percorrido na cadeia que seja diferente do aminoácido procurado. Esse processo é repetido até toda a seqüência ser encontrada, ou o numero de gap atinja o valor zero. Se o gap atingir o valor zero significa que a seqüência não pode ser construída. Após este procedimento percorre a cadeia a partir do 1 aminoácido da seqüência encontrado até encontrar a próxima ocorrência do mesmo e repete o processo descrito acima.

ESTRATÉGIA DE PARALELIZAÇÃO
---------------------------

A seqüência a ser procurada e enviada a todos os processadores enquanto a cadeia de DNA e distribuída entre os processadores. No entanto, quando usando troca de mensagens, o pedaço do DNA a ser enviado para cada processador deve ser aumentado do maior tamanho que a seqüência pode ter (tamanho da seqüência + gap) para evitar que uma possível ocorrência da seqüência na cadeia fique quebrada entre os processadores.

METODOLOGIA
-----------

E procurada uma seqüência de DNA com 10 aminoácidos em uma cadeia de DNA com 100.000 de aminoácidos. Ambos são lidos a partir dos arquivos seq.dna e cadeia[0-9].dna respectivamente. É medido o tempo para distribuição da cadeia entre os processadores, do envio da seqüência para os processadores e o tempo médio de busca.
