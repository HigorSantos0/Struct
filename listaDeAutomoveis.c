/*
QuestÃ£o 01:
Uma loja de automÃ³veis mantÃ©m os carros Ã 
venda sob a forma de um vetor de structs
contendo as seguintes informaÃ§Ãµes, para cada
veÃ­culo: placa, modelo, marca, cor,
quilometragem, ano modelo/fabricaÃ§Ã£o (deve
ser um struct), valor e tipo (usado ou 0 km,
conforme o valor do campo quilometragem).
Pede-se a declaraÃ§Ã£o de uma variÃ¡vel que
represente o estoque de veÃ­culos da loja,
incluindo todas as declaraÃ§Ãµes de tipos que
possam ser necessÃ¡rias.
AlÃ©m disso, implementar as seguintes funÃ§Ãµes:
i. Exibir todos os carros do modelo m, ano de
fabricaÃ§Ã£o entre a1 e a2 (inclusive), com
valor nÃ£o superior a x reais;
ii. Reajustar os valores de todos os carros 0
km, considerando um aumento de 2.5%;
iii. Retirar do estoque um determinado veÃ­culo,
dada a sua placa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef struct
{

	int anoModelo, anoFabricacao;
} Tano;

typedef struct
{

	char placa[10];
	char modelo[15];
	char marca[15];
	char cor[15];
	float km;
	Tano ano;
	float valor;
	char tipo[10];

} Tcarros;

void preencher(Tcarros agencia[], int tamanho);
void printarCarros(Tcarros carro);
void exibirTodosOsCarros(Tcarros agencia[], int tamanho);
void exibirCarrosDadoAsCondicoes(Tcarros agencia[], int tamanho, char m[], int ano1, int ano2, float x);
void reajustaValor(Tcarros agencia[], int tamanho);
int removerCarrosDoEstoque(Tcarros agencia[], int *tamanho, char placa[]);

void main()
{
	Tcarros age[10];
	char modelo[10];
	int a1, a2;
	float valor;
	char placa[10];
	int tamanho = 2;

	printf("preenchendo dados do carro\n");
	preencher(age, 2);
	printf("\n");

	printf("Exibindo todos os carros:\n");
	exibirTodosOsCarros(age, 2);
	printf("\n");
	
	printf("Entre com o modelo que deseja buscar: ");
	fflush(stdin);
	gets(modelo);
	
	printf("Digite entre quais anos deseja buscar: ");
	scanf("%d", &a1);
	
	printf("Digite entre quais anos deseja buscar: ");
	scanf("%d", &a2);
	
	printf("Ate qual valor: ");
	scanf("%f", &valor);
	
	printf("Exibindo carros a partir de dados especificos:\n");
	exibirCarrosDadoAsCondicoes(age, 2, modelo, a1, a2, valor);
	printf("\n");

	printf("reajustando valor dos carros 0km\n");
	reajustaValor(age, 2);
	exibirTodosOsCarros(age, 2);
	printf("\n");

	printf("entre com a placa: ");
	fflush(stdin);
	gets(placa);

	if (removerCarrosDoEstoque(age, &tamanho, placa) == TRUE)
	{
		printf("Carro removido!");
		
		printf("Exibindo todos os carros apos a remocao:\n");
		exibirTodosOsCarros(age, tamanho);
		printf("\n");
	}
	else
	{
		if (removerCarrosDoEstoque(age, &tamanho, placa) == FALSE)
		{
			printf("Carro nao encontrado");
		}
	}
}
void preencher(Tcarros agencia[], int tamanho)
{
	int i;

	for (i = 0; i < tamanho; i++)
	{
		printf("Placa: ");
		fflush(stdin);
		gets(agencia[i].placa);

		printf("Modelo: ");
		fflush(stdin);
		gets(agencia[i].modelo);

		printf("Marca: ");
		fflush(stdin);
		gets(agencia[i].marca);

		printf("Cor: ");
		fflush(stdin);
		gets(agencia[i].cor);

		printf("km: ");
		scanf("%f", &agencia[i].km);

		printf("ano do carro: ");
		scanf("%d", &agencia[i].ano.anoModelo);

		printf("ano de fabricacao: ");
		scanf("%d", &agencia[i].ano.anoFabricacao);

		printf("valor:\n");
		scanf("%f", &agencia[i].valor);

		printf("tipo - Usado ou 0km: ");
		fflush(stdin);
		gets(agencia[i].tipo);
	}
}
void printarCarros(Tcarros carro)
{
	printf("Placa: %s\n", carro.placa);
	printf("Modelo %s\n", carro.modelo);
	printf("km: %.2f", carro.km);
	printf("Ano de fabricacao: %d\n", carro.ano.anoFabricacao);
	printf("Valor: %.2f\n", carro.valor);
	printf("Tipo: %s\n", carro.tipo);
}
void exibirTodosOsCarros(Tcarros agencia[], int tamanho)
{
	int i;

	for (i = 0; i < tamanho; i++)
	{
		printarCarros(agencia[i]);
	}
}
void exibirCarrosDadoAsCondicoes(Tcarros agencia[], int tamanho, char m[], int ano1, int ano2, float x)
{

	int i, cont = 0;

	for (i = 0; i < tamanho; i++)
	{
		if ((strcmp(m, agencia[i].modelo) == 0) &&
			(agencia[i].ano.anoFabricacao >= ano1) &&
			(agencia[i].ano.anoFabricacao <= ano2) &&
			(agencia[i].valor <= x))
		{
			printarCarros(agencia[i]);
			cont++;
		}
	}
	if (cont == 0)
	{
		printf("Nenhum carro encontrado.\n");
	}
}
void reajustaValor(Tcarros agencia[], int tamanho)
{
	int i;

	for (i = 0; i < tamanho; i++)
	{
		if (strcmp(agencia[i].tipo, "0km") == 0)
		{
			agencia[i].valor = agencia[i].valor * 1.025;
		}
	}
}
int removerCarrosDoEstoque(Tcarros agencia[], int *tamanho, char placa[])
{
	int i;

	for (i = 0; i < *tamanho; i++)
	{
		if (strcmp(agencia[i].placa, placa) == 0)
		{
			agencia[i] = agencia[i + 1];

			(*tamanho)--;

			return TRUE;
		}
	}
	return FALSE;
}
