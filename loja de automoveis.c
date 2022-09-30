/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	Data: 22/09/2022
	
	Lista de Exercícios VII (Structs)
	
	Questão 01:
	Uma loja de automóveis mantém os carros à venda sob a forma 
	de um vetor de structs contendo as seguintes informações, 
	para cada veículo: placa, modelo, marca, cor, quilometragem, 
	ano modelo/fabricação (deve ser um struct), valor e tipo 
	(usado ou 0 km, conforme o valor do campo quilometragem). 
	
	Pede-se a declaração de uma variável que represente o 
	estoque de veículos da loja, incluindo todas as declarações 
	de tipos que possam ser necessárias.

	Além disso, implementar as seguintes funções: 
		i.	Exibir todos os carros do modelo m, ano de fabricação 
		    entre a1 e a2 (inclusive), com valor não superior a 
			x reais;
		ii.	Reajustar os valores de todos os carros 0 km, 
		    considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado veículo, dada a 
		    sua placa.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>

//definição de constantes
#define TAM 1

#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct { 		//representa os anos de modelo e fabricação do carro
	int fabricacao;
	int modelo;
} TAno;

typedef struct {		//representa um carro e todas as suas informações
	char placa[9];
	char modelo[20];
	char marca [20];
	char cor[20];
	float km;
	TAno ano;
	float valor;
	char tipo[6];
} TCarro;

//protótipos das funções
void buscarCarros (TCarro agencia[], int quant, char m[], int *a1, int *a2, float x);
void reajustar0KM (TCarro agencia[], int quant, float taxa);
int removerCarroEstoque (TCarro agencia[], int *quant, char placa[]);

void preencherVetor (TCarro vetor[], int tamanho);
void exibirDadosCarro (TCarro carro);
void exibirTodosCarros (TCarro agencia[], int quant);

//main
void main ()
{
	//declaração de variáveis
	TCarro agencia[TAM];	
	int quantCarros = TAM;
	char mod[quantCarros];
	int ano1, ano2;
	float val;
	
	//preenchendo o vetor para que as demais funções possam ser testadas
	preencherVetor (agencia, quantCarros);
		
	//exibindo os carros que atenderem aos filtros definidos
	
	printf("Entre com o modelo: ");
	fflush(stdin);
	gets(agencia[quantCarros].modelo);
	
	printf("Entre com o ano: ");
	scanf("%d", &ano1);
	
	printf("Entre com o segundo ano: ");
	scanf("%d", &ano2);
	
	printf("Ate qual valor? ");
	scanf("%f", &val);
	
	//Chamada 1
	printf ("Chamada 1 (exibindo carros por filtro):\n");
	buscarCarros (agencia, quantCarros, mod, &ano1, &ano2, val);

	
	//chamando a função que reajustará os carros 0km
	reajustar0KM (agencia, quantCarros, 2.5);
	
	//exibindo os carros após o reajuste
	printf ("\n\nExibindo os carros apos o reajuste:\n");
	exibirTodosCarros (agencia, quantCarros);

	//Chamada 1
	printf ("Chamada 1 (removendo carro do estoque):\n");
	if (removerCarroEstoque (agencia, &quantCarros, "XYZ 1234") == TRUE)
	{
		printf ("\n\tCarro removido com sucesso!\n");
		exibirTodosCarros (agencia, quantCarros);
	}
	else
	{
		printf ("\n\tPlaca não localizada!\n\n");
	}
	
}

//implementação das funções

void preencherVetor (TCarro vetor[], int tamanho)
{
	
	int i;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("PLACA: ");
		fflush(stdin);
		gets(vetor[i].placa);
		
		printf("MODELO: ");
		fflush(stdin);
		gets(vetor[i].modelo);
		
		printf("MARCA: ");
		fflush(stdin);
		gets(vetor[i].marca);
		
		printf("COR: ");
		fflush(stdin);
		gets(vetor[i].cor);
		
		printf("TIPO: ");
		fflush(stdin);
		gets(vetor[i].tipo);
		
		printf("KM: ");
		scanf("%f",&vetor[i].km);
		
		printf("ANO DO CARRO: ");
		scanf("%d", &vetor[i].ano.modelo);
		
		printf("FABRICADO: ");
		scanf("%d", &vetor[i].ano.fabricacao);
		
		printf("VALOR: ");
		scanf("%f", &vetor[i].valor);
		
		printf("\n");
		
	}
	/*
	//1º carro
	strcpy (agencia[0].placa, "ABC 1234");
	strcpy (agencia[0].modelo, "HB20");
	strcpy (agencia[0].marca, "HYUNDAI");
	strcpy (agencia[0].cor, "PRATA");
	agencia[0].km = 20000;
	agencia[0].ano.modelo = 2016;
	agencia[0].ano.fabricacao = 2015;
	agencia[0].valor = 25000;
	strcpy (agencia[0].tipo, "USADO");	
	
	//2º carro
	strcpy (agencia[1].placa, "BCD 2345");
	strcpy (agencia[1].modelo, "CIVIC");
	strcpy (agencia[1].marca, "HONDA");
	strcpy (agencia[1].cor, "BRANCA");
	agencia[1].km = 0;
	agencia[1].ano.modelo = 2022;
	agencia[1].ano.fabricacao = 2022;
	agencia[1].valor = 90000;
	strcpy (agencia[1].tipo, "0KM");	
	
	//3º carro
	strcpy (agencia[2].placa, "CDE 3456");
	strcpy (agencia[2].modelo, "HB20");
	strcpy (agencia[2].marca, "HYUNDAI");
	strcpy (agencia[2].cor, "PRETA");
	agencia[2].km = 45000;
	agencia[2].ano.modelo = 2017;
	agencia[2].ano.fabricacao = 2017;
	agencia[2].valor = 35000;
	strcpy (agencia[2].tipo, "USADO");	
	
	//4º carro
	strcpy (agencia[3].placa, "EFG 4567");
	strcpy (agencia[3].modelo, "HB20");
	strcpy (agencia[3].marca, "HYUNDAI");
	strcpy (agencia[3].cor, "AZUL");
	agencia[3].km = 58000;
	agencia[3].ano.modelo = 2019;
	agencia[3].ano.fabricacao = 2018;
	agencia[3].valor = 40000;
	strcpy (agencia[3].tipo, "USADO");	
	
	//5º carro
	strcpy (agencia[4].placa, "FGH 5678");
	strcpy (agencia[4].modelo, "ECOSPORT");
	strcpy (agencia[4].marca, "FORD");
	strcpy (agencia[4].cor, "VERDE");
	agencia[4].km = 0;
	agencia[4].ano.modelo = 2022;
	agencia[4].ano.fabricacao = 2022;
	agencia[4].valor = 85000;
	strcpy (agencia[4].tipo, "0KM");	
	*/
}



void exibirDadosCarro (TCarro carro)
{
	printf("Placa: %s\n", carro.placa);
	printf("Marca/modelo: %s/%s\n", carro.marca, carro.modelo);
	printf("Km: %.1f\n", carro.km);
	printf("Ano: %d/%d\n", carro.ano.fabricacao, carro.ano.modelo);
	printf("Valor: R$ %.2f\n", carro.valor);
	printf("Tipo: %s\n\n", carro.tipo);
}

void exibirTodosCarros (TCarro agencia[], int quantidade)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (agencia[i]);
	}
}

//Exibir todos os carros do modelo m, ano de fabricação entre a1 
//e a2 (inclusive), com valor não superior a x reais.
void buscarCarros (TCarro agencia[], int quant, char m[], int *a1, int *a2, float x)
{
	//declaração de variáveis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		//verificando se o carro da posição 'i' atende aos filtros
		if ((strcmp (m,agencia[i].modelo) == 0) && 
		    (agencia[i].ano.fabricacao >= *a1) && 
			(agencia[i].ano.fabricacao <= *a2) && 
			(agencia[i].valor <= x))
		{
			exibirDadosCarro (agencia[i]);
			cont++;
		}
	}
	
	//verificando se nenhum carro atendeu aos filtros
	if (cont == 0)
	{
		printf ("Nenhum carro encontrado!");
	}
}
  
//Reajustar os valores de todos os carros 0 km, considerando um 
//aumento de 2.5%.
void reajustar0KM (TCarro agencia[], int quant, float taxa)
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor
	for (i=0; i<quant ; i++)
	{
		//verificando se trata-se de um carro zero
		//if (agencia[i].km == 0)   ou
		if (strcmp (agencia[i].tipo, "0KM") == 0)
		{
			//agencia[i].valor = agencia[i].valor + (taxa/100) * agencia[i].valor;
			agencia[i].valor *= 1 + taxa/100; 
		}
	}
}

//Retirar do estoque um determinado veículo, dada a sua placa.
int removerCarroEstoque (TCarro ag[], int *quantidade, char placa[])
{
	//declaração de variáveis
	int i;
	
	//percorrendo o vetor que representa a agência de carros
	for (i=0; i<*quantidade; i++)
	{
		//verificando se a placa foi encontrada
		if (strcmp(ag[i].placa, placa) == 0)
		{
			//copiando o último carro para a posição sendo removida
			ag[i] = ag[(*quantidade)-1];
			
			//atualizando a quantidade de carros
			(*quantidade)--;
			
			//retornando TRUE, pois houve sucesso na tentativa de remoção
			return TRUE;
		}
	}	
	
	//fracasso na tentativa de remoção
	return FALSE;
}



