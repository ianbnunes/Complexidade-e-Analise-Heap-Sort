#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void heapify(int *arr, int n, int i) {
    int largest = i;         
    int left = 2 * i + 1;    
    int right = 2 * i + 2;   

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

double mean(const double *values, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    return sum / (double)n;
}

double stddev_sample(const double *values, int n) {
    if (n < 2) {
        return 0.0;
    }

    double m = mean(values, n);
    double sum_sq = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = values[i] - m;
        sum_sq += diff * diff;
    }
    return sqrt(sum_sq / (double)(n - 1));
}


double run_single_sort(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Erro ao alocar memória para n = %d\n", n);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        arr[i] = rand();  
    }

    clock_t start = clock();
    heap_sort(arr, n);
    clock_t end = clock();

    free(arr);

    double elapsed = (double)(end - start) / (double)CLOCKS_PER_SEC;
    return elapsed;
}

int main(void) {
    srand((unsigned int)time(NULL));

    const int sizes[] = {100, 500, 1000, 5000, 10000, 50000};
    const int NUM_SIZES = sizeof(sizes) / sizeof(sizes[0]);

    const int NUM_RUNS = 20;

    printf("Experimento Heap Sort\n");
    printf("Numero de execucoes por tamanho: %d\n\n", NUM_RUNS);
    printf("n\tmedia (s)\tdesvio-padrao (s)\n");
    printf("-------------------------------------------------\n");

    for (int s = 0; s < NUM_SIZES; s++) {
        int n = sizes[s];
        double *times = (double *)malloc(NUM_RUNS * sizeof(double));
        if (times == NULL) {
            fprintf(stderr, "Erro ao alocar memoria para tempos (n = %d)\n", n);
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < NUM_RUNS; i++) {
            times[i] = run_single_sort(n);
        }

        double m = mean(times, NUM_RUNS);
        double sd = stddev_sample(times, NUM_RUNS);

        printf("%d\t%.6f\t%.6f\n", n, m, sd);

        free(times);
    }

    return 0;
}
