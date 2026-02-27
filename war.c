#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[50];
    char corExercito[50];
    int numTropas;
} Territorio;

// Protótipos das funções
void realizarAtaque(Territorio *atacante, Territorio *defensor);

int main() {
    int n = 5; // Número de territórios
    srand(time(NULL)); // Inicializa a semente para números aleatórios

    // Alocação Dinâmica com calloc (limpa a memória com zeros)
    Territorio *mapa = (Territorio *)calloc(n, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // 2. Cadastro (Entrada de dados)
    for (int i = 0; i < n; i++) {
        printf("--- Cadastro do Território %d ---\n", i + 1);
        printf("Nome do Território: ");
        scanf(" %[^\n]s", mapa[i].nome);
        printf("Cor do Exército: ");
        scanf(" %s", mapa[i].corExercito);
        printf("Número de Tropas: ");
        scanf("%d", &mapa[i].numTropas);
        printf("\n");
    }

    // 3. Fase de Ataque (Loop Interativo)
    int at, def;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        printf("\n--- FASE DE ATAQUE ---\n");
        printf("Escolha o território ATACANTE (1 a %d): ", n);
        scanf("%d", &at);
        printf("Escolha o território DEFENSOR (1 a %d): ", n);
        scanf("%d", &def);

        // Ajuste de índice (usuário digita 1-5, o C usa 0-4)
        if (at != def && at > 0 && at <= n && def > 0 && def <= n) {
            realizarAtaque(&mapa[at - 1], &mapa[def - 1]);
        } else {
            printf("Escolha inválida! Não pode atacar a si mesmo ou índice fora do mapa.\n");
        }

        printf("\nDeseja realizar outro ataque? (s/n): ");
        scanf(" %c", &continuar);
    }

    // 4. Liberação de Memória
    free(mapa);
    printf("\nMemória liberada. Fim de jogo!\n");

    return 0;
}

// Função de Batalha usando Ponteiros
void realizarAtaque(Territorio *at, Territorio *def) {
    if (at->numTropas <= 1) {
        printf("\nO território %s não tem tropas suficientes para atacar!\n", at->nome);
        return;
    }

    // Simulação de dados (1 a 6)
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\n⚔️ BATALHA: %s (%s) vs %s (%s)\n", at->nome, at->corExercito, def->nome, def->corExercito);
    printf("Dado Atacante: [%d] | Dado Defensor: [%d]\n", dadoAtacante, dadoDefensor);

    // Lógica: Empate ou vitória do atacante
    if (dadoAtacante >= dadoDefensor) {
        printf("O atacante venceu o duelo!\n");
        def->numTropas--;
        
        if (def->numTropas <= 0) {
            printf("TERRITÓRIO CONQUISTADO! %s agora pertence ao exército %s.\n", def->nome, at->corExercito);
            strcpy(def->corExercito, at->corExercito);
            def->numTropas = 1; // Tropas mínimas após conquista
        }
    } else {
        printf("O defensor resistiu! Atacante perdeu uma tropa.\n");
        at->numTropas--;
    }

    printf("Status atual: %s (%d tropas) | %s (%d tropas)\n", at->nome, at->numTropas, def->nome, def->numTropas);
}
