CC = gcc
CFLAGS = -Wall

all: queue caesar ciphered_queue

queue: queue_main.c queue.c
    $(CC) $(CFLAGS) -o queue queue_main.c queue.c

caesar: caesar.c
    $(CC) $(CFLAGS) -o caesar caesar.c

ciphered_queue: ciphered_queue_main.c queue.c
    $(CC) $(CFLAGS) -o ciphered_queue ciphered_queue_main.c queue.c

clean:
    rm -f queue caesar ciphered_queue
