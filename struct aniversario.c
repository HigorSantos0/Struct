/*
	Questão 04: lista 7
Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
? Determinar a quantidade de pessoas que
fazem aniversário no mês M;
? Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.
*/

//importação de bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//definição de constantes
#define TAM 3

#define TRUE 1
#define FALSE 0

//definição de tipos
typedef struct { 	

	int dia;
	int mes;
	
} Tdata;

typedef struct{
	
	char nome[50];
	Tdata data;
	
}Tpessoa; 	

int quantAniversariantes(Tpessoa vetor[], int tamanho, int mes);
void exibirAniversariantes(Tpessoa vetor[], int tamanho, Tdata d1, Tdata d2);
int verificarIntervalo(Tdata datAniver, Tdata inf, Tdata sup);
void leituraDados(Tpessoa vetor[], int tamanho);
void leituraIntervalo(Tdata* d1, Tdata* d2);


void main()
{
	Tdata dat;
	Tdata inf, sup;
	Tpessoa vet[TAM];
	int quant, m;
	
	leituraDados(vet, TAM);
	
	printf("Entre com o mes que deseja saber");
	scanf("%d", &m);
	quant = quantAniversariantes(vet, TAM, m);
	printf("Quantidade de aniversariantes no mes desejado: %d\n", quant);
	   
    leituraIntervalo(&inf,&sup);
	exibirAniversariantes(vet, TAM, inf, sup);
	
}
int quantAniversariantes(Tpessoa vetor[], int tamanho, int mes)
{
	int i;
	int cont = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		if(vetor[i].data.mes == mes)
		{
			cont++;
		}
	}
	return cont;
	
}
void exibirAniversariantes(Tpessoa vetor[], int tamanho, Tdata d1, Tdata d2)
{
	int i, cont = 0;
	
	for(i = 0; i < tamanho; i++)
	{   

		if(verificarIntervalo (vetor[i].data, d1,d2))
		{
			printf("%s\n", vetor[i].nome);
			cont++;
		}
			
	}

	if(cont == 0)
	{
		printf("Nenhum aniversariante encontrado!");
	}
}
int verificarIntervalo(Tdata datAniver, Tdata inf, Tdata sup)
{
	if((datAniver.mes > inf.mes) && (datAniver.mes < sup.mes))
	{
		return TRUE;
	}
	if((datAniver.mes == inf.mes) && (datAniver.dia >= inf.dia))
	{
		return TRUE;
	}
	if((datAniver.mes == sup.mes) && (datAniver.dia <= sup.dia))
	{
		return TRUE;
	}
	
	return FALSE;
}
void leituraDados(Tpessoa vetor[], int tamanho)
{
	int i;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("Entre com o nome: ");
		fflush(stdin);
		gets(vetor[i].nome);
		
		printf("entre com o dia do aniversario: ");
		scanf("%d", &vetor[i].data.dia);
		
		printf("Entre com o mes do aniversario: ");
		scanf("%d", &vetor[i].data.mes);
		printf("\n");
	}
	
}

void leituraIntervalo(Tdata* d1, Tdata* d2){

    printf("Digite o dia e mes da data 1 - Inferior do intervalo: ");
    scanf("%d %d", &d1->dia,&d1->mes);

    printf("Digite o dia e mes da data 2 - Superior do intervalo: ");
    scanf("%d %d", &d2->dia,&d2->mes);

    printf("Intervalo: \nD1: <%d> <%d>\n D2: <%d> <%d>\n\n",d1->dia,d1->mes,d2->dia,d2->mes);

}

