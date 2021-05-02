#include <stdio.h>
#include <stdlib.h>

void main() {
  /*
    Array(Vetores)
      arrays(vetores) sao estruturas de dados que servem para armazenar 
      varios valores de um mesmo tipo em uma unica variavel

    Estrutura 
      A estrutura de um Array é dada pelo seu tipo , seguido de "[]"
      ex: 
        char[] array1;
        int[] array2;
        bool[] array3;
        float[] array4; etc

    String
      String é uma estrutura de dados que representam os textos
      em c uma string é um array de char

     ex char[255] palavra;
      porém ao deixar assim voce pode ocupar mais espaco
      que deseja e desperdicar memoria para isso devemos
      fazer
      
      palavra[strlen(palavra)-1] = '\0'

      para ler uma String devemos fazer

      setbuf(stdin,0) para limpar o buf

      fgets(palavra,255,stdin); le a string onde os parametros sao

      fgets(variavel,tamanho,entrada) 
        variavel = para qual variavel vai a palavra digitara
        tamanho =  qual o tamanho que pode ter a palavra
        entrada = qual o tipo da entrada

      Codigo final:

      char palavra[255];

      printf("Digite uma palavra");

      setbuf(stdin,0);

      fgets(palavra,255,stdin);

      palavra[strlen(palavra)-1] = '\0';

      printf("%s",palavra);

    Matriz
      matriz e uma estrutura de dados que igual ao array
      armazena dados de uma mesma variavel , porem a matriz
      ela e dada em 2 dimensoes, pense na matematica
      que seria um x e y

      ex int matriz[5][5] aqui é uma matriz onde o "x"
      vai até 4 e o "y" vai até 4

      representação em desenho

      [00] [01] [02] [03] [04]
      [10] [11] [12] [13] [14]
      [20] [21] [22] [23] [24]
      [30] [31] [32] [33] [34]
      [40] [41] [42] [43] [44]

      para percorrer uma matriz voce deve utilizar um duplo for
      
      int x,y;

      for(y = 0 ; y < 5; y++){
        for(x = 0 ; x < 5; x++){
          printf("%d",matriz[y][x]);
        }
        printf("\n");
      }

   */               
}
