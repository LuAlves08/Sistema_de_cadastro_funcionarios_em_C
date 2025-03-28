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
void listarFuncionarios() {
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    Funcionario temp;
    int contador = 0;

    printf("\n===== Lista de Funcionários =====\n");
    while (fscanf(arquivo, "%d;%49[^;];%f\n", &temp.id, temp.nome, &temp.salario) == 3) {
        printf("ID: %d\n", temp.id);
        printf("Nome: %s\n", temp.nome);
        printf("Salário: R$ %.2f\n", temp.salario);
        printf("-------------------------------\n");
        contador++;
    }

    if (contador == 0) {
        printf("Nenhum funcionário encontrado.\n");
    }

    fclose(arquivo);
}
void buscarFuncionario() {
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("\nNenhum funcionário cadastrado ainda.\n");
        return;
    }

    int idBusca, encontrado = 0;
    Funcionario temp;

    printf("\nDigite o ID do funcionário que deseja buscar: ");
    while (scanf("%d", &idBusca) != 1) {
        printf("Entrada inválida! Digite um número inteiro: ");
        while (getchar() != '\n');
    }
    getchar();

    while (fscanf(arquivo, "%d;%49[^;];%f\n", &temp.id, temp.nome, &temp.salario) == 3) {
        if (temp.id == idBusca) {
            printf("\n===== Funcionário Encontrado =====\n");
            printf("ID: %d\n", temp.id);
            printf("Nome: %s\n", temp.nome);
            printf("Salário: R$ %.2f\n", temp.salario);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nFuncionário com ID %d não encontrado.\n", idBusca);
    }

    fclose(arquivo);
}
