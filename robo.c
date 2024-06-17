#include <stdio.h>
#include <stdlib.h>

// Função para verificar se a próxima posição está dentro dos limites do salão e é um ladrilho preto
int Valido(int x, int y, int L, int C, int map[L][C]) {
    return x >= 0 && x < L && y >= 0 && y < C && map[x][y] == 1;
}

// Função principal para encontrar a posição final do robô
void PosicaoFinal(int L, int C, int startX, int startY, int mapa[L][C], int *finalX, int *finalY) {
    int x = startX;
    int y = startY;
    int dx[] = {-1, 1, 0, 0}; // Mudanças na linha: Norte, Sul
    int dy[] = {0, 0, -1, 1}; // Mudanças na coluna: Oeste, Leste
    
    // Enquanto houver um próximo ladrilho preto válido
    while (1) {
        int moveu = 0;
        for (int i = 0; i < 4; i++) {
            int novoX = x + dx[i];
            int novoY = y + dy[i];
            if (Valido(novoX, novoY, L, C, mapa)) {
                mapa[x][y] = 0; // Marca o ladrilho atual como visitado
                x = novoX;
                y = novoY;
                moveu = 1;
                break;
            }
        }
        if (!moveu) {
            // Não há mais movimentos possíveis
            break;
        }
    }
    *finalX = x + 1; // Ajustando para contagem a partir de 1
    *finalY = y + 1; // Ajustando para contagem a partir de 1
}

int main() {
    int L, C;
    
    // Leitura das dimensões do salão
    scanf("%d %d", &L, &C);
    
    int A, B;
    
    // Leitura da posição inicial do robô
    scanf("%d %d", &A, &B);
    A--; // Ajustando para índice base 0
    B--; // Ajustando para índice base 0
    
    int mapa[L][C];
    
    // Leitura do mapa
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &mapa[i][j]);
        }
    }
    
    int finalX, finalY;
    
    // Encontrar a posição final
    PosicaoFinal(L, C, A, B, mapa, &finalX, &finalY);
    
    // Imprimir a posição final
    printf("%d %d\n", finalX, finalY);
    
    return 0;
}
