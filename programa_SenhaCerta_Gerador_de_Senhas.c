#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Nome e Operação do software    
    printf("\n\xF0\x9F\x94\x92 SenhaCerta - Gerador de senhas\n");

    // Inicializa semente para números aleatórios (chamar apenas uma vez)
    srand(time(NULL));

    // Declaração de variáveis
    int tipoSenha, tamanhoSenha, senhaAceita;
    char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char numeros[] = "0123456789";
    char especiais[] = "!@#$%^&*()-_=+[]{}<>?";
    char alfanumerica[] = "0123456789"
                         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "abcdefghijklmnopqrstuvwxyz"
                         "!@#$%^&*()-_=+[]{}<>?";

    printf("\nBem vindo ao gerador de senhas rápido, simples e seguro que cria senhas personalizadas com vários tipos de caracteres,\n"
           "ajudando você a proteger suas contas com a senha certa.\n");

    do {
        // Escolha do tipo de senha com validação simples
        do {
            printf("\nEscolha o tipo de senha desejada: \n");
            printf("1. Numérica\n2. Alfabética\n3. Alfanumérica\n4. Caracteres Especiais\n");
            if (scanf("%d", &tipoSenha) != 1) {
                printf("Entrada inválida. Digite um número.\n");
                while(getchar() != '\n'); // Limpa buffer
                tipoSenha = 0; // força repetição
                continue;
            }
            if (tipoSenha < 1 || tipoSenha > 4) {
                printf("Tipo inválido. Tente novamente.\n");
            }
        } while (tipoSenha < 1 || tipoSenha > 4);

        // Define o conjunto de caracteres conforme o tipo
        char *conjunto;
        switch(tipoSenha) {
            case 1:
                conjunto = numeros;
                printf("Numérica: 0123456789\n");
                break;
            case 2:
                conjunto = letras;
                printf("Alfabética: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz\n");
                break;
            case 3:
                conjunto = alfanumerica;
                printf("Alfanumérica: 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                       "abcdefghijklmnopqrstuvwxyz!@#$%%^&*()-_=+[]{}<>?\n");
                break;
            case 4:
                conjunto = especiais;
                printf("Caracteres Especiais: !@#$%%^&*()-_=+[]{}<>?\n");
                break;
        }

        // Escolha do tamanho da senha
        do {
            printf("\nInforme o tamanho da senha desejada (1 a 30): \n");
            if (scanf("%d", &tamanhoSenha) != 1) {
                printf("Entrada inválida. Digite um número.\n");
                while(getchar() != '\n'); // limpa buffer
                tamanhoSenha = 0; // força repetição
                continue;
            }
            if (tamanhoSenha < 1 || tamanhoSenha > 30) {
                printf("Tamanho inválido. Tente novamente.\n");
            }
        } while (tamanhoSenha < 1 || tamanhoSenha > 30);

        // Geração da senha aleatória
        int tamanhoConjunto = strlen(conjunto);
        printf("\nSenha gerada: ");
        for (int i = 0; i < tamanhoSenha; i++) {
            int indiceAleatorio = rand() % tamanhoConjunto;
            printf("%c", conjunto[indiceAleatorio]);
        }
        printf("\n");

        // Confirmação da senha
        printf("\nVocê confirma o aceite da senha (digite 1)?\nOu deseja gerar uma nova senha (digite 0)?\n");
        while (scanf("%d", &senhaAceita) != 1) {
            printf("Entrada inválida. Digite 1 para aceitar ou 0 para gerar nova senha.\n");
            while(getchar() != '\n');
        }

    } while (senhaAceita != 1);

    printf("\nSenha gerada com sucesso!\n");

    // Manual simples de boas práticas
    printf("\nPreparamos algumas recomendações para tornar sua experiência melhor:\n");
    printf("• Nunca compartilhe suas senhas.\n");
    printf("• Use um gerenciador de senhas confiável.\n");
    printf("• Altere suas senhas periodicamente.\n");
    printf("• Use senhas longas e complexas.\n");
    printf("• Não reutilize senhas em diferentes serviços.\n");

    printf("\nObrigado por usar nossos serviços!\n");
    printf("A DEUS TODA A GLÓRIA!\n");

    return 0;
}
