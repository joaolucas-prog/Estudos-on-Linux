#include <stdio.h>//biblioteca de outputs e inputs
#include <stdlib.h>//biblioteca para alocacao de memoria e controle de processos

void main() {
  printf("Hello World"); // programa mais simples em C , incui apenas sdtio.h
  
  /*tipos primitivos
   *
   * int - representa os numeros inteiros 
   * float - representa os numeros flutuantes
   * char - representa os caracteres
   *
   * para declarar uma variavel em C voce deve escrever seu tipo e em seguida seu nome e caso queira , um valor
   * ficando com a estrututa 'tipo nome = valor;'
   *
   * toda declaração de codigo deve terminar com ';'
   *
   * a função printf imprime algum dado que eu passe para ele
   * para imprimir os dados de uma variavel devemos chamar sua
   * representação adequada em seguida seu valor na memoria
   *
   * para o tipo int sua representacao e o %d
   * para o tipo float sua representacao e o %f
   * para o char sua representacao e o %c
   *
   * obs: existe outras representacoes para os tipos de variaveis porem irei apenas falar essas
   *
   * para declarar seu local de moria utilizamos o &
   *
   * exemplos :*/

  int numero1 = 10;
  printf("O valor do numero1 e: %d\n",numero1);
  //o \n significa uma quebra de linha
  float numero2 = 20.3;
  printf("O valor do numero2 e: %f\n",numero2);

  char letra = 'a';
  printf("O valor da letra e: %c\n",letra);

  //podemos receber um valor e armanela-lo em uma variavel
  printf("digite um numero:\n");
  scanf("%d", &numero1);
  getchar();//para limpar o maldito enter do buffer
  printf("O numero digitado foi : %d\n",numero1);

  //caso você queira pegar um valor de um caracter lembre-se de usar uma funcao
  //chamada fflush() para limpar o lixo que estiver no buffer de entrada
  printf("Digite um caracter:\n");
  //fflush(stdin);//stdin significa entrada principal limpa buffer no windows
  scanf("%c", &letra);
  printf("O caracter digitado foi: %c\n",letra);
    
  
}
