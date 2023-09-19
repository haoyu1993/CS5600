#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue_t *create_queue() {
    queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
    if (queue == NULL) {
        fprintf(stderr, "Failed to allocate memory for queue.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(queue_t *queue, void *element) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Failed to allocate memory for node.\n");
        exit(1);
    }
    new_node->data = element;
    new_node->next = NULL;
    
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

void *dequeue(queue_t *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty. Cannot dequeue.\n");
        return NULL;
    }
    
    node_t *front_node = queue->front;
    void *data = front_node->data;
    
    queue->front = front_node->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(front_node);
    return data;
}

void free_queue(queue_t *queue) {
    while (queue->front != NULL) {
        dequeue(queue);
    }
    free(queue);
}
