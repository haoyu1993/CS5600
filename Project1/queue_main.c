#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() {
    queue_t queue;
    queue.front = NULL;
    queue.rear = NULL;

    process_t process1 = {1, "A"};
    process_t process2 = {2, "B"};
    process_t process3 = {3, "C"};

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process1.id, process1.name);
    enqueue(&queue, &process1);
    printf("[id: %d, name: %s]\n", process1.id, process1.name);

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process2.id, process2.name);
    enqueue(&queue, &process2);
    printf("[id: %d, name: %s] -> ", process1.id, process1.name);
    printf("[id: %d, name: %s]\n", process2.id, process2.name);

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process3.id, process3.name);
    enqueue(&queue, &process3);
    printf("[id: %d, name: %s] -> [id: %d, name: %s] -> ", process1.id, process1.name, process2.id, process2.name);
    printf("[id: %d, name: %s]\n", process3.id, process3.name);

    printf("Dequeue: [id: %d, name: %s] is dequeued. ", ((process_t *)dequeue(&queue))->id, ((process_t *)dequeue(&queue))->name);
    printf("[id: %d, name: %s] -> ", ((process_t *)dequeue(&queue))->id, ((process_t *)dequeue(&queue))->name);
    printf("[id: %d, name: %s]\n", ((process_t *)dequeue(&queue))->id, ((process_t *)dequeue(&queue))->name);

    return 0;
}
