import random
import time
import statistics


def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  
        heapify(arr, n, largest)  
def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)


def run_experiment(sizes, runs_per_size=20):
    resultados = []  

    for n in sizes:
        tempos = []
        for _ in range(runs_per_size):
            arr = [random.randint(0, 1_000_000) for _ in range(n)]

            start = time.perf_counter()
            heap_sort(arr)
            end = time.perf_counter()

            tempos.append(end - start)

        media = statistics.mean(tempos)
        desvio = statistics.stdev(tempos)  

        resultados.append({
            'tamanho': n,
            'tempos': tempos,
            'media': media,
            'desvio': desvio
        })

    return resultados


if __name__ == "__main__":
    tamanhos = [100, 500, 1000, 5000, 10000, 50000]
    resultados = run_experiment(tamanhos, runs_per_size=20)

    print("n\tmedia (s)\tdesvio-padrão (s)")
    for r in resultados:
        print(f"{r['tamanho']}\t{r['media']:.6f}\t{r['desvio']:.6f}")
