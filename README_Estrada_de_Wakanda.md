# 🛣️ Estrada de Wakanda — Trabalho Prático de Estruturas de Dados (UCB)

## 📘 Descrição do Problema

O rei **T’Challa**, governante de **Wakanda**, decidiu construir uma estrada que atravessa o país de **oeste a leste**.  
Essa estrada passa pelo **centro de algumas cidades**, e cada cidade será **responsável pela manutenção** do trecho da estrada **mais próximo** dela.

O objetivo do trabalho é implementar um **programa em linguagem C** que:

1. Lê os dados da estrada e das cidades de um **arquivo de texto**;  
2. Calcula o **tamanho da menor vizinhança de estrada**;  
3. Retorna o **nome da cidade com a menor vizinhança**.

---

## 🧩 Estrutura do Projeto

| Arquivo | Descrição |
|----------|------------|
| **cidades.h** | Cabeçalho contendo as definições das estruturas e protótipos das funções. |
| **cidades.c** | Implementa as funções principais (`getEstrada`, `calcularMenorVizinhanca` e `cidadeMenorVizinhanca`). |
| **main.c** | Arquivo principal de teste que chama as funções e exibe o resultado no terminal. |
| **teste01.txt** | Arquivo de entrada com os dados da estrada e das cidades. |

---

## ⚙️ Estruturas Utilizadas

```c
typedef struct Cidade {
    char Nome[256];         // Nome da cidade
    int Posicao;            // Distância (em km) da fronteira oeste
    struct Cidade *Proximo; // Ponteiro para a próxima cidade
} Cidade;

typedef struct {
    int N;        // Número de cidades
    int T;        // Comprimento total da estrada
    Cidade *Inicio; // Ponteiro para a primeira cidade da lista
} Estrada;
```

Essas estruturas formam uma **lista encadeada** que representa as cidades posicionadas ao longo da estrada.

---

## 🧠 Lógica do Programa

### 1️⃣ Leitura dos dados (`getEstrada`)
- Abre o arquivo `teste01.txt`;
- Lê:
  - `T` → comprimento total da estrada;
  - `N` → número de cidades;
  - `Xi` → posição de cada cidade;
  - `Si` → nome da cidade;
- Valida as restrições:
  - `3 ≤ T ≤ 10^6`
  - `2 ≤ N ≤ 10^4`
  - `0 < Xi < T`
  - `Xi ≠ Xj` (sem posições repetidas)
- Cria uma **lista encadeada** com as cidades ordenadas pela posição.

---

### 2️⃣ Cálculo da menor vizinhança (`calcularMenorVizinhanca`)

A **vizinhança** de uma cidade é o trecho da estrada **mais próximo** dela do que de qualquer outra cidade.  
O cálculo depende da posição da cidade:

- **Primeira cidade:**  
  \[ viz = \frac{(X_2 - X_1)}{2} + X_1 \]
- **Última cidade:**  
  \[ viz = (T - X_n) + \frac{(X_n - X_{n-1})}{2} \]
- **Intermediárias:**  
  \[ viz = \frac{(X_{i+1} - X_{i-1})}{2} \]

O programa percorre todas as cidades e retorna o **menor valor** encontrado.

---

### 3️⃣ Cidade com menor vizinhança (`cidadeMenorVizinhanca`)
- Repete o cálculo da função anterior;
- Armazena o **índice da cidade** com a menor vizinhança;
- Retorna uma **string** com o nome dessa cidade.

---

## 📄 Exemplo de Arquivo de Entrada (`teste01.txt`)

```
10
2
8 Birnin_Zana
5 Birnin_SYan
```

### 🧮 Interpretação:
- Comprimento da estrada: **10 km**
- Cidades:
  - Birnin Zana → posição 8 km
  - Birnin S’Yan → posição 5 km

### 📊 Resultado esperado:
- Vizinhança de Birnin Zana: **3,5 km**
- Vizinhança de Birnin S’Yan: **6,5 km**
- Cidade com menor vizinhança: **Birnin Zana**

---

## 🖥️ Exemplo de Execução

### Compilação

No terminal (PowerShell, CMD ou Bash), dentro da pasta do projeto:

```bash
gcc main.c cidades.c -o cidades.exe
```

### Execução

```bash
./cidades
```

### Saída esperada

```
=== RESULTADOS DA ESTRADA DE WAKANDA ===
Comprimento total da estrada: 10
Número de cidades: 2
Menor vizinhança: 3.50 km
Cidade com menor vizinhança: Birnin_Zana
=========================================
```

---

## 📦 Estrutura Final do Projeto

```
TP02_Estrada_de_Wakanda/
│
├── cidades.c
├── cidades.h
├── main.c
├── teste01.txt
└── README.md
```

---

## 🧹 Liberação de Memória

- Cada cidade criada é liberada com `free()` no final da execução;
- A estrutura `Estrada` também é liberada;
- A string retornada por `cidadeMenorVizinhanca` deve ser liberada com `free()` no `main`.

---

## 🧠 Requisitos de Execução

- Compilador **GCC** (ou Dev-C++, Code::Blocks, VSCode com extensão de C);
- Sistema operacional: **Windows**, **Linux** ou **MacOS**;
- O arquivo `teste01.txt` deve estar **na mesma pasta** do executável.

---

## ✅ Dicas

- Mantenha o nome do arquivo de entrada exatamente igual: `teste01.txt`;
- Evite acentos e apóstrofos nos nomes das cidades (use `_`);
- Sempre recompile após qualquer modificação no código.

---

## 👨‍💻 Autor

- **Universidade Católica de Brasília – UCB**  
- **Disciplina:** Estruturas de Dados  
- **Professor:** Marcelo Eustáquio  
- **Aluno:** *[Seu Nome Aqui]*  
- **Ano:** 2025  
