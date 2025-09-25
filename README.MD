````markdown
# Benchmark Simples em C++

Olá! Meu nome é **Leonardo Gonçalves** e este é um projeto que desenvolvi para a disciplina de Arquitetura e Organização de Computadores.  
A proposta era criar um programa de benchmarking simples para avaliar e comparar o desempenho de diferentes máquinas.

## Sobre o Projeto

Este código é uma ferramenta de linha de comando escrita em C++ que realiza uma série de testes intensivos para medir a performance do processador e da memória RAM.  
O objetivo é fornecer uma métrica simples e rápida para comparar a capacidade de processamento bruto entre diferentes sistemas.

## Como o Código Funciona

O programa executa três testes distintos em sequência. A "carga de trabalho" de cada teste é definida por um único parâmetro numérico que você informa ao executar o programa. Quanto maior o número, mais intenso será o benchmark.

Os testes são:

- **Benchmark de Matrizes:** Realiza a multiplicação de duas matrizes quadradas (`N x N`, onde `N` é a carga de trabalho). Este teste é muito intensivo em CPU e em acesso à memória cache, sendo um ótimo indicador da performance de computação geral.

- **Benchmark de Matemática:** Executa milhões de operações matemáticas de ponto flutuante, como seno, cosseno e logaritmo. O objetivo deste teste é estressar a Unidade de Ponto Flutuante (FPU) do processador.

- **Benchmark de Memória:** Aloca um vetor muito grande na RAM e depois preenche cada uma de suas posições. Este teste mede a velocidade de alocação e escrita sequencial na memória principal do sistema.

Ao final, o programa exibe o tempo que cada teste levou para ser concluído (em milissegundos) e o tempo total da execução.

## Como Compilar e Executar

Para usar o programa, você primeiro precisa compilá-lo a partir do código-fonte `benchmark.cpp`.  
O processo varia um pouco entre Linux e Windows.

### No Linux (usando G++)

1. Abra o terminal na pasta onde o arquivo `benchmark.cpp` está localizado.
2. Compile o código com o seguinte comando:
   ```bash
   g++ -o benchmark benchmark.cpp -std=c++17 -O2
````

3. Execute o benchmark, passando um número como parâmetro de carga. Por exemplo:

   ```bash
   ./benchmark 500
   ```

### No Windows (usando o compilador da Microsoft)

1. Você precisa ter o Visual Studio ou as **Build Tools for Visual Studio** instaladas.
2. Abra o **Developer Command Prompt for VS** (Prompt de Comando do Desenvolvedor para VS).
3. Navegue até a pasta do projeto usando o comando `cd`.
4. Compile com o seguinte comando:

   ```batch
   cl /EHsc /O2 /std:c++17 /Fe:benchmark.exe benchmark.cpp
   ```
5. Execute o programa, passando o parâmetro de carga:

   ```batch
   benchmark.exe 500
   ```

## Exemplo de Uso e Saída

Ao executar `benchmark.exe 400`, por exemplo, você verá uma saída parecida com esta:

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

### Saída Real de Execução

Aqui está um exemplo real da execução no Windows, com fator de carga 100:

![Exemplo de execução real](./Captura%20de%20tela%202025-09-25%20144107.png)

---

**Autor:** Leonardo Gonçalves

```