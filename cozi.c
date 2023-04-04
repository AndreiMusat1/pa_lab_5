#include "cozi.h"
#include "stive.h"

Queue* createQueue() {
	Queue* q = (Queue*) malloc(sizeof(Queue));

	if (q==NULL) {
		return NULL;
	}

	q->front = q->rear = NULL;

	return q;	
}

 void enQueue(Queue* q, int v) { 
	Elem* newNode = (Elem*) malloc(sizeof(Elem));

	newNode->val = v;
	newNode->next = NULL;

	if (q->rear==NULL) {
		q->rear = newNode;
	} else {
		(q->rear)->next = newNode;
		(q->rear) = newNode;
	}

	if (q->front==NULL) {
		q->front = q->rear;
	} 
}
 
int deQueue(Queue* q) {  
	Elem* aux; 
	int d;

	if (isQueueEmpty(q)) {
		return INT_MIN;
	}
	
	aux = q->front; 
	d = aux->val;
	q->front = (q->front)->next;

	free(aux);

	return d;  	
} 

int isQueueEmpty(Queue* q) {
	return (q->front == NULL);
}

void deleteQueue(Queue* q) {
	Elem* aux;

	while (!isQueueEmpty(q)) {
		aux = q->front;
		q->front = q->front->next;

		free(aux);
	}

	free(q);
}	

void reverseQueue(Queue* q) {
	Node* head = NULL;
	int value;

	while(!isQueueEmpty(q)) {
		value = deQueue(q);
		push(&head, value);
	}

	while(!isEmpty(head)) {
		value = pop(&head);
		enQueue(q, value);
	}
}