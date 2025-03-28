# Sistema de Cadastro de Funcionários

Este projeto é um sistema simples desenvolvido em C para gerenciar funcionários, permitindo cadastro, listagem e busca de dados. Os funcionários são armazenados em um arquivo de texto, garantindo persistência das informações.

## Funcionalidades
- Cadastrar novos funcionários com ID, nome e salário.
- Listar todos os funcionários cadastrados.
- Buscar funcionários pelo ID.
- Armazenamento de dados em arquivo (`funcionarios.txt`).
- Validação de entrada para evitar erros de digitação.

## Estrutura do Projeto
O código está organizado da seguinte forma:

📂 projeto ├── main.c # Código principal com o menu interativo ├── cadastro.c # Função para cadastrar funcionários ├── listar.c # Função para listar funcionários ├── buscar.c # Função para buscar funcionários por ID ├── funcionarios.txt # Arquivo onde os dados são armazenados ├── README.md # Documentação do projeto

bash
Copiar
Editar

## Como Executar
1. **Clonar o repositório**
   ```sh
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
Compilar o código

sh
Copiar
Editar
gcc main.c -o sistema
Executar o programa

sh
Copiar
Editar
./sistema
Uso do Sistema
Ao executar, o programa exibe um menu interativo:

csharp
Copiar
Editar
===== MENU =====
[1] Cadastrar Funcionário
[2] Listar Funcionários
[3] Buscar Funcionário
[4] Sair
Escolha uma opção:
Cadastrar Funcionário: Solicita ID, nome e salário do funcionário e armazena no arquivo.

Listar Funcionários: Exibe todos os funcionários cadastrados.

Buscar Funcionário: Permite pesquisar um funcionário pelo ID.

Sair: Encerra o programa.
