/*
* Atividade Prática - Exercício 5
* Aluno: Marcos Fabricio Sizanosky RU-3395570
* Professor: Winston Sen Lun Fung
* Data criação: 04/05/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max 6

FILE* arq;

// Struct que registra os dados do cliente.
typedef struct {
    char nome_completo[80];
    char cpf[16];
    char telefone[16];
    char email[80];
} Cliente; // Define um nome para struct.
Cliente Cadastros[max]; // Cria um vetor para armazenar o cadastro de 6 clientes.

// Função para limpar o buffer do teclado após uma entrada do usuário.
void limpa_buffer_teclado();
// Função para adicionar um cliente ao cadastro.
void cadastra_cliente();
// Função gera um arquivo.csv e armazena os dados do cadastro.
void grava_arquivo();

int main() {
    printf("Hello World!\n\n");

    // Função para habilitar a utilização de caracteres da língua portuguesa.
    setlocale(LC_ALL, "Portuguese");

    // Cabeçalho do programa e informações ao usuário.
    printf("#=#=#=#= CADASTRO CLIENTES =#=#=#=#\n\n");
    printf("- Digite todos os dados solicitados.\n");
    printf("- Os cadastros efetuados serão armazenados no arquivo < 3395570.csv >\n\n");

    // Entradas do usuário.
    cadastra_cliente();

    // Cria um arquivo.csv e grava os dados do cadastro.
    grava_arquivo();

    return 0;
}

// Funções.

void limpa_buffer_teclado() {
    /* Está função é utilizada para limpar o buffer do teclado após
     * uma entrada do usuário.
     */

    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void cadastra_cliente() {
    /* Esta função utiliza um laço "for" para percorrer os índices do vetor 
     * "Cadastros" e adiciona os dados na struct "Cliente" formando n(max) 
     * cadastros de clientes.
    */

    int i; // Variável usada para iterar como índice do vetor "Cadastros".

    /* O bloco abaixo solicita as entradas do usuário usando um laço "for",
     * armazena os dados na struct "Cliente" dentro do vetor "Cadastros",
     * e substitui o marcador "\n" da entrada por "\0".
    */

    for (i = 0; i < max; i++) { 

        // Entrada do usuário.
        printf("Nome completo: ");
        fgets(Cadastros[i].nome_completo, 79, stdin);
        //limpa_buffer_teclado();

        // Verifica o tamanho da string e substitui os marcadores.
        size_t nome = strlen(Cadastros[i].nome_completo) - 1;
            if (Cadastros[i].nome_completo[nome] == '\n')
                Cadastros[i].nome_completo[nome] = '\0';

        // Entrada do usuário.
        printf("CPF (somente números): ");
        fgets(Cadastros[i].cpf, 15, stdin);
        //limpa_buffer_teclado();
        
        // Verifica o tamanho da string e substitui os marcadores.
        size_t cpf = strlen(Cadastros[i].cpf) - 1;
        if (Cadastros[i].cpf[cpf] == '\n')
            Cadastros[i].cpf[cpf] = '\0';

        // Entrada do usuário.v
        printf("Telefone (somente números): ");
        fgets(Cadastros[i].telefone, 15, stdin);
        //limpa_buffer_teclado();
        
        // Verifica o tamanho da string e substitui os marcadores.
        size_t tel = strlen(Cadastros[i].telefone) - 1;
        if (Cadastros[i].telefone[tel] == '\n')
            Cadastros[i].telefone[tel] = '\0';

        // Entrada do usuário.
        printf("E-mail: ");
        fgets(Cadastros[i].email, 79, stdin);
        //limpa_buffer_teclado();
       
        // Verifica o tamanho da string e substitui os marcadores.
        size_t email = strlen(Cadastros[i].email) - 1;
        if (Cadastros[i].email[email] == '\n')
            Cadastros[i].email[email] = '\0';

        printf("Cliente cadastrado com sucesso!\n\n");
    }
}

void grava_arquivo() {
    /* Esta função cria o arquivo "3395570.csv" onde serão armazenados os 
     * dados do vetor "Cadastros" utilizando um laço "for" para percorer os 
     * índices do vetor "Cadastros" e "escreve" o arquivo com os dados da 
     * struct "Cliente". 
    */

    errno_t err;
    int i;

    err = fopen_s(&arq, "3395570.csv", "w");

    if (err == 0) {
        printf("Criando arquivo \"3395570.csv\"...\n");
        printf("Abrindo arquivo para escrita...\n");
        printf("Gravando dados...\n");

        for (i = 0; i < max; i++) {

            fprintf_s(arq, "%s;", Cadastros[i].nome_completo);
            fprintf_s(arq, "%s;", Cadastros[i].cpf);
            fprintf_s(arq, "%s;", Cadastros[i].telefone);
            fprintf_s(arq, "%s;\n", Cadastros[i].email);
        }
        fclose(arq);
    }

    else {
        printf("Erro ao abrir o arquivo!\n");
    }
}