/*
*   DKU Operating System Lab
*       Lab1 (Scheduler Algorithm Simulator)
*        Student id : 32163006, 32164420
*        Student name : 이건욱, 조정민
*
*   lab1_sched_types.h :
*       - lab1 header file.
*       - must contains scueduler algorithm function's declations.
*
*/

#ifndef _LAB1_HEADER_H
#define _LAB1_HEADER_H

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>
#include <stddef.h>
#include "lab1_sched_types.h"

typedef struct process
{
    char name;
    int arrival;
    int service; //실행해야하는 시간
    int runtime[3]; //실제 실행시간
    int r_run;
    int ticket;
}process;

char Print[200];
process Task[5];

typedef struct Node //노드 정의
{
    process* data;
    struct Node* link;
}Node;

typedef struct Queue //Queue 구조체 정의
{
    Node* front; //맨 앞(꺼낼 위치)
    Node* rear; //맨 뒤(보관할 위치)
    int count;//보관 개수
}Queue;

void process1();
void process2();
void InitQueue(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, process* data);
Node* Dequeue(Queue* queue);
int getLCM(int* numArr);
int getGDC(int small, int big);
int power(int x, int y);
void Show();
void FIFO(process a, process b, process c, process d, process e);
void RR(process a, process b, process c, process d, process e, int q);
void MLFQ(process a, process b, process c, process d, process e, int q);
void Stride(process a, process b, process c, process d, process e);


#endif /* LAB1_HEADER_H*/



