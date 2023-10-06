#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(queue_t *queue, void *element) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = element;
    new_node->next = NULL;

    if (!queue->front) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

void *dequeue(queue_t *queue) {
    if (!queue->front) {
        fprintf(stderr, "Queue is empty\n");
        exit(1);
    }
    node_t *front_node = queue->front;
    void *data = front_node->data;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = front_node->next;
    }

    free(front_node);
    return data;
}
