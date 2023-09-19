#ifndef QUEUE_H
#define QUEUE_H

typedef struct process {
    int id;
    char *name;
} process_t;

typedef struct node {
    void *data;
    struct node *next;
} node_t;

typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

queue_t *create_queue();
void enqueue(queue_t *queue, void *element);
void *dequeue(queue_t *queue);
void free_queue(queue_t *queue);

#endif /* QUEUE_H */
