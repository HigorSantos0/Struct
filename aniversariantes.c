/*
Questão 04:
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

#include  <stdio.h>
#include <string.h>

#define TAM 5

typedef struct{
	int dia, mes;
}TData;

typedef struct{
	char nome[30];
	TData dataAniversario;
}TPessoa;

int aniversariantesMes(TPessoa vetor[], int tamanho, int mes); 
void exibirAniversariantes(TPessoa vetor[], int tamanho, TData d1, TData d2);
int verificaDataIntervalo(TData d1, TData d2, TData data);
void preencheVetor(TPessoa vetor[], int tamanho);

void main()
{
	TPessoa pessoas[TAM];
	TData data1, data2;
	int resp;
	
	preencheVetor(pessoas, TAM);
	
	resp = aniversariantesMes(pessoas, TAM, 8);
	
	printf("Quantidade de pessoas que fazem aniversario no mes buscado: %d\n", resp);
	
	data1.dia = 15;
	data1.mes = 4; 
	
	data2.dia = 5;
	data2.mes = 10; 
	
	exibirAniversariantes(pessoas, TAM, data1, data2);
}
int aniversariantesMes(TPessoa vetor[], int tamanho, int mes)
{
	int i, cont = 0;
	
	for(i = 0; i < tamanho; i++)
	{
		if(vetor[i].dataAniversario.mes == mes)
		{
			cont++;
		}
	}
	return cont;
}
void exibirAniversariantes(TPessoa vetor[], int tamanho, TData d1, TData d2)
{
	int i;
	
	printf("Pessoas que fazem aniversario entre %d/%d e %d/%d:\n\n", d1.dia, d1.mes, d2.dia, d2.mes);
	
	for(i = 0; i < tamanho; i++)
	{
		if(verificaDataIntervalo(d1, d2, vetor[i].dataAniversario) == 1)
		{
			printf("nome: %s\n", vetor[i].nome);
			printf("Data de aniversario: %d/%d\n\n", vetor[i].dataAniversario.dia, vetor[i].dataAniversario.mes);
		}
	}
}
int verificaDataIntervalo(TData d1, TData d2, TData data)
{
	if((data.mes > d1.mes) && (data.mes < d2.mes))
	{
		return 1;
	}
	else
		{
			if(data.mes == d1.mes)
			{
				if(data.dia >= d1.dia)	
				{
					return 1;
				}
			}
			else
				{
					
					if(data.mes == d2.mes)
					{
						if(data.dia <= d2.dia)
						{
							return 1;
						}
					}		
				}
			
		}
		return 0;
}
void preencheVetor(TPessoa vetor[], int tamanho)
{
	int i;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("Nome: ");
		fflush(stdin);
		gets(vetor[i].nome);
		
		printf("Data de aniversario: ");
		scanf("%d %d", &vetor[i].dataAniversario.dia, &vetor[i].dataAniversario.mes);
	}
}
