#include <stdio.h>
#include <stdbool.h>

bool espacoLivre(int* tabela, int posicao)
{
	return tabela[posicao] == 0;
}

void insereElemento(int* tabela, int posicao, int numMatricula)
{
	if (espacoLivre(tabela, posicao))
		tabela[posicao] = numMatricula;
	else
	{
		if (posicao + 4 > 20)
			insereElemento(tabela, posicao - 17, numMatricula);
		else
			insereElemento(tabela, posicao + 4, numMatricula);
	}
}

int main()
{
	int tabela[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int numMatricula;
	int numIteracoes = 0;
	int proxElemento;
	int posicao;
	bool tabelaCheia = false;
	
	do
	{
		proxElemento = 1;
		printf("Insira o numero de matricula.\n");
		scanf("%d", &numMatricula);

		if (numIteracoes == 21)
			printf(" \t*** TABELA CHEIA!!!\n");
		else
		{
			posicao = numMatricula % 21;
			insereElemento(tabela, posicao, numMatricula);
			numIteracoes++;
		}
		
		printf("Digite 0 inserir outra matricula na tabela.\nDigite 1 para imprimir a tabela e encerrar o programa.\n");
		scanf("%d", &proxElemento);

		if (proxElemento)
			tabelaCheia = !tabelaCheia;
	} while (!tabelaCheia);

	printf("------RESULTADO DA TABELA DE HASHING------\n");
	for (int i = 0; i < 21; i++)
		printf("Elemento %d = %d \n", i, tabela[i]);

	return 0;
}