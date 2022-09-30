/*
Exercício:

Considere a existência de um vetor no qual cada posição pode armazenar o nome do aluno, 
as notas de AV1 e AV2, sua média e a situação (aprovado, reprovado ou em AVF). Pede-se:

i) A declaração do vetor, assim como de todos os tipos de dados necessários, caso existam;
ii) Uma função que leia os dados de todos os alunos da turma;
iii) Uma função que calcule a média de cada aluno (e a armazene no vetor), assim como a sua situação;
iv) Uma função que, dado um número inteiro (1-aprovado;2-reprovado;3-em AVF), exiba todos 
    os alunos que estão nesta situação.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAM 3

typedef struct{
	
	float av1, av2, media;
	char nome[50];
	char situacao[15];
	
}TAlunos;

void leituraDados(TAlunos vetor[], int tamanho);
void calculaMediaSituacao(TAlunos vetor[], int tamanho);
void exibirAlunosporSituacao(TAlunos vetor[], int tamanho, int situ);


void main()
{
	TAlunos turma[TAM];
	
	leituraDados(turma, TAM);
	calculaMediaSituacao(turma, TAM);
	
	printf("\nAlunos Aprovados\n");
	exibirAlunosporSituacao(turma, TAM, 1);
	
	printf("\nAlunos Reprovados\n");
	exibirAlunosporSituacao(turma, TAM, 2);
	
	printf("\nAlunos AVF\n");
	exibirAlunosporSituacao(turma, TAM, 3);
}
void leituraDados(TAlunos vetor[], int tamanho)
{
	int i;
	
	for(i = 0; i < tamanho; i++)
	{
		printf("Entre com o nome: ");
		fflush(stdin);
		gets(vetor[i].nome);
		
		printf("Entre com a av1: ");
		scanf("%f", &vetor[i].av1);
		
		printf("Entre com a av2: ");
		scanf("%f", &vetor[i].av2);
		printf("\n");
	}
	
}
void calculaMediaSituacao(TAlunos vetor[], int tamanho)
{
	int i;
	
	for(i = 0; i < tamanho; i++)
	{
		vetor[i].media = (vetor[i].av1 + vetor[i].av2)/2;
		
		//calculando a situação
		
		if(vetor[i].media >= 6)
		{
			strcpy(vetor[i].situacao, "APROVADO");
		}
		else
			{
				if(vetor[i].media < 4)
				{
					strcpy(vetor[i].situacao, "REPROVADO");	
				}
				else
					{
						strcpy(vetor[i].situacao, "AVF");
					}
				
			}
	}
}
void exibirAlunosporSituacao(TAlunos vetor[], int tamanho, int situ)
{
	char busca[15];
	int i;
	
	//mapeando parâmetros 'sit' para a variavel 'busca'
	
	switch(situ)
	{
		case 1: strcpy(busca, "APROVADO");
				break;
				
		case 2: strcpy(busca, "REPROVADO");
				break;
				
		case 3: strcpy(busca, "AVF");
				break;
	}
	
	//varrendo o vetor em busca da situação desejada
	
	for(i = 0; i < tamanho; i++)
	{
		if(strcmp(vetor[i].situacao,busca) == 0)
		{
			printf("\n nome: %s\n Av1: %.1f - Av2: %.1f - media: %.1f\n", vetor[i].nome, vetor[i]. av1, vetor[i]. av2, vetor[i]. media);
		}
	}
}



