#include <stdio.h>

#define MAX_CANDIDATOS 10 // limite de candidatos
#define COD_BRANCO 0 // código do voto em branco
#define COD_NULO -1 // código do voto nulo (sem candidato associado)

typedef struct {
    int codigo; // código do candidato (de 1 a 99)
    int votos; // quantidade de votos recebidos
} Candidato;

typedef struct {
    int num_eleitores; // número total de eleitores inscritos
    int num_votantes; // número de eleitores que já votaram
    int num_abstencoes; // número de eleitores que não votaram
    int votos_brancos; // quantidade de votos em branco
    int votos_nulos; // quantidade de votos nulos (sem candidato associado)
    Candidato candidatos[MAX_CANDIDATOS]; // vetor de candidatos
} ZonaEleitoral;

void inicializaZonaEleitoral(ZonaEleitoral *zona, int num_eleitores) 
{
	int i;
	
    zona->num_eleitores = num_eleitores;
    zona->num_votantes = 0;
    zona->num_abstencoes = num_eleitores;
    zona->votos_brancos = 0;
    zona->votos_nulos = 0;
    for (i = 0; i < MAX_CANDIDATOS; i++) {
        zona->candidatos[i].codigo = i + 1; // código de candidato começa em 1
        zona->candidatos[i].votos = 0;
    }
}

void exibeResultados(ZonaEleitoral zona)
 {
 	int i;
    int votos_validos = zona.num_votantes - zona.votos_brancos - zona.votos_nulos;
    int votos_vencedor = 0, cod_vencedor = -1, cod_segundo = -1;
    printf("Total de votos:%d\n", votos_validos);
    for (i = 0; i < MAX_CANDIDATOS; i++) {
        printf("Candidato %02d: %d votos\n", zona.candidatos[i].codigo, zona.candidatos[i].votos);
        if (zona.candidatos[i].votos > votos_vencedor) {
            votos_vencedor = zona.candidatos[i].votos;
            cod_segundo = cod_vencedor;
            cod_vencedor = zona.candidatos[i].codigo;
        } else if (zona.candidatos[i].votos > zona.candidatos[cod_segundo-1].votos) {
            cod_segundo = zona.candidatos[i].codigo;
        }
    }
    printf("Votos em branco: %d\n", zona.votos_brancos);
    printf("Votos nulos: %d\n", zona.votos_nulos);
    printf("Abstenções: %d\n", zona.num_abstencoes);
    if (votos_validos == 0) {
        printf("Nenhum voto válido registrado.\n");
    } else if (votos_vencedor > votos_validos/2) {
        printf("Candidato %02d venceu com %d votos (%.2f%% dos votos válidos).\n", cod_vencedor, votos_vencedor, 100.0*votos_vencedor/votos_validos);
    } else if (cod_segundo != -1) {
        printf("Haverá segundo turno entre os candidatos %02d e %02d.\n", cod_vencedor, cod_segundo);
    } else {
        printf("Nenhum candidato obteve maioria absoluta de votos válidos.\n");
    }
}

int leVoto(ZonaEleitoral *zona) {
    int cod_candidato = COD_NULO;
    
    printf("\nCANDIDATOS\n\n");
    printf("codigo: 01\n");
    printf("codigo: 02\n");
    printf("codigo: 03\n");
    printf("codigo: 04\n");
    printf("codigo: 05\n");
    printf("codigo: 06\n");
    printf("codigo: 07\n");
    printf("codigo: 08\n");
    printf("codigo: 09\n");
    printf("codigo: 10\n");
    
    
    printf("Digite o código do candidato (ou 0 para voto em branco, -1 para voto nulo): ");
    scanf("%d", &cod_candidato);
    if (cod_candidato == COD_BRANCO) 
	{
        zona->votos_brancos++;
        printf("Voto em branco registrado.\n");
    } else if (cod_candidato > 0 && cod_candidato <= MAX_CANDIDATOS) {
        zona->candidatos[cod_candidato-1].votos++;
        printf("Voto registrado para o candidato %02d.\n", cod_candidato);
    } else if (cod_candidato == COD_NULO) {
        zona->votos_nulos++;
        printf("Voto nulo registrado.\n");
    } else {
        printf("Código de candidato inválido.\n");
    }
    zona->num_votantes++;
    zona->num_abstencoes--;
    return cod_candidato;
}

int main() 
{
    int num_eleitores;
    printf("Digite o número de eleitores inscritos: ");
    scanf("%d", &num_eleitores);
    ZonaEleitoral zona;
    inicializaZonaEleitoral(&zona, num_eleitores);
    int voto;
    do {
        voto = leVoto(&zona);
    } while (zona.num_votantes < zona.num_eleitores && voto != COD_NULO);
    exibeResultados(zona);
    return 0;
}
