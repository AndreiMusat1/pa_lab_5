#ifndef COZI_H
#define COZI_H

#include <stdio.h>
#include <stdlib.h>

#define INT_MIN (1 << 16)

typedef struct Elem {
    int val;
    struct Elem* next;
} Elem;

typedef struct Q {
    Elem *front, *rear;
} Queue;

Queue* createQueue();
void enQueue(Queue* , int );
int deQueue(Queue* );
int isQueueEmpty(Queue* );
void deleteQueue(Queue* );
void reverseQueue(Queue* );

#endif