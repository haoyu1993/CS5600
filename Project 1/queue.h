#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int id;
    char *name;
} process_t;

typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct {
    node_t *front;
    node_t *rear;
} queue_t;

void enqueue(queue_t *queue, void *element);
void *dequeue(queue_t *queue);

#endif // QUEUE_H
