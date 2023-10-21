# BCC202-TP02
---

Este trabalho tem como objetivo testar as habilidades estudadas na materia BCC202 (Estrutura de Dados I), e para isso, foi realizado a criação de um algoritmo de ordenação do quadro de medalhas das olimpíadas fora de ordem, na linguagem de programação C.

O programa deve colocá-lo na ordem correta. A ordem dos países no quadro de medalhas é dada pelo número de medalhas de ouro. Se há empate em medalhas de ouro, a nação que tiver mais medalhas de prata fica a frente. Havendo empate em medalhas de ouro e prata, fica mais bem colocado o país com mais medalhas de bronze. Se dois ou mais países empatarem nos três tipos de medalhas, o programa deve mostrá-los em ordem alfabética.

É necessário compilar e executar o projeto em sua máquina:
 
> Windows e Linux
```bash
> gcc ordenacao.c -c
> gcc principal.c -c
> gcc ordenacao.o principal.o -o programa -Wall
> ./programa < casoteste.in
```
