#ifndef LOTTERY_H
#define LOTTERY_H

#include "sched.h"

typedef struct lottery_params {
        int num_tickets;

} LotterySchedParams;

//Funcao chamada pela inicializacao do S.O. para a incializacao do escalonador
//conforme o algoritmo Lottery Scheduling
//Deve envolver a inicializacao de possiveis parametros gerais
//Deve envolver o registro do algoritmo junto ao escalonador
void lottInitSchedInfo(void);

//Inicializa os parametros de escalonamento de um processo p, chamada
//normalmente quando o processo e' associado ao slot de Lottery
void lottInitSchedParams(Process *p, void *params);

//Retorna o proximo processo a obter a CPU, conforme o algortimo Lottery
Process* lottSchedule(Process *plist);

//Libera os parametros de escalonamento de um processo p, chamada
//normalmente quando o processo e' desassociado do slot de Lottery
//Retorna o numero do slot ao qual o processo estava associado
int lottReleaseParams(Process *p);

//Transfere certo numero de tickets do processo src para o processo dst.//Retorna o numero de tickets efetivamente transfeirdos (pode ser menos)
int lottTransferTickets(Process *src, Process *dst, int tickets);

#endif
