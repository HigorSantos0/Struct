/*
	FAETERJ-Rio
	FPR - Professor Leonardo Vianna
	Data: 22/09/2022
	
	Lista de Exerc�cios VII (Structs)
	
	Quest�o 01:
	Uma loja de autom�veis mant�m os carros � venda sob a forma 
	de um vetor de structs contendo as seguintes informa��es, 
	para cada ve�culo: placa, modelo, marca, cor, quilometragem, 
	ano modelo/fabrica��o (deve ser um struct), valor e tipo 
	(usado ou 0 km, conforme o valor do campo quilometragem). 
	
	Pede-se a declara��o de uma vari�vel que represente o 
	estoque de ve�culos da loja, incluindo todas as declara��es 
	de tipos que possam ser necess�rias.

	Al�m disso, implementar as seguintes fun��es: 
		i.	Exibir todos os carros do modelo m, ano de fabrica��o 
		    entre a1 e a2 (inclusive), com valor n�o superior a 
			x reais;
		ii.	Reajustar os valores de todos os carros 0 km, 
		    considerando um aumento de 2.5%;
		iii.Retirar do estoque um determinado ve�culo, dada a 
		    sua placa.
*/

//importa��o de bibliotecas
#include <stdio.h>
#include <string.h>

//defini��o de constantes
#define TAM 1

#define TRUE 1
#define FALSE 0

//defini��o de tipos
typedef struct { 		//representa os anos de modelo e fabrica��o do carro
	int fabricacao;
	int modelo;
} TAno;

typedef struct {		//representa um carro e todas as suas informa��es
	char placa[9];
	char modelo[20];
	char marca [20];
	char cor[20];
	float km;
	TAno ano;
	float valor;
	char tipo[6];
} TCarro;

//prot�tipos das fun��es
void buscarCarros (TCarro agencia[], int quant, char m[], int *a1, int *a2, float x);
void reajustar0KM (TCarro agencia[], int quant, float taxa);
int removerCarroEstoque (TCarro agencia[], int *quant, char placa[]);

void preencherVetor (TCarro vetor[], int tamanho);
void exibirDadosCarro (TCarro carro);
void exibirTodosCarros (TCarro agencia[], int quant);

//main
void main ()
{
	//declara��o de vari�veis
	TCarro agencia[TAM];	
	int quantCarros = TAM;
	char mod[quantCarros];
	int ano1, ano2;
	float val;
	
	//preenchendo o vetor para que as demais fun��es possam ser testadas
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

	
	//chamando a fun��o que reajustar� os carros 0km
	reajustar0KM (agencia, quantCarros, 2.5);
	
	//exibindo os carros ap�s o reajuste
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
		printf ("\n\tPlaca n�o localizada!\n\n");
	}
	
}

//implementa��o das fun��es

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
	//1� carro
	strcpy (agencia[0].placa, "ABC 1234");
	strcpy (agencia[0].modelo, "HB20");
	strcpy (agencia[0].marca, "HYUNDAI");
	strcpy (agencia[0].cor, "PRATA");
	agencia[0].km = 20000;
	agencia[0].ano.modelo = 2016;
	agencia[0].ano.fabricacao = 2015;
	agencia[0].valor = 25000;
	strcpy (agencia[0].tipo, "USADO");	
	
	//2� carro
	strcpy (agencia[1].placa, "BCD 2345");
	strcpy (agencia[1].modelo, "CIVIC");
	strcpy (agencia[1].marca, "HONDA");
	strcpy (agencia[1].cor, "BRANCA");
	agencia[1].km = 0;
	agencia[1].ano.modelo = 2022;
	agencia[1].ano.fabricacao = 2022;
	agencia[1].valor = 90000;
	strcpy (agencia[1].tipo, "0KM");	
	
	//3� carro
	strcpy (agencia[2].placa, "CDE 3456");
	strcpy (agencia[2].modelo, "HB20");
	strcpy (agencia[2].marca, "HYUNDAI");
	strcpy (agencia[2].cor, "PRETA");
	agencia[2].km = 45000;
	agencia[2].ano.modelo = 2017;
	agencia[2].ano.fabricacao = 2017;
	agencia[2].valor = 35000;
	strcpy (agencia[2].tipo, "USADO");	
	
	//4� carro
	strcpy (agencia[3].placa, "EFG 4567");
	strcpy (agencia[3].modelo, "HB20");
	strcpy (agencia[3].marca, "HYUNDAI");
	strcpy (agencia[3].cor, "AZUL");
	agencia[3].km = 58000;
	agencia[3].ano.modelo = 2019;
	agencia[3].ano.fabricacao = 2018;
	agencia[3].valor = 40000;
	strcpy (agencia[3].tipo, "USADO");	
	
	//5� carro
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
	//declara��o de vari�veis
	int i;
	
	//percorrendo o vetor que representa a ag�ncia de carros
	for (i=0;i<quantidade;i++)
	{
		exibirDadosCarro (agencia[i]);
	}
}

//Exibir todos os carros do modelo m, ano de fabrica��o entre a1 
//e a2 (inclusive), com valor n�o superior a x reais.
void buscarCarros (TCarro agencia[], int quant, char m[], int *a1, int *a2, float x)
{
	//declara��o de vari�veis
	int i, cont = 0;
	
	//percorrendo o vetor
	for (i=0; i<quant; i++)
	{
		//verificando se o carro da posi��o 'i' atende aos filtros
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
	//declara��o de vari�veis
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

//Retirar do estoque um determinado ve�culo, dada a sua placa.
int removerCarroEstoque (TCarro ag[], int *quantidade, char placa[])
{
	//declara��o de vari�veis
	int i;
	
	//percorrendo o vetor que representa a ag�ncia de carros
	for (i=0; i<*quantidade; i++)
	{
		//verificando se a placa foi encontrada
		if (strcmp(ag[i].placa, placa) == 0)
		{
			//copiando o �ltimo carro para a posi��o sendo removida
			ag[i] = ag[(*quantidade)-1];
			
			//atualizando a quantidade de carros
			(*quantidade)--;
			
			//retornando TRUE, pois houve sucesso na tentativa de remo��o
			return TRUE;
		}
	}	
	
	//fracasso na tentativa de remo��o
	return FALSE;
}



