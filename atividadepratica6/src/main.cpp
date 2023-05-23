#include <iostream>
#include <chrono> // Para medir o tempo de execução
#include <iomanip> // Para formatar a saída
#include <random> // Para gerar vetores aleatórios
#include <algorithm> // Para comparar os resultados

// Implementação do heapsort

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Implementação do shellsort

void shellsort(int arr[], int n) {
    int h = 1;
    while (h < n / 3)
        h = 3 * h + 1;

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            int key = arr[i];
            int j = i;
            while (j >= h && arr[j - h] > key) {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = key;
        }
        h /= 3;
    }
}

// Função para gerar vetor aleatório

void gerarVetorAleatorio(int vetor[], int n) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 1000);

    for (int i = 0; i < n; i++) {
        vetor[i] = distribution(generator);
    }
}

int main() {
    const int tamanhos[] = {10, 100, 500, 10000, 100000};
    const int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    const int valoresH[] = {2, 4, 8, 16, 32};
    const int numValoresH = sizeof(valoresH) / sizeof(valoresH[0]);

    std::cout << "Tamanho do vetor | Valor de h | Tempo Heapsort | Tempo Shellsort" << std::endl;

    for (int i = 0; i < numTamanhos; i++) {
        int tamanho = tamanhos[i];
        int* vetor = new int[tamanho];

        for (int j = 0; j < numValoresH; j++) {
            int h = valoresH[j];

            // Gerar vetor aleatório
            gerarVetorAleatorio(vetor, tamanho);

            // Copiar vetor para uso no shellsort
            int* vetorShell = new int[tamanho];
            std::copy(vetor, vetor + tamanho, vetorShell);

            // Medir tempo de execução do heapsort
            auto startTimeHeap = std::chrono::steady_clock::now();
            heapsort(vetor, tamanho);
            auto endTimeHeap = std::chrono::steady_clock::now();
            auto elapsedHeap = std::chrono::duration_cast<std::chrono::microseconds>(endTimeHeap - startTimeHeap).count();

            // Medir tempo de execução do shellsort
            auto startTimeShell = std::chrono::steady_clock::now();
            shellsort(vetorShell, tamanho);
            auto endTimeShell = std::chrono::steady_clock::now();
            auto elapsedShell = std::chrono::duration_cast<std::chrono::microseconds>(endTimeShell - startTimeShell).count();

            std::cout << std::setw(16) << tamanho << " | " << std::setw(11) << h << " | " << std::setw(14) << elapsedHeap << " us | " << std::setw(16) << elapsedShell << " us" << std::endl;

            // Verificar se os resultados dos algoritmos estão corretos
            bool resultadoCorreto = std::is_sorted(vetor, vetor + tamanho) && std::is_sorted(vetorShell, vetorShell + tamanho);
            std::cout << "Resultados corretos? " << (resultadoCorreto ? "Sim" : "Não") << std::endl;

            delete[] vetorShell;
        }

        delete[] vetor;
    }

    return 0;
}