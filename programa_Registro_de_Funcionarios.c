#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Conversão de letras minúsculas para maiúsculas
    void stringParaMaiusculo(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int main() {
    char nome[50], cargo[100], modelo, modeloTexto[20], senioridade[50];
    int nivel, opcao;
    char confirmacao;
    
//Cadastro do Funcionário
    printf("====================================================================\n");
    printf("        REGISTRO DE FUNCIONÁRIO     \n");
    printf("====================================================================\n\n");
    
    printf("[Informe seu nome completo]: ");
    scanf(" %[^\n]", nome);
    stringParaMaiusculo(nome);
    
    printf("[Informe seu cargo]: ");
    scanf(" %[^\n]", cargo);
    stringParaMaiusculo(cargo);
    
    printf("\nSeja bem vindo, %s!\n", nome);
    printf("Cargo informado: %s.\n", cargo);
    printf("\n====================\n\n");
    
//Verificação de Senioridade
    printf("SENIORIDADE\n");
    printf("1. Estagiário\n");
    printf("2. Júnior\n");
    printf("3. Pleno\n");
    printf("4. Sênior\n");
    printf("5. Líder\n");
    
    printf("\n[Informe seu nível (1-5)]: ");
    scanf("%d", &nivel);
    while (getchar() != '\n');
    
// Validação e conversão da senioridade
    do { 
        switch (nivel) {
            case 1: strcpy(senioridade, "ESTÁGIO"); break;
            case 2: strcpy(senioridade, "JÚNIOR"); break;
            case 3: strcpy(senioridade, "PLENO"); break;
            case 4: strcpy(senioridade, "SÊNIOR"); break;
            case 5: strcpy(senioridade, "LÍDER"); break;
            default: strcpy(senioridade, "Nível inválido! Tente novamente.");
        }
        stringParaMaiusculo(senioridade);
        
        if (nivel< 1 || nivel > 5) {
            printf("\n[Informe um nível válido (1-5)]: ");
            scanf("%d", &nivel);
            while(getchar() != '\n');
        }
        
    } while (nivel < 1 || nivel > 5);
    
    printf("%s\n", senioridade);
    printf("\n====================\n");
    
//Registro do Modelo de Trabalho
    printf("\nMODELO DE TRABALHO\n");
    printf("P - Presencial\n");
    printf("H - Híbrido\n");
    printf("R - Remoto\n");
    
    printf("\n[Informe seu modelo de trabalho (apenas letra)]: ");
    scanf(" %c", &modelo);
    while(getchar() != '\n');
    
    switch(toupper(modelo)) {
        case 'P': strcpy(modeloTexto, "PRESENCIAL"); break;
        case 'H': strcpy(modeloTexto, "HÍBRIDO"); break;
        case 'R': strcpy(modeloTexto, "REMOTO"); break;
        default: strcpy(modeloTexto, "MODELO INVÁLIDO");
    }
    
    printf("%s.\n", modeloTexto);
    printf("\n====================\n\n");
    
//Confirmação de informações
    do {
        printf("\nCONFIRME SUAS INFORMAÇÕES (S/N ou 1/0): \n");
        printf("[Nome] %s\n", nome);
        printf("[Cargo] %s\n", cargo);
        printf("[Senioridade] %s\n", senioridade);
        printf("[Modelo de Trabalho] %s\n", modeloTexto);
        printf("\nResposta: ");
        scanf(" %c", &confirmacao);
        while (getchar() != '\n');
        confirmacao = toupper(confirmacao);
        
        
        if (confirmacao == '1') confirmacao = 'S';
        if (confirmacao == '0') confirmacao = 'N';
        
        if (confirmacao == 'S') {
            
            break;
        } else if (confirmacao == 'N') {
            printf("\n[Informe qual campo deseja revisar (digite um número)]:\n");
            printf("1.Nome\n");
            printf("2.Cargo\n");
            printf("3.Senioridade\n");
            printf("4.Modelo de Trabalho\n\n");
            
            scanf("%d", &opcao);
            while(getchar() != '\n');
            
            
            switch(opcao) {
                case 1:
                    printf("\nNovo nome: ");
                    scanf(" %[^\n]", nome);
                    stringParaMaiusculo(nome);
                    while (getchar() != '\n');
                    break;
                case 2:
                    printf("\nNovo cargo: ");
                    scanf(" %[^\n]", cargo);
                    stringParaMaiusculo(cargo);
                    while (getchar() != '\n');
                    break;
                case 3: // apresenta o menu de opções novamente
                    printf("\nSENIORIDADE\n");
                    printf("1. Estagiário\n2. Júnior\n3. Pleno\n4. Sênior\n5. Líder\n");
                    printf("\nInforme o novo nível (1-5): ");
                    scanf("%d", &nivel);
                    while (getchar() != '\n');
                    
                    
                    switch (nivel) {
                        case 1: strcpy(senioridade, "ESTAGIÁRIO"); break;
                        case 2: strcpy(senioridade, "JÚNIOR"); break;
                        case 3: strcpy(senioridade, "PLENO"); break;
                        case 4: strcpy(senioridade, "SÊNIOR"); break;
                        case 5: strcpy(senioridade, "LÍDER"); break;
                        default: strcpy(senioridade, "NÍVEL INVÁLIDO!");
                    }
                    stringParaMaiusculo(senioridade);
                    break;
                case 4:
                    printf("\nMODELO DE TRABALHO\n");
                    printf("P - Presencial\nH - Híbrido\nR - Remoto\n");
                    printf("\nNovo modelo (apenas a letra): ");
                    scanf(" %c", &modelo);
                    while (getchar() != '\n');
                    
                  
                    switch (toupper(modelo)) {
                        case 'P': strcpy(modeloTexto, "PRESENCIAL"); break;
                        case 'H': strcpy(modeloTexto, "HÍBRIDO"); break;
                        case 'R': strcpy(modeloTexto, "REMOTO"); break;
                        default: strcpy(modeloTexto, "MODELO INVÁLIDO!");
                    }
                    stringParaMaiusculo(modeloTexto);
                    break;
                default:
                        printf("[Opção inválida! Digite um número de 1 a 4]\n");
            }
        } else {
            printf("\n[Opção inválida! Digite S/N ou 1/0]\n");
        }
        
    } while (confirmacao != 'S');
    
    printf("\n\n**** CADASTRO REALIZADO COM SUCESSO! ****");

    return 0;
}