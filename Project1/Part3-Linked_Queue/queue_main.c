#include <stdio.h>
#include "queue.h"

int main() {
    queue_t *queue = create_queue();

    process_t process1 = {1, "A"};
    process_t process2 = {2, "B"};
    process_t process3 = {3, "C"};

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process1.id, process1.name);
    enqueue(queue, &process1);
    printf("[id: %d, name: %s]\n", process1.id, process1.name);

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process2.id, process2.name);
    enqueue(queue, &process2);
    printf("[id: %d, name: %s] -> [id: %d, name: %s]\n", process1.id, process1.name, process2.id, process2.name);

    printf("Enqueue: [id: %d, name: %s] is enqueued. ", process3.id, process3.name);
    enqueue(queue, &process3);
    printf("[id: %d, name: %s] -> [id: %d, name: %s] -> [id: %d, name: %s]\n",
           process1.id, process1.name, process2.id, process2.name, process3.id, process3.name);

    while (queue->front != NULL) {
        process_t *front_process = (process_t *)dequeue(queue);
        printf("Dequeue: [id: %d, name: %s] is dequeued. ", front_process->id, front_process->name);
        if (queue->front == NULL) {
            printf("[Empty]\n");
        } else {
            printf("[id: %d, name: %s]\n", ((process_t *)queue->front->data)->id, ((process_t *)queue->front->data)->name);
        }
    }

    free_queue(queue);

    return 0;
}
