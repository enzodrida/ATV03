#include <stdio.h>
#include <stdlib.h>

int main()
    {
    int opcao, ordenacao, quantidade, numero
    int etapa = 1;
    do {
        // Exibe o menu principal
        printf("===== MENU =====\n");
        printf("1 - Criar arquivo com dados numericos\n");
        printf("2 - Escolha a Ordenação\n");
        printf("3 - Emitir arquivo ordenado\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        // Usa switch para tratar a escolha
        switch (opcao) {
            
        case 1:
        if (etapa == 1) {
            printf("\nVoce escolheu: CRIAR ARQUIVO\n");
            FILE *arquivo = fopen("dados.txt", "w");
            if (arquivo == NULL) {
                printf("Erro ao criar o arquivo!\n");
                return 1;
            }
                printf("Quantos numeros deseja informar? ");
                scanf("%d", &quantidade);
                fprintf(arquivo, "Sequencia numerica:\n");
            for (int i = 0; i < quantidade; i++) {
                printf("Digite o %d numero: ", i + 1);
                scanf("%d", &numero);
                fprintf(arquivo, "%d ", numero);
            }
                fprintf(arquivo, "\n");
                fclose(arquivo);
                printf("\nArquivo criado e dados gravados com sucesso!\n");
            return 0;
            etapa = 2;
        } else {
            printf("Voce ja passou dessa etapa!\n");
        }
        break;
        
        case 2:
        if (etapa == 2) {
            printf("\nVoce escolheu: ORDENAÇÃO\n");
            printf("===== MENU: ORDENAÇÃO =====\n");
            printf("1 - Bubble Sort\n");
            printf("2 - Insertion Sort\n");
            printf("3 - Selection Sort\n");
            printf("4 - Merge Sort\n");
            printf("5 - Quick Sort\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &ordenacao);
            switch(ordenacao) {
                case 1:
                break;
                
                case 2:
                break;
                
                case 3:
                break;
                
                case 4:
                break;
                
                case 5:
                break;
            } etapa = 3;}
        else {
            printf("Execute a primeira opcao antes!\n");
            }
        break;
            
        case 3:
        if (etapa == 3) {
            printf("\nVoce escolheu: EMITIR ARQUIVO ORDENADO\n");
            etapa = 4;}
        else {
            printf("Execute as opcoes anteriores primeiro!\n");}
        break;
        
        case 4:
            if (etapa == 4) {
                    printf("Saindo do programa...\n");
            } else {
                    printf("Complete as tres etapas antes de sair!\n");
                opcao = 0;
            }
            break;

            default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
    return 0
}