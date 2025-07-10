#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[3];
    char codigo[10];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

void cadastrarCidade(struct Cidade *cidade) {
    printf("Digite o estado (sigla, ex: SP): ");
    scanf("%s", cidade->estado);
    printf("Digite o codigo da cidade (ex: A01): ");
    scanf("%s", cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", cidade->nome);
    printf("Digite a populacao: ");
    scanf("%lu", &cidade->populacao);
    printf("Digite a area (km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em milhoes): ");
    scanf("%f", &cidade->pib);
    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &cidade->pontosTuristicos);
    cidade->densidadePopulacional = cidade->populacao / cidade->area;
    cidade->pibPerCapita = cidade->pib / cidade->populacao;
}

void exibirCidade(struct Cidade cidade) {
    printf("\nCidade: %s\n", cidade.nome);
    printf("Estado: %s\n", cidade.estado);
    printf("Codigo: %s\n", cidade.codigo);
    printf("Populacao: %lu\n", cidade.populacao);
    printf("Area: %.2f km²\n", cidade.area);
    printf("PIB: %.2f milhoes\n", cidade.pib);
    printf("Pontos Turisticos: %d\n", cidade.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade.densidadePopulacional);
    printf("PIB per Capita: %.2f milhoes/hab\n\n", cidade.pibPerCapita);
}

int main() {
    struct Cidade cidade1, cidade2;
    
    printf("Cadastro da Cidade 1:\n");
    cadastrarCidade(&cidade1);
    printf("\nCadastro da Cidade 2:\n");
    cadastrarCidade(&cidade2);
    
    printf("\nCidades cadastradas:\n");
    exibirCidade(cidade1);
    exibirCidade(cidade2);
    
    return 0;
}