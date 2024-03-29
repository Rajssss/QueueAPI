#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

// Queue DS API - <WIP>
// Copyright Rajesh Kumbhakar (Rajssss@GitHub) 2019.
// Licenced under GPL V3.

/*--------------------------------------------------------------------
 * --> Part of WIP Project of full Data Structure API written in C.
 *--> TODOs: 1.Circular Queue
 *           2.Dynamic Queue (with Linked List)
 *           3.More memory control and handling feature...
 * --------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define _FETAL_INPUT "INVALID INPUT: Quiting.."
#define _FATAL_OUT_OF_MEMORY "FATAL: Out of memory..."

typedef struct {
  int Size;
  short int front;
  short int rear;
  int *Q_Data;
} Queue;

void CreateQueue(Queue *Q);
void EnQueue(Queue *Q, int value);
int DeQueue(Queue *Q);
void DisplayQueue(Queue *Q);

void CreateQueue(Queue *Q) {
  if (Q->Size <= 0) {
    printf("\n%s\n", _FETAL_INPUT);
    Sleep(3 * 1000);
    exit(EXIT_SUCCESS);
  }
  Q->front = Q->rear = 0;
  Q->Size = Q->Size+1; //One extra space should be left untouched for circular functionality.
  Q->Q_Data = (int *)malloc(Q->Size * sizeof(int));
}

void EnQueue(Queue *Q, int value) {
  if ((Q->rear + 1) % Q->Size == Q->front) {
    printf("\n%s", _FATAL_OUT_OF_MEMORY);
    Sleep(3 * 1000);
    exit(EXIT_SUCCESS);
  } else {
    Q->rear = (Q->rear + 1) % Q->Size;
    Q->Q_Data[Q->rear] = value;
  }
}
void DisplayQueue(Queue *Q) {
    int i = Q->front+1;

    do{
        printf("\n%d", Q->Q_Data[i]);
        i = (i+1)%Q->Size;
    }while (i!=(Q->rear+1)%Q->Size);
}

int DeQueue(Queue *Q) {
  if (Q->rear == Q->Size) {
    printf("%s", _FATAL_OUT_OF_MEMORY);
  } else {
    Q->front = (Q->front + 1) % Q->Size;
    return Q->Q_Data[Q->front];
  }
}

#endif // QUEUE_QUEUE_H
