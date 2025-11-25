# Análise de Complexidade e Desempenho: Heap Sort

![Language C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Language Python](https://img.shields.io/badge/Language-Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Institution](https://img.shields.io/badge/Institution-CESAR_School-orange?style=for-the-badge)

Este repositório contém a implementação, análise teórica e experimental do algoritmo de ordenação **Heap Sort**, desenvolvido como parte da disciplina de **Teoria da Computação** da CESAR School.

## 👥 Equipe 
* **Emanuel Eduardo**
* **Ian Nunes**
* **Mariana Correia**
* **Pedro Henrique Silva**

**Professor:** Daniel Bezerra  
**Semestre:** 2025.2

---

## 🎯 Objetivo do Projeto
O objetivo deste trabalho é analisar a complexidade de tempo do algoritmo **Heap Sort** sob a ótica da Teoria da Complexidade, comparando sua eficiência teórica com resultados práticos obtidos em duas linguagens de paradigmas diferentes: **C (compilada)** e **Python (interpretada)**.

O projeto atende aos seguintes requisitos:
1. Implementação do algoritmo.
2. Análise assintótica (Big-O, Omega, Theta).
3. Simulação com dados randômicos e medição de tempo.
4. Comparação de desempenho entre linguagens.
5. Classificação na hierarquia das classes de complexidade (P vs NP).

---

## 📚 Sobre o Heap Sort
O Heap Sort é um algoritmo de ordenação por comparação que utiliza uma estrutura de dados **Max-Heap** (árvore binária completa onde o pai é sempre maior que os filhos).

**Funcionamento Básico:**
1. **Build Max Heap:** Transforma o array desordenado em um Max-Heap.
2. **Ordenação:** Troca a raiz (maior elemento) com o último elemento do heap, reduz o tamanho do heap e aplica o `max_heapify` para restaurar a propriedade da árvore. Repete-se até o array estar ordenado.

### Complexidade Teórica
O algoritmo possui um comportamento muito estável, apresentando a mesma ordem de complexidade para todos os casos:

| Caso | Notação | Complexidade |
|:---:|:---:|:---:|
| **Pior Caso** | Big-O ($O$) | $O(n \log n)$ |
| **Melhor Caso** | Big-$\Omega$ ($\Omega$) | $\Omega(n \log n)$ |
| **Caso Médio** | Big-$\Theta$ ($\Theta$) | $\Theta(n \log n)$ |

> **Nota:** O Heap Sort é um algoritmo *in-place* (memória $O(1)$ auxiliar), mas **não é estável**.

---

## 🧪 Metodologia Experimental
Para validar a teoria, realizamos experimentos controlados com as seguintes configurações:

* **Entradas (n):** 100, 500, 1.000, 5.000, 10.000, 50.000 elementos.
* **Dados:** Vetores de inteiros gerados aleatoriamente (distribuição uniforme).
* **Repetições:** Cada tamanho de entrada foi executado **20 vezes** para garantir consistência estatística (média e desvio-padrão).
* **Ambiente:** Comparação direta entre **C** (foco em desempenho e baixo nível) e **Python** (foco em produtividade e alto nível).


---

## Como executar as implementações do Heap Sort (C e Python)

Este repositório possui duas implementações do Heap Sort com simulação de desempenho (20 execuções por tamanho de entrada):

* `heapsort.py` — implementação em Python
* `heapsort.c` — implementação em C
* `Heap_Sort_Analise.ipynb` — notebook para gerar gráficos e comparar C × Python
* `results_python.txt` e `results_c.txt` — saídas já registradas

---

### Requisitos

**Para Python**

* Python 3.8+
* Não é necessária instalação de bibliotecas externas.

**Para C**

* GCC (ou outro compilador C compatível)
* Biblioteca matemática padrão (`-lm`)
---

## Executando o Heap Sort em Python

1. Abra um terminal na pasta do projeto.
2. Execute:

```bash
python3 heapsort.py
```

O programa:

* gera vetores aleatórios para diferentes valores de `n`;
* executa o Heap Sort 20 vezes por tamanho;
* imprime uma tabela com **tempo médio** e **desvio-padrão**.

A saída segue o formato:

```text
n       media (s)      desvio-padrão (s)
100     ...
500     ...
...
```

> Observação: você roda o script **uma única vez**; as 20 repetições são automáticas.

---

## Executando o Heap Sort em C

1. Compile:

```bash
gcc -O2 heapsort.c -o heapsort -lm
```

* `-O2`: otimização para testes de desempenho mais realistas
* `-lm`: necessário por causa do `sqrt()` no cálculo do desvio-padrão

2. Execute:

```bash
./heapsort
```

A saída também imprime a tabela:

```text
n       media (s)      desvio-padrão (s)
100     ...
500     ...
...
```

---

## Gerando gráficos e comparações (C × Python)

1. Abra o notebook:

`Heap_Sort_Analise.ipynb`

2. Execute as células em ordem no Google Colab/Jupyter.

O notebook gera:

* gráfico **Tempo médio × tamanho da entrada** (Python vs C);
* comparação com curva teórica **O(n log n)**;
* gráfico de **speedup** (quanto Python é mais lento que C);
* tabelas consolidadas para o relatório.

---

## Resultados prontos

Se você quiser apenas consultar os resultados já coletados, eles estão em:

* `results_python.txt`
* `results_c.txt`

Esses arquivos contêm as tabelas finais usadas nos gráficos.
