#include "cozi.h"

int main(void) {
    Queue* q = createQueue();

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    reverseQueue(q);

    printf("Reversed queue:\n");
    while(!isQueueEmpty(q)) {
        printf("%d ", (q->front)->val);
        q->front = (q->front)->next;
    }

    return 0;
}