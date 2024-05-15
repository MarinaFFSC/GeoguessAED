#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JOGADORES 30 

typedef struct Jogador {
    char nome[50];
    int pontuacao;
} Jogador;


typedef struct No {
    char dica1[100];  
    char dica2[100];  
    char dica3[100];  
    char resposta[30]; 
    struct No* prox;
    struct No* ant;
} No;


No* criarNo(const char* dica1, const char* dica2, const char* dica3, const char* resposta) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro: Memória insuficiente.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(novoNo->dica1, dica1);
    strcpy(novoNo->dica2, dica2);
    strcpy(novoNo->dica3, dica3);
    strcpy(novoNo->resposta, resposta);
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    return novoNo;
}


void adicionarNo(No** cabeca, const char* dica1, const char* dica2, const char* dica3, const char* resposta) {
    No* novoNo = criarNo(dica1, dica2, dica3, resposta);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
        novoNo->ant = temp;
    }
}

void liberarLista(No* cabeca) {
    while (cabeca != NULL) {
        No* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}


void jogarQuiz(No* cabeca, Jogador* jogador) {
    int pontuacao = 0;
    No* atual = cabeca;

    while (atual != NULL) {
        printf("\nDicas:\n");
        printf("\nDica 1: %s\n", atual->dica1);
        printf("Dica 2: %s\n", atual->dica2);
        printf("Dica 3: %s\n", atual->dica3);

  
        char palpite[30];
        printf("\nAdivinhe o nome do país - lembre-se de colocar os acentos se necessário (ou 'sair' para encerrar): ");
        scanf(" %[^\n]", palpite);

        if (strcmp(palpite, "sair") == 0) {
            printf("\nVocê decidiu encerrar o jogo. Obrigado por jogar!\n");
            break;
        }

        if (strcasecmp(palpite, atual->resposta) == 0) {
            printf("\nResposta correta! +10 pontos.\n");
            pontuacao += 10;
        } else {
            printf("\nResposta incorreta. A resposta correta era: %s\n", atual->resposta);
        }

        atual = atual->prox; 
    }

    
    jogador->pontuacao = pontuacao;
    printf("Pontuação final: %d pontos.\n", jogador->pontuacao);
}


void ordenarJogadores(Jogador jogadores[], int numJogadores) {
    for (int i = 0; i < numJogadores - 1; i++) {
        for (int j = 0; j < numJogadores - i - 1; j++) {
            if (jogadores[j].pontuacao < jogadores[j + 1].pontuacao) {
                Jogador temp = jogadores[j];
                jogadores[j] = jogadores[j + 1];
                jogadores[j + 1] = temp;
            }
        }
    }
}

void exibirRanking(Jogador jogadores[], int numJogadores) {
    printf("\n===== RANKING DOS JOGADORES =====\n");
    for (int i = 0; i < numJogadores; i++) {
        printf("%dº lugar: %s - Pontuação: %d\n", i + 1, jogadores[i].nome, jogadores[i].pontuacao);
    }
}

int main() {
    No* paises = NULL;

    adicionarNo(&paises, "É conhecido por seus fiordes impressionantes.",
               "Sua capital é Oslo.",
               "É famoso por sua qualidade de vida e altos padrões sociais.",
               "Noruega");

    adicionarNo(&paises, "É o maior país do mundo em área territorial.",
               "Possui uma extensa rede ferroviária conhecida como o Transiberiano.",
               "Moscou é sua capital.",
               "Rússia");
    adicionarNo(&paises, "É conhecido por suas pirâmides antigas e faraós.",
           "O rio Nilo é fundamental para sua história e economia.",
           "Sua capital é Cairo.",
           "Egito");

    adicionarNo(&paises, "É o lar da Estátua da Liberdade.",
       "Seu sistema de entretenimento em Hollywood é famoso globalmente.",
       "A capital do país é Washington, D.C.",
       "Estados Unidos");

    adicionarNo(&paises, "É famoso por sua culinária sofisticada e vinhos de alta qualidade.",
       "Tem uma torre emblemática que é uma das Sete Maravilhas do Mundo Moderno.",
       "Sua capital é Paris.",
       "França");

    adicionarNo(&paises, "É uma nação insular com uma fauna única, incluindo o canguru.",
       "Seu maior recife é a Grande Barreira de Corais.",
       "A Opera House de Sydney é um ícone mundial.",
       "Austrália");

    adicionarNo(&paises, "É um país escandinavo com alta qualidade de vida.",
       "Conhecido por seu design minimalista e eficiência urbana.",
       "Sua capital é Estocolmo.",
       "Suécia");

    adicionarNo(&paises, "Tem uma das economias mais avançadas do mundo.",
       "Conhecido por sua tecnologia de ponta e cultura pop.",
       "Sua capital é Tóquio.",
       "Japão");

    adicionarNo(&paises, "É o maior país da América do Sul.",
       "Abriga a Floresta Amazônica, a maior floresta tropical do mundo.",
       "Sua capital é Brasília.",
       "Brasil");

    adicionarNo(&paises, "É um país insular com uma paisagem marcante de montanhas e fiordes.",
       "Conhecido por sua população amigável e padrões de vida elevados, bem como o banho nas piscinas termais.",
       "Sua capital é Reykjavik",
       "Islândia");

    adicionarNo(&paises, "Foi o centro da civilização greco-romana.",
       "Roma é sua capital.",
       "É conhecido por sua rica herança artística e arquitetônica.",
       "Itália");

    adicionarNo(&paises, "Fica na Europa Ocidental e é famoso por seus canais e bicicletas.",
       "Sua capital é Amsterdã.",
       "Conhecido por suas flores, especialmente tulipas.",
       "Holanda");

    adicionarNo(&paises, "Fica no sul da Ásia e é conhecido por sua rica herança cultural e espiritual.",
       "Sua capital é Nova Deli",
       "É o lar do famoso monumento Taj Mahal.",
       "Índia");

    adicionarNo(&paises, "É uma nação no leste da Ásia conhecida por sua alta tecnologia e tradições antigas.",
       "Sua capital é Seul.",
       "É um líder global em eletrônicos e entretenimento.",
       "Coreia do Sul");

    adicionarNo(&paises, "É um país na América do Norte com uma diversidade geográfica impressionante.",
       "Sua capital é Ottawa.",
       "Famoso por suas Cataratas do Niágara.",
       "Canadá");

    adicionarNo(&paises, "Fica no sul da Europa e é conhecido por sua rica história e cultura.",
       "Sua capital é Atenas.",
       "Berço da democracia e lar de monumentos históricos como a Acrópole.",
       "Grécia");

    adicionarNo(&paises, "É uma ilha caribenha conhecida por suas praias deslumbrantes e música reggae.",
       "Sua capital é Kingston.",
       "Lar do famoso cantor Bob Marley.",
       "Jamaica");

    adicionarNo(&paises, "É um país localizado no continente asiático, especificamente na Ásia Oriental",
       "Famoso por sua Grande Muralha e pela Cidade Proibida.",
       "Sua capital é Pequim.",
       "China");

    adicionarNo(&paises, "É conhecido por seus templos antigos, incluindo Angkor Wat.",
       "Sua capital é Phnom Penh.",
       "Tem uma rica história marcada por reinos poderosos.",
       "Camboja");


    printf("Bem-vindo ao Geoguess!\n");
    printf("Esse jogo foi desenvolvido por alunos da Cesar School com o intuito de promover a aprendizagem acerca dos Países do mundo.\n");
    printf("Serão dadas 3 dicas para que jogador tente acertar a qual país elas se referem.\n");
    printf("Vamos jogar?\n\n");

    Jogador jogadores[MAX_JOGADORES];
    int numJogadores = 0;

    FILE* arquivo = fopen("ranking.txt", "r");
    if (arquivo != NULL) {
        while (fscanf(arquivo, "%s %d", jogadores[numJogadores].nome, &jogadores[numJogadores].pontuacao) == 2) {
            numJogadores++;
            if (numJogadores >= MAX_JOGADORES) {
                break;
            }
        }
        fclose(arquivo);
    }

    printf("Por favor, insira seu nome ou apelido: ");
    scanf(" %[^\n]", jogadores[numJogadores].nome);
    numJogadores++;

    int escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Iniciar o Jogo\n");
        printf("2. Exibir Ranking\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nComeçando o Jogo...\n");
                jogarQuiz(paises, &jogadores[numJogadores - 1]);
                break;
            case 2:
                ordenarJogadores(jogadores, numJogadores);
                exibirRanking(jogadores, numJogadores);
                break;
            case 3:
                printf("\nObrigado por jogar!\n");
                arquivo = fopen("ranking.txt", "w");
                if (arquivo != NULL) {
                    for (int i = 0; i < numJogadores; i++) {
                        fprintf(arquivo, "%s %d\n", jogadores[i].nome, jogadores[i].pontuacao);
                    }
                    fclose(arquivo);
                }

                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 3);

    liberarLista(paises);

    return 0;
}