#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	
	int dia;
	int mes;
	int ano;
}Tdata;

typedef struct{
	
	char nome[50];
	char endereco[100];
	char genero;
	Tdata datanascimento;
}Tpessoa;

void main()
{
	Tpessoa p[30], p1;
	
	
	//dados da primeira pessoa
	
	//Nome: Joao da silva
	strcpy(p[0].nome, "Joao da Silva");
	
	//endereço: rua das flores, 123, Quintino
	strcpy(p[0].endereco, "rua das flores, 123, Quintino");

	//genero: m
	p[0].genero = 'M';
	
	//nasceu no dia 22/11/1990							
	p[0].datanascimento.dia = 22;
	p[0].datanascimento.mes = 11;
	p[0].datanascimento.ano = 1990;
	
	//p1.datanascimento.dia = 22;		
	//p1.datanascimento.mes = 11;
	//p1.datanascimento.ano = 1990;
	
	// Ou fazer tudo receber p[0] = p1;
	
	
	
}
