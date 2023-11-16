#include "stairs.h"





// You can write your own semwait function that can call sem_wait(sem) or sem_trywait(sem)
// in addition to checking/setting proper variables
// properly use pthread_mutex_lock/unlock
 

// You can write your own sempost function that call sem_post(sem)
// in addition to checking/setting proper variables
// properly use pthread_mutex_lock/unlock

 

void *threadfunction (void *vargp) {
    // write the threadfunction whose name should be part of pthread_create(..)
	// Don't forget your timing computations

    

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    

    //printf("Number of Customers: %d\nNumber of stairs: %d\n", ...., .....);
    

  
    // sem_init(.....);
	// generate an array of threads, set their direction randomly, call pthread_create, 
	// then sleep for some random nonzero time

  // your code here

	// for each thread created, call pthread_join(..)
    



   // printf turnaround time for each thread and average turnaround time
    
  // free every pointer you used malloc for

 
    return 0;
}

#define MAX_CUSTOMERS 30
#define MAX_STEPS 13
#define STAIR_TIME 1

int customers_on_stairs = 0;
int current_direction = -1;  // -1 indicates no current direction
pthread_mutex_t stairs_mutex;
sem_t stairs_sem;

// Semwait function
void semwait(sem_t *sem) {
    sem_wait(sem);
}

// Sempost function
void sempost(sem_t *sem) {
    sem_post(sem);
}

// Function to check if stairs can be used
bool can_use_stairs(int direction) {
    pthread_mutex_lock(&stairs_mutex);
    bool result = (current_direction == -1 || current_direction == direction) && customers_on_stairs < MAX_STEPS;
    if (result) {
        current_direction = direction;
        customers_on_stairs++;
    }
    pthread_mutex_unlock(&stairs_mutex);
    return result;
}

// Function to leave the stairs
void leave_stairs() {
    pthread_mutex_lock(&stairs_mutex);
    customers_on_stairs--;
    if (customers_on_stairs == 0) {
        current_direction = -1;
    }
    pthread_mutex_unlock(&stairs_mutex);
}

void *threadfunction (void *vargp) {
    thread_arg_t *arg = (thread_arg_t *)vargp;
    printf("Customer %d trying to go %s\n", arg->index, arg->direction == 0 ? "down" : "up");
    
    while (!can_use_stairs(arg->direction)) {
        sleep(1);  // Wait before retrying
    }
    
    printf("Customer %d is using the stairs\n", arg->index);
    sleep(STAIR_TIME);  // Simulating time to cross the stairs
    leave_stairs();
    printf("Customer %d has left the stairs\n", arg->index);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // Initialize mutex and semaphore
    pthread_mutex_init(&stairs_mutex, NULL);
    sem_init(&stairs_sem, 0, MAX_STEPS);

    // Thread creation and management logic goes here

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <number_of_customers> <number_of_steps>\n", argv[0]);
        return 1;
    }

    int number_of_customers = atoi(argv[1]);
    int number_of_steps = atoi(argv[2]);
    if (number_of_customers > MAX_CUSTOMERS || number_of_steps > MAX_STEPS) {
        fprintf(stderr, "Maximum number of customers is %d and steps is %d\n", MAX_CUSTOMERS, MAX_STEPS);
        return 1;
    }

    // Initialize mutex and semaphore
    pthread_mutex_init(&stairs_mutex, NULL);
    sem_init(&stairs_sem, 0, number_of_steps);

    pthread_t threads[number_of_customers];
    thread_arg_t args[number_of_customers];
    struct timeval start_time[number_of_customers], end_time[number_of_customers];

    // Creating threads
    for (int i = 0; i < number_of_customers; i++) {
        args[i].index = i;
        args[i].direction = rand() % 2; // Random direction
        gettimeofday(&start_time[i], NULL);
        if (pthread_create(&threads[i], NULL, threadfunction, (void *)&args[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Calculating turnaround time
    double total_turnaround_time = 0;
    for (int i = 0; i < number_of_customers; i++) {
        pthread_join(threads[i], NULL);
        gettimeofday(&end_time[i], NULL);
        double turnaround_time = (end_time[i].tv_sec - start_time[i].tv_sec) * 1000.0;
        turnaround_time += (end_time[i].tv_usec - start_time[i].tv_usec) / 1000.0;
        printf("Customer %d turnaround time: %.2f ms\n", i, turnaround_time);
        total_turnaround_time += turnaround_time;
    }

    printf("Average turnaround time: %.2f ms\n", total_turnaround_time / number_of_customers);

    // Cleanup
    pthread_mutex_destroy(&stairs_mutex);
    sem_destroy(&stairs_sem);

    return 0;
}
