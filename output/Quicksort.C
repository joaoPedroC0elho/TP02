
#include <stdio.h>
#include <stdlib.h>
#include <cstring>


int comparacoes = 0;
int trocasFeitas = 0;


void swap(const char **a, const char **b) {
   const char *temp = *a;
    *a = *b;
    *b = temp;
    trocasFeitas++;
}



int Particao(const char* arr[20], int low, int high) {
   const char* Pivot = arr[high];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        comparacoes++;
        if(strcmp(arr[j], Pivot) < 0){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i + 1);
}

void Quicksort(char const* arr[], int low, int high) {
    if(low < high) {
        int pi = Particao(arr, low, high);
        Quicksort(arr, low, pi - 1);
        Quicksort(arr, pi + 1, high);
    }
}

int main() {
  char const *arr[] = {"maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"};
    int tamanho = sizeof(arr) / sizeof(arr[0]);

 printf("Lista de nomes antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", arr[i]);
    }

    Quicksort(arr, 0, tamanho - 1);

    printf("\nLista de nomes ordenada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", arr[i]);
    }

    printf("\nNumero de comparacoes realizadas: %d\n", comparacoes);
    printf("Numero de trocas realizadas: %d\n", trocasFeitas);

  
    char const* mediana = arr[tamanho / 2];
    printf("\nMediana: %s\n", mediana);

    
    FILE* saidaArquivo = fopen("frutasOrdenadas.txt", "w");
    if (saidaArquivo == NULL) {
        fprintf(stderr, "ERRO AO ABRIR O ARQUIVO!\n");
        return 1;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(saidaArquivo, "%s\n", arr[i]);
    }

    fclose(saidaArquivo);

    return 0;
}