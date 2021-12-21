#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char paisesOrdenados[10][100];

void menu() {
  printf("                             o                              \n");
  printf("                            /\\                             \n");
  printf("                           /::\\                            \n");
  printf("                          /::::\\        BEM-VINDO AO JOGO DOS PAÍSES\n");
  printf("            ,a_a         /\\::::/\\ \n");
  printf("           {/ ''\\_      /\\ \\::/\\ \\        Neste jogo, o jogador deve\n");
  printf("           {\\ ,_oo)    /\\ \\ \\/\\ \\ \\     ordenar uma lista aleatória\n");
  printf("           {/  (_^____/  \\ \\ \\ \\ \\ \\    de países em ordem alfabética\n");
  printf(" .=.      {/ \\___)))*)    \\ \\ \\ \\ \\/      trocando as suas posições\n");
  printf("(.=.`\\   {/   /=;  ~/      \\ \\ \\ \\/                    \n");
  printf("    \\ `\\{/(   \\/\\  /        \\ \\ \\/            Você está pronto?\n");
  printf("     \\  `. `\\  ) )           \\ \\/          Iniciando em 3 segundos...\n");
  printf(" jgs  \\    // /_/_            \\/                          \n");
  printf("       '==''---))))                          © RocketTeam - 2021   \n");
  system ("sleep 3");
  system("clear");
}

void ordenaPaises() {
  char auxiliar[100];
  int comp;
  for(int i = 0; i < 10; i++) {
    for(int j = (i + 1); j < 10; j++) {
      comp = strcmp(paisesOrdenados[i], paisesOrdenados[j]);
      if (comp > 0) {
        strcpy(auxiliar, paisesOrdenados[i]);
        strcpy(paisesOrdenados[i], paisesOrdenados[j]);
        strcpy(paisesOrdenados[j], auxiliar);
      }
    }
  }
}

int calculaValorPaises() {
  int cont = 0;

  for(int i = 0; i < 10; i++) {
    for(int j = (i + 1); j < 10; j++) {
      cont += strcmp(paisesOrdenados[i], paisesOrdenados[j]);
    }
  }

  return cont;
}

int main() {
  char paises[197][100];
  char paisesOrdem[10][100];
  char auxiliar[100];
  int cont = 0, antes, depois, indicesSorteados[10];
  
  menu();

  // Realiza a leitura de todos os países
  for(int i = 0; i < 197; i++)
    scanf(" %[^\n]s", paises[i]);

  // Sorteia 10 países para o início do jogo
  srand(time(NULL));
  for(int i = 0; i < 10; i++) {
    int aleatorio = rand() % 197;
    indicesSorteados[i] = aleatorio;
  }

  for(int i = 0; i < 10; i++) 
    for(int j = (i + 1); j < 10; j++) {
      if (indicesSorteados[i] == indicesSorteados[j])
        indicesSorteados[i] = rand() % 197;
    }
  
  for(int i = 9; i >= 0; i--) 
    for(int j = 9; j >= (i + 1); j--) {
      if(indicesSorteados[i] == indicesSorteados[j]) 
        indicesSorteados[i] = rand() % 197;
    }

  for (int i = 0; i < 10; i++) {
    int indice = indicesSorteados[i];
    strcpy(paisesOrdem[i], paises[indice]);
    strcpy(paisesOrdenados[i], paises[indice]);
  }

  // Ordena os países em ordem alfábetica em outro vetor
  ordenaPaises();

  // Reabre a leitura de caracteres para o teclado
  freopen("/dev/tty", "rw", stdin);

  do {
    system("clear");

    // Imprime os 10 países sorteados
    for(int i = 0; i < 10; i++) {
      printf(" [%0d] %s\n", i, paisesOrdem[i]);
    }

    // Solicita ao usuário as posições de troca
    printf("\n Digite os índices dos países\n  > ");
    scanf("%d %d", &antes, &depois);

    // Troca os valores dos países de acordo com a ordem do usuário
    strcpy(auxiliar, paisesOrdem[depois]);
    strcpy(paisesOrdem[depois], paisesOrdem[antes]);
    strcpy(paisesOrdem[antes], auxiliar);

    // Calcula a soma de comparação de todos os 10 países
    for (int i = 0; i < 10; i++) {
      for (int j = (i+1); j < 10; j++) {
        cont += strcmp(paisesOrdem[i], paisesOrdem[j]);
      }
    }

    // Se a soma strcmp dos países atuais for diferente dos países em ordem
    if (cont != calculaValorPaises())
      cont = 0; // Reinicia a variável contadora

  } while(cont != calculaValorPaises());

  return 0;
}