#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"
#include "queue.h"

int main() {
    queue_t queue;
    queue.front = NULL;
    queue.rear = NULL;

    int key = 3; // Caesar cipher key

    process_t process1 = {1, "A"};
    process_t process2 = {2, "B"};
    process_t process3 = {3, "C"};

    printf("Caesar cipher key: %d.\n", key);

    // Enqueue process1
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process1.id, process1.name);
    encode(process1.name, key);
    enqueue(&queue, &process1);
    printf("[id: %d, name: %s]\n", process1.id, process1.name);

    // Enqueue process2
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process2.id, process2.name);
    encode(process2.name, key);
    enqueue(&queue, &process2);
    printf("[id: %d, name: %s] -> [id: %d, name: %s]\n", process1.id, process1.name, process2.id, process2.name);

    // Enqueue process3
    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process3.id, process3.name);
    encode(process3.name, key);
    enqueue(&queue, &process3);
    printf("[id: %d, name: %s] -> [id: %d, name: %s] -> [id: %d, name: %s]\n",
           process1.id, process1.name, process2.id, process2.name, process3.id, process3.name);

    // Dequeue elements
    while (queue.front != NULL) {
        process_t *dequeued_process = (process_t *)dequeue(&queue);
        printf("Dequeue: [id: %d, name: %s] is dequeued. ", dequeued_process->id, dequeued_process->name);
        printf("[id: %d, name: %s]\n", dequeued_process->id, dequeued_process->name);
    }

    return 0;
}
