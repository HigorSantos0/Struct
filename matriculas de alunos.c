/*
Questão 03:
Determinada instituição de ensino armazena,
sob a forma de vetores (de structs), as
seguintes informações:
? Alunos: nome, matrícula;
? Disciplinas do curso: nome, código;
? Inscrições realizadas: matrícula do aluno,
código da disciplina, semestre da inscrição
(semestre/ano).
Pede-se o desenvolvimento de funções que
realizem as seguintes operações:
i. Exibir, para cada aluno, o total de inscrições
já realizadas;
ii. Dado um semestre, informar para cada
disciplina o número de alunos inscritos.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//definição de constantes
#define TAM 2

#define TRUE 1
#define FALSE 0

typedef struct{
	
	int semestre;
	int ano;
	
}Tsemestre;

typedef struct{
	
	char nome[50];
	int matricula;
	char nomeCurso[50];
	char codigoCurso[10];
	Tsemestre semestreInscricao;
	
}TAluno;

int leituraDados(TAluno vetor[], int tamanho);
//int quantALunosPorDisciplina(TAluno vetor[], int tamanho, int cod, int sem);
int buscaInscri(TAluno vetor[], int tamanho, int s);

void main()
{
	TAluno vet[TAM];
	int quant;
	int s;
	
	printf("DISCIPLINAS E CODIGOS");
	printf("\n");
	printf("\n\nFRP/123f4q\n");
	printf("\n\nLES/213g3w\n");
	printf("\n\nCAW/335h4t\n");
	printf("\n\nCAL/657i8o\n");
	printf("\n\nSOP/092j1k\n");
	printf("\n\nDAW/008y9t\n");
	
	leituraDados(vet, TAM);
	

	printf("ENTRE PARA VERIFICAR NUMEROS DE INSCRITOS NO SEMESTRE: ");
	scanf("%d", &s);
	
	buscaInscri(vet, TAM, s);	
	
	
}
int leituraDados(TAluno vetor[], int tamanho)
{
	int i, cont = 0;
	
	for(i = 0; i < tamanho; i++)
	{
			
		
		printf("Entre com seu nome: ");
		fflush(stdin);
		gets(vetor[i].nome);
		
		printf("Entre com seu numero de matricula: ");
		scanf("%d", &vetor[i].matricula);
		
		printf("Entre com o nome do curso: ");
		fflush(stdin);
		gets(vetor[i].nomeCurso);
		
		printf("Codigo da disciplina: ");
		fflush(stdin);
		gets(vetor[i].codigoCurso);
		
		printf("Qual semestre da inscricao? ");
		scanf("%d", &vetor[i].semestreInscricao.semestre);
		
		printf("Entre com o ano da inscricao: ");
		scanf("%d", &vetor[i].semestreInscricao.ano);
		
		printf("\n");
		
		cont++;
		
		printf("Total de inscricoes ja feitas = %d\n", cont);
	}
	
	//return cont;
}

int buscaInscri(TAluno vetor[], int tamanho, int s)
{
	int i;
	int fpr = 0, caw = 0, les = 0, sop = 0, cal = 0, daw = 0;
	
	
	for(i = 0; i < tamanho; i++)
	{
		if(vetor[i].semestreInscricao.semestre == s)
		{
		
		
		if(strcmp(vetor[i].codigoCurso, "123f4q") == 0)
		{
			fpr++;
			
		}
		
		if(strcmp(vetor[i].codigoCurso, "213g3w") == 0)	
		{
			les++;
		
		}
		
		if(strcmp(vetor[i].codigoCurso, "335h4t") == 0)
		{
			caw++;
		}
		
		if(strcmp(vetor[i].codigoCurso, "657i8o") == 0)
		{
			cal++;
		}
		if(strcmp(vetor[i].codigoCurso, "092j1k") == 0)
		{
			sop++;
		}
		if(strcmp(vetor[i].codigoCurso, "008y9t") == 0)
		{
			daw++;
		}
	
	}
		
	}
	printf("FPR = %d\n", fpr);
	printf("LES = %d\n", les);
	printf("CAW = %d\n", caw);
	printf("CAL = %d\n", cal);
	printf("SOP = %d\n", sop);
	printf("DAW = %d\n", daw);
}


