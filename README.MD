# 🚀 Benchmark Simples em C++

Um projeto desenvolvido por **Leonardo Gonçalves** para a disciplina de **Arquitetura e Organização de Computadores**.  
O objetivo é criar um programa de benchmarking simples em **C++**, capaz de avaliar e comparar o desempenho de diferentes máquinas.

---

## 📖 Sobre o Projeto

Este programa é uma ferramenta de **linha de comando** que executa uma série de testes intensivos no **processador** e na **memória RAM**.  
Ele fornece métricas rápidas e diretas para analisar a capacidade de processamento bruto entre sistemas distintos.

---

## ⚙️ Como Funciona

O benchmark executa **3 testes principais**, definidos por um parâmetro de carga informado pelo usuário (quanto maior o número, mais intenso será o teste):

1. **🟦 Matrizes**  
   Multiplicação de matrizes quadradas `N x N`.  
   → Mede uso intensivo de **CPU** e memória **cache**.

2. **🧮 Matemática**  
   Milhões de operações de ponto flutuante (seno, cosseno, logaritmo).  
   → Avalia a **Unidade de Ponto Flutuante (FPU)**.

3. **💾 Memória**  
   Alocação e preenchimento de grandes vetores na RAM.  
   → Mede velocidade de **alocação** e **escrita sequencial**.

🔹 Ao final, o programa mostra o tempo (em **ms**) de cada teste e o **tempo total de execução**.

---

## 🛠️ Como Compilar e Executar

### Linux (G++)
```bash
# Abra o terminal na pasta do projeto
g++ -o benchmark benchmark.cpp -std=c++17 -O2

# Execute com um parâmetro de carga (ex: 500)
./benchmark 500
```

### Windows (MSVC)
```batch
:: No Developer Command Prompt
cl /EHsc /O2 /std:c++17 /Fe:benchmark.exe benchmark.cpp

:: Execute com um parâmetro de carga (ex: 500)
benchmark.exe 500
```

---

## 📊 Exemplo de Saída

Execução com carga **400**:

```
Iniciando benchmark com fator de carga: 400
---------------------------------------------
Executando Benchmark de Matrizes (tamanho 400x400)... Concluído.
Executando Benchmark de Matemática (40000000 operações)... Concluído.
Executando Benchmark de Memória (40000000 elementos)... Concluído.
---------------------------------------------
Resultados do Benchmark:
 > Teste de Matrizes: 2130.45 ms
 > Teste de Matemática: 861.12 ms
 > Teste de Memória: 202.97 ms
---------------------------------------------
Tempo Total de Execução: 3.20 segundos
```

---

## 📷 Exemplo Real

Execução no Windows com fator de carga **100**:

![Exemplo de execução real](./Captura%20de%20tela%202025-09-25%20144107.png)

---

## 👤 Autor

**Leonardo Gonçalves**  
Projeto acadêmico — UFPE  
