/* Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
int banco = 1000;
int ganhoeperda;
int aposta= 0;

main() 
{
	
printf("Programa de: Vitor Macedo Ochoa\n\n");
printf("\nFaca sua aposta: R$");
scanf("%d",&aposta);
printf("\n");
do{
if(aposta > banco || banco <= 0)
{
	printf("Saldo insuficiente");
	aposta = -999;
} 
else 
{
int gameStatus, sum, myPoint;
srand(time(NULL));
sum = rollDice(); /* primeira jogada dos dados */
switch(sum)

{

case 7:
case 11: /* vence na primeira jogada */
gameStatus = 1;
break;
case 2:
case 3:
case 12: /* perde na primeira jogada */
gameStatus = 2;
break;
default: /* armazena o ponto */
gameStatus = 0;
myPoint = sum;
printf("O ponto e %d\n", myPoint);
break;

}

if(gameStatus == 1)
{
ganhoeperda=banco + aposta;
printf("\nAposta de: R$ %d obteve vitoria",aposta);
printf("\n\nSua banca sofreu alteracao, no limite disponivel: R$ %d",ganhoeperda);
banco = ganhoeperda;
}
else
{
ganhoeperda=banco-aposta;
printf("\nAposta de: R$ %d obteve derrota",aposta);
printf("\n\nSua banca sofreu alteracao, novo limite disponivel: R$ %d",ganhoeperda);
banco = ganhoeperda;
}

printf("\nDeseja continuar jogando? Digite -999 para sair ou faça uma nova aposta para continuar para continuar.\n R$");
scanf("%d",&aposta);
}
} while (aposta != -999);
return 0;
}

int rollDice(void)
{
int die1,die2,workSum;
{
int die1 = 1 + (rand() % 6);
int die2 = 1 + (rand() % 6);
int workSum = die1 + die2;
printf("Jogador obteve %d + %d = %d", die1, die2, workSum);
printf("\n");
return workSum;
}
}
