#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <string>

// --- Função de Benchmark 1: Multiplicação de Matrizes ---
// Estressa o processador com operações de ponto flutuante e o acesso à memória.
void benchmark_matrizes(int n) {
    // Cria matrizes n x n. Usamos 'double' para forçar cálculos de ponto flutuante.
    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<std::vector<double>> b(n, std::vector<double>(n));
    std::vector<std::vector<double>> resultado(n, std::vector<double>(n, 0.0));

    // Preenche as matrizes com valores de exemplo
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = static_cast<double>(i + 1) * 0.5;
            b[i][j] = static_cast<double>(j + 1) * 1.5;
        }
    }

    // O trabalho principal: multiplicação de matrizes O(n^3)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// --- Função de Benchmark 2: Operações Matemáticas ---
// Estressa a Unidade de Ponto Flutuante (FPU) da CPU com cálculos complexos.
void benchmark_matematica(long long num_operacoes) {
    double valor = 1.2345;
    for (long long i = 0; i < num_operacoes; ++i) {
        valor += std::sin(valor);
        valor += std::cos(valor);
        valor += std::log(std::abs(valor) + 1.0);
    }
    // Usamos o valor para garantir que o compilador não otimize e remova o loop
    if (valor == 123.0) std::cout << " "; 
}

// --- Função de Benchmark 3: Leitura e Escrita em Memória ---
// Mede a velocidade de alocação e escrita sequencial na RAM.
void benchmark_memoria(long long num_elementos) {
    // Aloca um grande vetor na memória
    std::vector<long long> memoria_vec(num_elementos);

    // Escreve em cada elemento do vetor
    for (long long i = 0; i < num_elementos; ++i) {
        memoria_vec[i] = i;
    }

    // Lê cada elemento do vetor para simular um acesso
    long long soma = 0;
    for (long long i = 0; i < num_elementos; ++i) {
        soma += memoria_vec[i];
    }
     // Usamos a soma para garantir que o compilador não otimize e remova o loop
    if (soma == 123) std::cout << " ";
}


int main(int argc, char* argv[]) {
    // --- Validação do Parâmetro de Entrada ---
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <fator_carga>" << std::endl;
        std::cerr << "Onde <fator_carga> eh um inteiro (ex: 100, 500, 1000)." << std::endl;
        return 1;
    }

    int fator_carga;
    try {
        fator_carga = std::stoi(argv[1]);
        if (fator_carga <= 0) {
            throw std::invalid_argument("O fator de carga deve ser positivo.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro: O parâmetro de entrada deve ser um número inteiro válido e positivo." << std::endl;
        return 1;
    }

    std::cout << "Iniciando benchmark com fator de carga: " << fator_carga << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // --- Execução e Medição dos Benchmarks ---
    
    // Mede o tempo total
    auto inicio_total = std::chrono::high_resolution_clock::now();

    // 1. Benchmark de Matrizes
    int tamanho_matriz = fator_carga;
    std::cout << "Executando Benchmark de Matrizes (tamanho " << tamanho_matriz << "x" << tamanho_matriz << ")..." << std::flush;
    auto inicio_matriz = std::chrono::high_resolution_clock::now();
    benchmark_matrizes(tamanho_matriz);
    auto fim_matriz = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_matriz = fim_matriz - inicio_matriz;
    std::cout << " Concluído." << std::endl;

    // 2. Benchmark de Matemática
    long long num_operacoes = fator_carga * 100000;
    std::cout << "Executando Benchmark de Matemática (" << num_operacoes << " operações)..." << std::flush;
    auto inicio_math = std::chrono::high_resolution_clock::now();
    benchmark_matematica(num_operacoes);
    auto fim_math = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_math = fim_math - inicio_math;
    std::cout << " Concluído." << std::endl;
    
    // 3. Benchmark de Memória
    long long num_elementos_mem = fator_carga * 100000;
    std::cout << "Executando Benchmark de Memória (" << num_elementos_mem << " elementos)..." << std::flush;
    auto inicio_mem = std::chrono::high_resolution_clock::now();
    benchmark_memoria(num_elementos_mem);
    auto fim_mem = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao_mem = fim_mem - inicio_mem;
    std::cout << " Concluído." << std::endl;

    auto fim_total = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracao_total = fim_total - inicio_total;

    // --- Exibição dos Resultados ---
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Resultados do Benchmark:" << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << " > Teste de Matrizes: " << duracao_matriz.count() << " ms" << std::endl;
    std::cout << " > Teste de Matemática: " << duracao_math.count() << " ms" << std::endl;
    std::cout << " > Teste de Memória: " << duracao_mem.count() << " ms" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Tempo Total de Execução: " << duracao_total.count() << " segundos" << std::endl;
    
    return 0;
}