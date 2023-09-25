// PROJETO DA DISCIPLINA DE ALGORITMOS
// ALUNO: GUSTAVO KESLEY DE FONTES NUNES
// PROFESSORES: DANIELA LOPES FREIRE, REUDISMAM ROLIM DE SOUZA


// O meu Projeto tem como ideia criar um sistema com um CRUD de usuários e pokemons
// O sistema conta com as seguintes funções: cadastrar usuário, cadastrar pokemon, listar pokemons, listar usuários, deletar usuário, deletar pokemon, editar usuário e editar pokemon.

// OBS: PROGRAMEI E TESTEI MEU CODIGO NO VSCODE E NO REPLIT


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <locale.h> 

// Definição da estrutura de usuário
typedef struct {
    char nome[20];
    char email[80];
    char senha[20];
} Usuario;

// Definição da estrutura de Pokémon
typedef struct {
    char nome[30];
    int numero;
    char tipo[20];
} Pokemon;

// Função para validar um email simples
bool validarEmail(char email[]) {
    int i;
    int countAt = 0; // Conta o número de "@" no email
    int countDot = 0; // Conta o número de "." no email
    
    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            countAt++;
        }
        if (email[i] == '.') {
            countDot++;
        }
    }

    // O email deve conter pelo menos um "@" e um "."
    if (countAt == 1 && countDot >= 1) {
        return true;
    } else {
        return false;
    }
}

// Função para cadastrar um novo usuário
void cadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    printf("Cadastro de Usuário:\n");
    printf("Nome: ");
    scanf("%s", usuarios[*numUsuarios].nome);

    // Validação de email
    do {
        printf("Email: ");
        scanf("%s", usuarios[*numUsuarios].email);
        if (!validarEmail(usuarios[*numUsuarios].email)) {
            printf("Email inválido. Tente novamente.\n");
        }
    } while (!validarEmail(usuarios[*numUsuarios].email));

    printf("Senha: ");
    scanf("%s", usuarios[*numUsuarios].senha);
    (*numUsuarios)++;
    printf("Usuário cadastrado com sucesso!\n");
}

// Função para realizar o login
int fazerLogin(Usuario usuarios[], int numUsuarios, char email[], char senha[]) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            printf("Login bem-sucedido. Bem-vindo, %s!\n", usuarios[i].nome);
            return i; // Retorna o índice do usuário para indicar o login bem-sucedido
        }
    }
    printf("Email ou senha incorretos. Tente novamente.\n");
    return -1; // Retorna -1 para indicar que o login falhou
}

// Função para editar um usuário com base no índice
void editarUsuario(Usuario usuarios[], int index) {
    printf("Editar Usuário:\n");
    printf("Novo Nome: ");
    scanf("%s", usuarios[index].nome);

    // Validação de email
    do {
        printf("Novo Email: ");
        scanf("%s", usuarios[index].email);
        if (!validarEmail(usuarios[index].email)) {
            printf("Email inválido. Tente novamente.\n");
        }
    } while (!validarEmail(usuarios[index].email));

    printf("Nova Senha: ");
    scanf("%s", usuarios[index].senha);

    printf("Usuário editado com sucesso!\n");
}

// Função para excluir um usuário com base no email
void excluirUsuario(Usuario usuarios[], int *numUsuarios, char email[]) {
    for (int i = 0; i < *numUsuarios; i++) {
        if (strcmp(email, usuarios[i].email) == 0) {
            for (int j = i; j < *numUsuarios - 1; j++) {
                strcpy(usuarios[j].nome, usuarios[j + 1].nome);
                strcpy(usuarios[j].email, usuarios[j + 1].email);
                strcpy(usuarios[j].senha, usuarios[j + 1].senha);
            }
            (*numUsuarios)--;
            printf("Usuário excluído com sucesso!\n");
            return;
        }
    }
    printf("Usuário não encontrado.\n");
}

// Função para listar usuários
void listarUsuarios(Usuario usuarios[], int numUsuarios) {
    printf("Lista de Usuários:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("\n");
    }
}

// Função para cadastrar um novo Pokémon
void cadastrarPokemon(Pokemon pokedex[], int *numPokemons) {
    printf("Cadastro de Pokémon:\n");
    printf("Nome do pokemon: ");
    scanf("%s", pokedex[*numPokemons].nome);

    printf("Número (ID): ");
    scanf("%d", &pokedex[*numPokemons].numero);

    printf("Tipo do pokemon: ");
    scanf("%s", pokedex[*numPokemons].tipo);

    (*numPokemons)++;
    printf("Pokémon cadastrado com sucesso!\n");
}

// Função para listar Pokémons
void listarPokemons(Pokemon pokedex[], int numPokemons) {
    printf("Lista de Pokémons:\n");
    for (int i = 0; i < numPokemons; i++) {
        printf("Nome: %s\n", pokedex[i].nome);
        printf("Número: %d\n", pokedex[i].numero);
        printf("Tipo: %s\n", pokedex[i].tipo);
        printf("\n");
    }
}

// Função para sortear um Pokémon aleatoriamente
void sortearPokemon(Pokemon pokedex[], int numPokemons) {
    if (numPokemons == 0) {
        printf("A Pokedex está vazia. Cadastre Pokémons antes de sortear.\n");
    } else {
        int indiceSorteado = rand() % numPokemons;
        printf("Parabéns! Você sorteou o Pokémon:\n");
        printf("Nome: %s\n", pokedex[indiceSorteado].nome);
        printf("Número: %d\n", pokedex[indiceSorteado].numero);
        printf("Tipo: %s\n", pokedex[indiceSorteado].tipo);
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    Usuario usuarios[100]; // Vetor de usuários
    int numUsuarios = 0;   // Número de usuários cadastrados

    Pokemon pokedex[100]; // Vetor de Pokémons
    int numPokemons = 0;  // Número de Pokémons na Pokedex

    // Inicialização com seis Pokémons pré-definidos
    strcpy(pokedex[numPokemons].nome, "Bulbasaur");
    pokedex[numPokemons].numero = 1;
    strcpy(pokedex[numPokemons].tipo, "Grama/Veneno");
    numPokemons++;

    strcpy(pokedex[numPokemons].nome, "Charmander");
    pokedex[numPokemons].numero = 4;
    strcpy(pokedex[numPokemons].tipo, "Fogo");
    numPokemons++;

    strcpy(pokedex[numPokemons].nome, "Squirtle");
    pokedex[numPokemons].numero = 7;
    strcpy(pokedex[numPokemons].tipo, "Água");
    numPokemons++;

    strcpy(pokedex[numPokemons].nome, "Pikachu");
    pokedex[numPokemons].numero = 25;
    strcpy(pokedex[numPokemons].tipo, "Elétrico");
    numPokemons++;

    strcpy(pokedex[numPokemons].nome, "Jigglypuff");
    pokedex[numPokemons].numero = 39;
    strcpy(pokedex[numPokemons].tipo, "Normal/Fada");
    numPokemons++;

    strcpy(pokedex[numPokemons].nome, "Eevee");
    pokedex[numPokemons].numero = 133;
    strcpy(pokedex[numPokemons].tipo, "Normal");
    numPokemons++;

    int usuarioLogadoIndex = -1; // Índice do usuário logado (-1 indica que nenhum usuário está logado)

    int opcao;
    do {
        system("cls"); 

        printf("======================== MENU ========================\n");
        printf("[1] Cadastrar novo usuário\n");
        printf("[2] Fazer login\n");
        printf("[3] Editar Usuário\n");
        printf("[4] Excluir Usuário\n");
        printf("[5] Listar Usuários\n");
        printf("[6] Pokedex\n");
        printf("[7] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case 2: {
                char email[80];
                char senha[20];
                printf("Email: ");
                scanf("%s", email);
                printf("Senha: ");
                scanf("%s", senha);
                usuarioLogadoIndex = fazerLogin(usuarios, numUsuarios, email, senha);
                if (usuarioLogadoIndex != -1) {
                }
                break;
            }
            case 3:
                if (usuarioLogadoIndex != -1) {
                    editarUsuario(usuarios, usuarioLogadoIndex);
                } else {
                    printf("Você precisa estar logado para editar seu perfil.\n");
                }
                break;
            case 4:
                if (usuarioLogadoIndex != -1) {
                    excluirUsuario(usuarios, &numUsuarios, usuarios[usuarioLogadoIndex].email);
                    usuarioLogadoIndex = -1; // Define o usuário logado como -1 (não logado)
                } else {
                    printf("Você precisa estar logado para excluir seu perfil.\n");
                }
                break;
            case 5:
                listarUsuarios(usuarios, numUsuarios);
                break;
            case 6:
                if (usuarioLogadoIndex != -1) {
                    int escolhaPokedex;
                    do {
                        system("cls");
                        printf("===================== POKÉDEX =====================\n");
                        printf("[1] Cadastrar Pokémon\n");
                        printf("[2] Listar Pokémons\n");
                        printf("[3] Sortear Pokémon\n");
                        printf("[4] Voltar\n");
                        printf("Escolha uma opção: ");
                        scanf("%d", &escolhaPokedex);

                        switch (escolhaPokedex) {
                            case 1:
                                cadastrarPokemon(pokedex, &numPokemons);
                                break;
                            case 2:
                                listarPokemons(pokedex, numPokemons);
                                break;
                            case 3:
                                sortearPokemon(pokedex, numPokemons);
                                break;
                            case 4:
                                break;
                            default:
                                printf("Opção inválida. Tente novamente.\n");
                                break;
                        }
                        printf("\nPressione Enter para continuar...");
                        getchar(); // Aguarda a entrada do Enter
                        getchar(); // Aguarda o Enter novamente
                    } while (escolhaPokedex != 4);
                } else {
                    printf("Você precisa estar logado para acessar a Pokedex.\n");
                }
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        printf("\nPressione Enter para continuar...");
        getchar(); 
        getchar(); 
    } while (opcao != 7);

    return 0;
}

