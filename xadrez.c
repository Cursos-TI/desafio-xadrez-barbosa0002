#include <stdio.h>

/**
 * Programa que simula o movimento de peças de xadrez (Torre, Bispo, Rainha e Cavalo)
 * utilizando técnicas como recursividade e loops, além dos demais requisitos 
 * das outras fases do desafio.
 */

// Funções que serão usadas
void moveTorre(int casasRestantes, char direcao[]);
void moveRainha(int casasRestantes, char direcao[]);
void moveBispoRecursivo(int casasRestantes, char direcao[]);
void moveBispoLoops(int totalCasas, char direcaoVertical[], char direcaoHorizontal[]);

int main() {
    // Strings para as direções
    char direcaoDireita[8] = "Direita";
    char direcaoEsquerda[9] = "Esquerda";
    char direcaoCima[5] = "Cima";
    char direcaoBaixo[6] = "Baixo";
    char direcaoCimaDireita[13] = "Cima, Direita";
    
    // Constantes para o número de casas
    const int TORRE_CASAS = 5;    // Torre move 5 casas
    const int BISPO_CASAS = 5;    // Bispo move 5 casas
    const int RAINHA_CASAS = 8;   // Rainha move 8 casas
    const int CAVALO_VERTICAL = 2;    // Cavalo move 2 casas na vertical
    const int CAVALO_HORIZONTAL = 1;  // Cavalo move 1 casa na horizontal
    
    printf("==== Simulação de Movimentos no Xadrez - Versão Avançada ====\n\n");
    
    // 1. TORRE com recursividade
    printf("Movimento da TORRE (5 casas para a direita) - Recursivo:\n");
    moveTorre(TORRE_CASAS, direcaoDireita);
    printf("\n");
    
    // 2. BISPO com recursividade
    printf("Movimento do BISPO (5 casas na diagonal) - Recursivo:\n");
    moveBispoRecursivo(BISPO_CASAS, direcaoCimaDireita);
    printf("\n");
    
    // 3. BISPO com loops aninhados
    printf("Movimento do BISPO (5 casas na diagonal) - Loops Aninhados:\n");
    moveBispoLoops(BISPO_CASAS, direcaoCima, direcaoDireita);
    printf("\n");
    
    // 4. RAINHA com recursividade
    printf("Movimento da RAINHA (8 casas para a esquerda) - Recursivo:\n");
    moveRainha(RAINHA_CASAS, direcaoEsquerda);
    printf("\n");
    
    // 5. CAVALO com loops aninhados complexos
    printf("Movimento do CAVALO (movimento em L - 2 para cima, 1 para a direita) - Loops Complexos:\n");
    
    // Variáveis para contar os movimentos
    int movCima = 0;
    int movDireita = 0;
    int totalMov = CAVALO_VERTICAL + CAVALO_HORIZONTAL;
    
    // Loop externo para todos os movimentos
    for (int i = 0; i < totalMov; i++) {
        // Loop interno para decidir qual direção mover
        for (int j = 0; j <= i; j++) {
            // Se ainda tem que mover para cima
            if (movCima < CAVALO_VERTICAL) {
                printf("%s\n", direcaoCima);
                movCima = movCima + 1;
                break; // Sai do loop interno
            } 
            // Se já moveu para cima, agora move para a direita
            else if (movDireita < CAVALO_HORIZONTAL) {
                printf("%s\n", direcaoDireita);
                movDireita = movDireita + 1;
                break; // Sai do loop interno
            }
        }
        
        // Verifica se já completou todos os movimentos
        if (movCima >= CAVALO_VERTICAL && movDireita >= CAVALO_HORIZONTAL) {
            break; // Sai do loop externo
        }
    }
    
    printf("\n==== Fim da Simulação ====\n");
    
    return 0;
}

// Função para mover a Torre
void moveTorre(int casasRestantes, char direcao[]) {
    // Se não tem mais casas para mover, para a recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Mostra a direção e chama a função novamente com uma casa a menos
    printf("%s\n", direcao);
    moveTorre(casasRestantes - 1, direcao);
}

// Função para mover o Bispo com recursividade
void moveBispoRecursivo(int casasRestantes, char direcao[]) {
    // Se não tem mais casas para mover, para a recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Mostra a direção e chama a função novamente com uma casa a menos
    printf("%s\n", direcao);
    moveBispoRecursivo(casasRestantes - 1, direcao);
}

// Função para mover o Bispo com loops aninhados
void moveBispoLoops(int totalCasas, char direcaoVertical[], char direcaoHorizontal[]) {
    // Loop externo para movimento vertical
    for (int i = 0; i < totalCasas; i++) {
        // Loop interno para movimento horizontal
        for (int j = 0; j < 1; j++) {
            // Mostra as duas direções juntas
            printf("%s, %s\n", direcaoVertical, direcaoHorizontal);
        }
    }
}

// Função para mover a Rainha
void moveRainha(int casasRestantes, char direcao[]) {
    // Se não tem mais casas para mover, para a recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Mostra a direção e chama a função novamente com uma casa a menos
    printf("%s\n", direcao);
    moveRainha(casasRestantes - 1, direcao);
}
