
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int v[], int n)
{
    int i, j, aux;
    // Percorre o vetor várias vezes
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Se o elemento atual for maior que o próximo, troca
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

int main()
{
    int quantidade, numero;

    system("cls");
    printf("ETAPA 1 - CRIAÇÃO DE SEQUENCIA NUMÉRICA EM ORDEM ALEATÓRIA\n");
    printf("Qual a quantidade de numeros que deseja informar?");
    scanf("%d", &quantidade);

    FILE *arquivo = fopen("dados.txt", "w");

    for (int i = 0; i < quantidade; i++)
    {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &numero);
        fprintf(arquivo, "%d\n", numero);
    }

    fprintf(arquivo, "\n");
    fclose(arquivo);

    printf("\nArquivo criado e dados gravados com sucesso!\n");

    printf("ETAPA 2 - LENDO SEQUENCIA DO ARQUIVO\n");
    FILE *arquivo_leitura = fopen("dados.txt", "r");

    int numeros[quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        fscanf(arquivo_leitura, "%d", &numeros[i]);
        printf("Numero %d: %d\n", i + 1, numeros[i]);
    }

    fclose(arquivo_leitura);

    int tipo_ordenacao;
    do
    {
        // toda vez que eu entro num laço
        // para escolher outra forma de ordenação
        // os numeros serão os que o usuario escolheu.
        int numeros_ordenados[quantidade];
        for (int i = 0; i < quantidade; i++)
        {
            numeros_ordenados[i] = numeros[i];
        }

        printf("\nETAPA 3: ESCOLHA DE ORDENAÇÃO\n");
        printf("===== MENU: ORDENAÇÃO =====\n\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Sair\n\n");

        printf("Escolha uma opcao: ");
        if (scanf("%d", &tipo_ordenacao) != 1)
        {
            system("cls");
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (tipo_ordenacao)
        {
        case 1:
            printf("1 - Bubble Sort -----------------------------------\n");
            bubbleSort(numeros_ordenados, quantidade);
            break;
        case 2:
            printf("2 - Insertion Sort ----------------------------------\n");

            break;

        case 3:
            printf("3 - Selection Sort ----------------------------------\n");

            break;

        case 4:
            printf("4 - Merge Sort ------------------------------------\n");

            break;

        case 5:
            printf("5 - Quick Sort -------------------------------------\n");

            break;
        case 6:
            printf("Saindo do programa. --------------------------------\n");

            break;

        default: // qualquer outro valor que não seja 1, 2, 3, 4, 5 ou 6 aparecerá a mensagem de opção inválida.
            printf("Opcao invalida. Escolha de 1 a 6.\n");
            break;
        }

        for (int i = 0; i < quantidade; i++)
        {
            printf("Numero %d: %d\n", i + 1, numeros_ordenados[i]);
        }

    } while (tipo_ordenacao != 6);
    printf("fim do código.\n");
}
