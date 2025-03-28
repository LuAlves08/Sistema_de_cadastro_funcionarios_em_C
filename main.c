#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    float salario;
} Funcionario;
void cadastrarFuncionario() {
    FILE *arquivo = fopen("funcionarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Funcionario novo;

    printf("\nDigite o ID do funcionário: ");
    while (scanf("%d", &novo.id) != 1) {
        printf("Entrada inválida! Digite um número inteiro para o ID: ");
        while (getchar() != '\n'); // Limpa buffer
    }
    getchar(); // Limpa o \n do buffer

    printf("Digite o nome do funcionário: ");
    fgets(novo.nome, 50, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Digite o salário do funcionário: ");
    while (scanf("%f", &novo.salario) != 1) {
        printf("Entrada inválida! Digite um valor numérico para o salário: ");
        while (getchar() != '\n');
    }
    getchar();

    fprintf(arquivo, "%d;%s;%.2f\n", novo.id, novo.nome, novo.salario);
    fclose(arquivo);

    printf("Funcionário cadastrado com sucesso!\n");
}
