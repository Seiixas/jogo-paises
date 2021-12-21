# 🇧🇷 Jogo dos Países 🇧🇷

Neste jogo, dez países do mundo são sorteados aleatoriamente e a sua missão é colocá-los em ordem alfabética!

# Índice
- 1 - Como executar o jogo
- 2 - Como compilar o código-fonte
- 3 - Versões de desenvolvimento
- 4 - Sobre o desenvolvimento

## 1. 🐧Como executar o jogo
Faça o download do paises.out para seu computador e da lista de países dentro da pasta util/paises.txt. Após, torne o jogo executável por meio do comando:
```bash
sudo chmod +x paises.out
```

Sendo assim, basta executar o jogo passando o arquivo de países por parâmetro!
```bash
./paises.out < paises.txt
```
# 2. ☕ Como compilar o código-fonte

Para compilar o código-fonte, basta acessar a pasta src e abrir o código fonte do jogo (src/paises.c). Nota-se que é necessário algum compilador da linguagem C como o gcc instalado na máquina.

Por fim, basta compilar o código normalmente!
```bash
gcc paises.c -o paises.out
```
# 3. 🛠️ Versões de desenvolvimento

As versões de desenvolvimento funcionam de forma parecida com a build final, porém contendo a ordem alfabética correta dos países sorteados para que o jogador possa testar e possivelmente encontrar falhas no jogo e quiçá corrigí-las! Os exetutáveis compilados encontram-se no diretório raíz (paisesDev.out), enquanto os códigos-fonte estão localizados na pasta src/paisesDev.c. 

Para executar ou compilar, basta seguir os passos anteriores, porém agora utilizando os arquivos dev.

# 4. 🖥️ Sobre o desenvolvimento

Este jogo foi desenvolvido como um dos desafios para a disciplina de Estrutura de Dados I propostas pelo professor Adriano Antunes no curso de Bacharelado em Sistemas de Informação do Instituto Federal do Norte de Minas Gerais - Campus Januária.

##### 4. 🖥 Tecnologias abordadas no projeto
- Manipulação de strings em C;
- Explorando a biblioteca <string.h>;
- Vetores de caracteres;

![IFNMG - Januaria](images/ifnmg.png)
