
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int v[], int n)
{
    int i, j, aux;
    // Percorre o vetor vÃ¡rias vezes
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            // Se o elemento atual for maior que o prÃ³ximo, troca
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int v[], int n)
{
    int i, j, chave;
    // ComeÃ§a a partir do segundo elemento
    for (i = 1; i < n; i++)
    {
        chave = v[i]; // Armazena o valor atual
        j = i - 1;
        // Move os elementos maiores para a direita
        while (j >= 0 && v[j] > chave)
        {
            v[j + 1] = v[j];
            j--;
        }
        // Insere a chave na posiÃ§Ã£o correta
        v[j + 1] = chave;
    }
}

void selectionSort(int v[], int n)
{
    int i, j, min, aux;
    // Percorre o vetor
    for (i = 0; i < n - 1; i++)
    {
        min = i; // Assume que o menor Ã© o atual
        // Procura o menor valor Ã  frente
        for (j = i + 1; j < n; j++)
        {
            if (v[j] < v[min])
                min = j;
        }
        // Troca se encontrou menor
        aux = v[i];
        v[i] = v[min];
        v[min] = aux;
    }
}

void merge(int v[], int inicio, int meio, int fim)
{
    int i = inicio, j = meio + 1, k = 0;
    int aux[fim - inicio + 1];
    // Intercala os dois subvetores
    while (i <= meio && j <= fim)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    // Copia o que sobrou de cada lado
    while (i <= meio)
        aux[k++] = v[i++];
    while (j <= fim)
        aux[k++] = v[j++];
    // Retorna os valores ao vetor original
    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];
}
void mergeSort(int v[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);  // Parte esquerda
        mergeSort(v, meio + 1, fim); // Parte direita
        merge(v, inicio, meio, fim); // Intercala
    }
}

void quickSort(int v[], int inicio, int fim)
{
    int i = inicio, j = fim, pivo = v[(inicio + fim) / 2], aux;
    // Particionamento
    while (i <= j)
    {
        while (v[i] < pivo)
            i++;
        while (v[j] > pivo)
            j--;
        if (i <= j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }
    // RecursÃ£o nas partes esquerda e direita
    if (inicio < j)
        quickSort(v, inicio, j);
    if (i < fim)
        quickSort(v, i, fim);
}

int main(void)
{
    int quantidade;
    int numero;

    printf("ETAPA 1 - CRIACAO DA SEQUENCIA NUMERICA\n");
    printf("Quantos numeros deseja informar? ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0)
    {
        printf("Quantidade invalida. Informe um inteiro maior que zero.\n");
        return 1;
    }

    /* Cria o arquivo e guarda os numeros digitados pelo usuario. */
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel criar dados.txt.\n");
        return 1;
    }

    int numeros[quantidade];
    for (int i = 0; i < quantidade; i++)
    {
        printf("Digite o numero %d: ", i + 1);
        if (scanf("%d", &numero) != 1)
        {
            printf("Entrada invalida.\n");
            fclose(arquivo);
            return 1;
        }
        numeros[i] = numero;
        fprintf(arquivo, "%d\n", numero);
    }
    fclose(arquivo);
    printf("Dados salvos em dados.txt.\n");

    /* Mostra os numeros que serao usados nas ordenacoes. */
    printf("\nETAPA 2 - NUMEROS INFORMADOS\n");
    for (int i = 0; i < quantidade; i++)
        printf("Numero %d: %d\n", i + 1, numeros[i]);

    int tipo_ordenacao;
    do
    {
        /* Copia os valores originais para comparar os algoritmos em cada escolha. */
        int numeros_ordenados[quantidade];
        for (int i = 0; i < quantidade; i++)
            numeros_ordenados[i] = numeros[i];

        const char *nome_ordenacao = NULL;

        printf("\nETAPA 3 - ESCOLHA DE ORDENACAO\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Quick Sort\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &tipo_ordenacao) != 1)
        {
            printf("Entrada invalida. Tente novamente.\n");
            int caractere;
            while ((caractere = getchar()) != '\n' && caractere != EOF)
                ;
            tipo_ordenacao = 0;
            continue;
        }

        /* O case escolhido ordena a copia e define o nome para o arquivo. */
        switch (tipo_ordenacao)
        {
        case 1:
            nome_ordenacao = "Bubble Sort";
            bubbleSort(numeros_ordenados, quantidade);
            break;
        case 2:
            nome_ordenacao = "Insertion Sort";
            insertionSort(numeros_ordenados, quantidade);
            break;
        case 3:
            nome_ordenacao = "Selection Sort";
            selectionSort(numeros_ordenados, quantidade);
            break;
        case 4:
            nome_ordenacao = "Merge Sort";
            mergeSort(numeros_ordenados, 0, quantidade - 1);
            break;
        case 5:
            nome_ordenacao = "Quick Sort";
            quickSort(numeros_ordenados, 0, quantidade - 1);
            break;
        case 6:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opcao invalida. Escolha de 1 a 6.\n");
            break;
        }

        /* Só grava quando um algoritmo válido foi escolhido. O arquivo é atualizado a cada ordenação. */
        if (nome_ordenacao != NULL)
        {
            FILE *arquivo_ordenado = fopen("dados-ordenados.txt", "w");
            if (arquivo_ordenado == NULL)
            {
                printf("Nao foi possivel criar dados-ordenados.txt.\n");
            }
            else
            {
                fprintf(arquivo_ordenado, "Ordenacao selecionada: %s\n", nome_ordenacao);
                fprintf(arquivo_ordenado, "Numeros ordenados em ordem crescente:\n");
                for (int i = 0; i < quantidade; i++)
                    fprintf(arquivo_ordenado, "%d%c", numeros_ordenados[i], i + 1 == quantidade ? '\n' : ' ');
                fclose(arquivo_ordenado);

                printf("\nAlgoritmo selecionado: %s\n", nome_ordenacao);
                for (int i = 0; i < quantidade; i++)
                    printf("Numero %d: %d\n", i + 1, numeros_ordenados[i]);
                printf("Resultado salvo em dados-ordenados.txt.\n");
            }
        }
    } while (tipo_ordenacao != 6);

    printf("Fim do programa.\n");
    return 0;
}
