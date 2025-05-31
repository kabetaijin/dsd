# Batalha Naval - Posicionando Navios em C (Nível Novato)

## Descrição

Este programa em C é uma introdução ao desenvolvimento do jogo Batalha Naval. Nesta fase inicial (nível novato), o foco está em representar um tabuleiro simplificado (10x10), inicializá-lo e posicionar dois navios de tamanho fixo (3 posições cada). Um navio é posicionado horizontalmente e o outro verticalmente. O programa também inclui validações para garantir que os navios estejam dentro dos limites do tabuleiro e não se sobreponham. A saída exibe o tabuleiro no console, mostrando a água (0) e as partes dos navios (3).

Este projeto é um exercício para praticar o uso de arrays bidimensionais (matrizes), funções, constantes e lógica de validação básica em C.

## Funcionalidades Implementadas

* **Representação do Tabuleiro:** Utiliza uma matriz 10x10 de inteiros.
* **Inicialização do Tabuleiro:** Todas as posições são inicializadas com `0` (representando água).
* **Navios:**
    * Dois navios, cada um com tamanho fixo de 3 posições.
    * Um navio posicionado horizontalmente e outro verticalmente.
    * As posições dos navios no tabuleiro são marcadas com o valor `3`.
    * Os "modelos" dos navios são conceitualmente representados por vetores unidimensionais, conforme o requisito do desafio.
* **Posicionamento:**
    * As coordenadas iniciais dos navios são definidas diretamente no código.
    * **Validação de Limites:** Verifica se o navio completo cabe dentro do tabuleiro.
    * **Validação de Sobreposição:** Garante que os navios não ocupem as mesmas posições.
* **Exibição do Tabuleiro:** O tabuleiro é impresso no console de forma clara, mostrando os índices das linhas e colunas.

## Como Compilar e Executar

### Pré-requisitos

* Um compilador C instalado (por exemplo, GCC, Clang, MinGW para Windows, ou o compilador do Visual Studio).

### Passos para Compilação

1.  **Salvar o código:** Salve o código-fonte em um arquivo com a extensão `.c` (por exemplo, `batalha_naval_novato.c`).
2.  **Abrir o terminal/prompt de comando:** Navegue até o diretório onde você salvou o arquivo.
3.  **Compilar o código:**
    * Se estiver usando **GCC**:
        ```bash
        gcc batalha_naval_novato.c -o batalha_naval_novato
        ```
    * Se estiver usando o compilador do **Visual Studio (MSVC)**, abra o "Developer Command Prompt for VS" e digite:
        ```bash
        cl batalha_naval_novato.c
        ```

### Passos para Execução

1.  Após a compilação bem-sucedida, um arquivo executável será gerado. Para executá-lo:
    * No **Linux ou macOS**:
        ```bash
        ./batalha_naval_novato
        ```
    * No **Windows**:
        ```bash
        batalha_naval_novato.exe
        ```
        (ou apenas `batalha_naval_novato`)

## Estrutura do Código

O código está organizado nas seguintes partes principais:

* **Constantes Globais:**
    * `TAMANHO_TABULEIRO`: Define as dimensões do tabuleiro.
    * `TAMANHO_NAVIO_FIXO`: Define o tamanho dos navios.
    * `AGUA`: Valor numérico para representar água.
    * `NAVIO`: Valor numérico para representar uma parte de um navio.
* **Função `inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO])`:** Preenche o tabuleiro com o valor `AGUA`.
* **Função `exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO])`:** Mostra o estado atual do tabuleiro no console.
* **Função `posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao, const int navio_modelo[])`:** Tenta colocar um navio no tabuleiro, realizando validações de limites e sobreposição.
* **Função `main()`:**
    * Ponto de entrada do programa.
    * Declara e inicializa o tabuleiro e os modelos de navio (vetores unidimensionais).
    * Coordena as chamadas para inicializar o tabuleiro, posicionar os dois navios pré-definidos e exibir o tabuleiro em diferentes etapas.
    * Inclui exemplos de tentativas de posicionamento inválidas para testar as lógicas de validação.

## Objetivos de Aprendizagem

Este projeto serve como um exercício prático para:
* Trabalhar com arrays bidimensionais (matrizes) em C.
* Implementar e utilizar funções para modularizar o código.
* Aplicar lógica de validação de dados (limites, sobreposição).
* Usar constantes para melhorar a legibilidade e manutenibilidade do código.
* Entender o processo de compilação e execução de um programa C.

## Tecnologias Utilizadas

* Linguagem C# dsd
