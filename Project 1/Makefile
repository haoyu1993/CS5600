CC = gcc
CFLAGS = -Wall

all: caesar queue ciphered_queue

caesar: caesar_main.c caesar.c
	$(CC) $(CFLAGS) -o caesar caesar_main.c caesar.c

queue: queue_main.c queue.c
	$(CC) $(CFLAGS) -o queue queue_main.c queue.c

ciphered_queue: ciphered_queue_main.c caesar.c queue.c
	$(CC) $(CFLAGS) -o ciphered_queue ciphered_queue_main.c caesar.c queue.c

clean:
	rm -f caesar queue ciphered_queue
