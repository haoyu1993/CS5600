#include <stdio.h>
#include <string.h>
#include "queue.h"

// Caesar cipher function with a fixed key
void caesar_cipher(char *str, int key) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + key) % 26;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + key) % 26;
        }
    }
}

// Caesar cipher key
#define CIPHER_KEY 3

int main() {
    queue_t *queue = create_queue();

    // Enqueue some process_t elements with encoded names
    process_t process1 = {1, "A"};
    caesar_cipher(process1.name, CIPHER_KEY);
    enqueue(queue, &process1);
    printf("Enqueue: [id: %d, name: %s] is enqueued. [id: %d, name: %s]\n",
           process1.id, process1.name, process1.id, process1.name);

    process_t process2 = {2, "B"};
    caesar_cipher(process2.name, CIPHER_KEY);
    enqueue(queue, &process2);
    printf("Enqueue: [id: %d, name: %s] is enqueued. [id: %d, name: %s] -> [id: %d, name: %s]\n",
           process2.id, process2.name, process1.id, process1.name, process2.id, process2.name);

    process_t process3 = {3, "C"};
    caesar_cipher(process3.name, CIPHER_KEY);
    enqueue(queue, &process3);
    printf("Enqueue: [id: %d, name: %s] is enqueued. [id: %d, name: %s] -> [id: %d, name: %s] -> [id: %d, name: %s]\n",
           process3.id, process3.name, process1.id, process1.name, process2.id, process2.name, process3.id, process3.name);

    // Dequeue and print elements with decoded names
    while (queue->front != NULL) {
        process_t *p = (process_t *)dequeue(queue);
        caesar_cipher(p->name, -CIPHER_KEY);
        printf("Dequeue: [id: %d, name: %s] is dequeued. ",
               p->id, p->name);

        if (queue->front == NULL) {
            printf("[Empty]\n");
        } else {
            printf("[id: %d, name: %s] -> ", ((process_t *)queue->front->data)->id, ((process_t *)queue->front->data)->name);
        }
    }

    free_queue(queue);

    return 0;
}
