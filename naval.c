#include <stdio.h> // Biblioteca para entrada/saída padrão (printf)

// --- Constantes do Jogo ---
#define TAMANHO_TABULEIRO 10   // Tamanho fixo do tabuleiro (10x10)
#define TAMANHO_NAVIO_FIXO 3   // Tamanho fixo dos navios (3 posições)
#define AGUA 0                 // Valor para representar água no tabuleiro
#define NAVIO 3                // Valor para representar um navio no tabuleiro

// --- Protótipos das Funções ---
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
void exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]);
int posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao, const int navio_modelo[]);

int main() {
    // Matriz para representar o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Requisito: "Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios."
    // Estes vetores representam o modelo de um navio. O valor NAVIO (3) será usado
    // para marcar as posições no tabuleiro.
    int navio_modelo1[TAMANHO_NAVIO_FIXO];
    int navio_modelo2[TAMANHO_NAVIO_FIXO];

    // Inicializa os modelos de navio (preenchendo com o valor NAVIO)
    for (int i = 0; i < TAMANHO_NAVIO_FIXO; i++) {
        navio_modelo1[i] = NAVIO; // Cada segmento do navio é representado por NAVIO (3)
        navio_modelo2[i] = NAVIO;
    }
    // Comentário: Os vetores navio_modelo1 e navio_modelo2 estão inicializados
    // e podem ser passados para a função de posicionamento como um "molde".

    // Inicializa o tabuleiro com água (valor 0)
    inicializarTabuleiro(tabuleiro);

    printf("--- BATALHA NAVAL - Posicionando Navios (Nivel Novato) ---\n");
    printf("Tabuleiro Inicial (so agua):\n");
    exibirTabuleiro(tabuleiro);

    // --- Posicionar Navio 1 (Horizontal) ---
    // Coordenadas e orientação definidas diretamente no código
    int linhaNavio1 = 2;         // Linha inicial do Navio 1
    int colunaNavio1 = 2;        // Coluna inicial do Navio 1
    char orientacaoNavio1 = 'H'; // 'H' para Horizontal
    int tamanhoNavio1 = TAMANHO_NAVIO_FIXO;

    printf("\nTentando posicionar Navio 1 (Horizontal, Tamanho %d) em L:%d, C:%d...\n",
           tamanhoNavio1, linhaNavio1, colunaNavio1);
    if (posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, tamanhoNavio1, orientacaoNavio1, navio_modelo1)) {
        printf("Navio 1 posicionado com sucesso!\n");
    } else {
        printf("FALHA ao posicionar Navio 1.\n");
    }
    exibirTabuleiro(tabuleiro);

    // --- Posicionar Navio 2 (Vertical) ---
    // Coordenadas e orientação definidas diretamente no código
    int linhaNavio2 = 4;         // Linha inicial do Navio 2
    int colunaNavio2 = 5;        // Coluna inicial do Navio 2
    char orientacaoNavio2 = 'V'; // 'V' para Vertical
    int tamanhoNavio2 = TAMANHO_NAVIO_FIXO;

    printf("\nTentando posicionar Navio 2 (Vertical, Tamanho %d) em L:%d, C:%d...\n",
           tamanhoNavio2, linhaNavio2, colunaNavio2);
    if (posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, tamanhoNavio2, orientacaoNavio2, navio_modelo2)) {
        printf("Navio 2 posicionado com sucesso!\n");
    } else {
        printf("FALHA ao posicionar Navio 2.\n");
    }
    exibirTabuleiro(tabuleiro);

    // --- Teste de Sobreposição (Deve Falhar) ---
    int linhaNavio3 = linhaNavio1;      // Mesma linha do Navio 1
    int colunaNavio3 = colunaNavio1 + 1; // Coluna que causaria sobreposição com Navio 1
    char orientacaoNavio3 = 'H';
    printf("\nTentando posicionar Navio 3 (Teste de Sobreposicao) em L:%d, C:%d...\n",
        linhaNavio3, colunaNavio3);
    if (posicionarNavio(tabuleiro, linhaNavio3, colunaNavio3, TAMANHO_NAVIO_FIXO, orientacaoNavio3, navio_modelo1)) {
        printf("Navio 3 posicionado (ERRO NA LOGICA DE SOBREPOSICAO)!\n");
    } else {
        printf("FALHA ao posicionar Navio 3 (Sobreposicao detectada, como esperado).\n");
    }
    exibirTabuleiro(tabuleiro);


    // --- Teste Fora dos Limites (Deve Falhar) ---
    int linhaNavio4 = 8;
    int colunaNavio4 = 8; // (8,8), (8,9), (8,10) -> (8,10) é fora para H
    char orientacaoNavio4 = 'H';
    printf("\nTentando posicionar Navio 4 (Teste Fora dos Limites) em L:%d, C:%d...\n",
        linhaNavio4, colunaNavio4);
    if (posicionarNavio(tabuleiro, linhaNavio4, colunaNavio4, TAMANHO_NAVIO_FIXO, orientacaoNavio4, navio_modelo1)) {
        printf("Navio 4 posicionado (ERRO NA LOGICA DE LIMITES)!\n");
    } else {
        printf("FALHA ao posicionar Navio 4 (Fora dos limites detectado, como esperado).\n");
    }
    exibirTabuleiro(tabuleiro);


    return 0; // Indica que o programa terminou com sucesso
}

/**
 * @brief Inicializa todas as posições do tabuleiro com o valor AGUA.
 *
 * @param tabuleiro A matriz 2D (array bidimensional) representando o tabuleiro.
 * O tamanho da segunda dimensão DEVE ser especificado.
 */
void inicializarTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    // Loop para percorrer cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop para percorrer cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Define a célula como AGUA (0)
        }
    }
}

/**
 * @brief Exibe o tabuleiro formatado no console.
 *
 * @param tabuleiro A matriz 2D representando o tabuleiro.
 */
void exibirTabuleiro(int tabuleiro[][TAMANHO_TABULEIRO]) {
    printf("\n  "); // Espaçamento para alinhar os índices das colunas
    // Imprime os índices das colunas (0 a TAMANHO_TABULEIRO-1)
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Loop para percorrer cada linha do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o índice da linha atual
        // Loop para percorrer cada coluna da linha atual
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o valor da célula (0 para água, 3 para navio)
        }
        printf("\n"); // Pula para a próxima linha no console após imprimir uma linha do tabuleiro
    }
    printf("\n"); // Linha em branco adicional para melhor formatação
}

/**
 * @brief Tenta posicionar um navio no tabuleiro.
 * Esta função verifica se o navio cabe nos limites do tabuleiro
 * e se não há sobreposição com outros navios já posicionados.
 *
 * @param tabuleiro A matriz 2D do jogo.
 * @param linha Linha da coordenada inicial para posicionar o navio (0-indexed).
 * @param coluna Coluna da coordenada inicial para posicionar o navio (0-indexed).
 * @param tamanho O número de células que o navio ocupará.
 * @param orientacao 'H' para horizontal, 'V' para vertical.
 * @param navio_modelo Array 1D representando os segmentos do navio (ex: {3,3,3}). Usado para obter o valor NAVIO.
 * @return 1 se o navio foi posicionado com sucesso, 0 caso contrário (erro de limites ou sobreposição).
 */
int posicionarNavio(int tabuleiro[][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, char orientacao, const int navio_modelo[]) {
    // --- 1. Validação de Limites Iniciais ---
    // Verifica se a coordenada inicial (linha, coluna) está dentro do tabuleiro.
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        printf("  Erro: Coordenada inicial (%d, %d) esta FORA dos limites do tabuleiro.\n", linha, coluna);
        return 0; // Falha: Posição inicial inválida
    }

    // --- 2. Validação de Limites do Navio Completo ---
    // Verifica se o navio completo, com seu tamanho e orientação, cabe no tabuleiro.
    if (orientacao == 'H' || orientacao == 'h') { // Navio na Horizontal
        if (coluna + tamanho > TAMANHO_TABULEIRO) { // Se a última parte do navio ultrapassa a borda direita
            printf("  Erro: Navio horizontal (tamanho %d) em L:%d,C:%d ultrapassa o limite DIREITO do tabuleiro.\n", tamanho, linha, coluna);
            return 0; // Falha: Não cabe
        }
    } else if (orientacao == 'V' || orientacao == 'v') { // Navio na Vertical
        if (linha + tamanho > TAMANHO_TABULEIRO) { // Se a última parte do navio ultrapassa a borda inferior
            printf("  Erro: Navio vertical (tamanho %d) em L:%d,C:%d ultrapassa o limite INFERIOR do tabuleiro.\n", tamanho, linha, coluna);
            return 0; // Falha: Não cabe
        }
    } else {
        printf("  Erro: Orientacao '%c' eh INVALIDA. Use 'H' ou 'V'.\n", orientacao);
        return 0; // Falha: Orientação desconhecida
    }

    // --- 3. Validação de Sobreposição ---
    // Verifica se alguma das células que o navio ocuparia já está ocupada por outro navio.
    for (int i = 0; i < tamanho; i++) {
        int linhaAtual = linha;
        int colunaAtual = coluna;

        if (orientacao == 'H' || orientacao == 'h') {
            colunaAtual += i; // Move para a próxima célula à direita
        } else { // orientacao == 'V' || orientacao == 'v'
            linhaAtual += i;  // Move para a próxima célula abaixo
        }

        // Se a célula no tabuleiro NÃO é AGUA, então está ocupada.
        if (tabuleiro[linhaAtual][colunaAtual] != AGUA) {
            printf("  Erro: SOBREPOSICAO detectada em L:%d,C:%d ao tentar posicionar navio.\n", linhaAtual, colunaAtual);
            return 0; // Falha: Sobreposição
        }
    }

    // --- 4. Posicionar o Navio ---
    // Se todas as validações passaram, o navio pode ser posicionado.
    // "Copia" o valor do navio_modelo (que é NAVIO, ou 3) para as posições do tabuleiro.
    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 'H' || orientacao == 'h') {
            tabuleiro[linha][coluna + i] = navio_modelo[i]; // ou simplesmente NAVIO
        } else { // orientacao == 'V' || orientacao == 'v'
            tabuleiro[linha + i][coluna] = navio_modelo[i]; // ou simplesmente NAVIO
        }
    }

    return 1; // Sucesso: Navio posicionado
}