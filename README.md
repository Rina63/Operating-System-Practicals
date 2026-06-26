# Operating Systems Practicals

This repository contains practical implementations of synchronization and inter-process communication concepts in C.

---

# Practical Session 1: Mutex Lock Demonstration

## Objective
Demonstrate mutual exclusion using pthread mutex locks.

## Files
- with_mutex.c
- without_mutex.c

## Comparison
The `without_mutex.c` program allows multiple threads to access a shared counter simultaneously, which may lead to race conditions and inconsistent results. Running the program multiple times can produce different outputs.

The `with_mutex.c` program uses `pthread_mutex_lock()` and `pthread_mutex_unlock()` to ensure that only one thread accesses the shared counter at a time, producing the correct and consistent result.

---

# Practical Session 2: Producer-Consumer Simulation

## Objective
Implement the Producer-Consumer problem using POSIX semaphores.

## Semaphores Used
- mutex (1): Protects the buffer from simultaneous access.
- empty (N): Counts empty slots in the buffer.
- full (0): Counts produced items available for consumption.

## Observation
The producer waits when the buffer is full, while the consumer waits when the buffer is empty, ensuring proper synchronization and preventing buffer overflows.

---

# Practical Session 3: Semaphore Implementation in C

## Objective
Compare mutex locks and semaphores for protecting shared resources.

## Files
- mutex_counter.c
- semaphore_counter.c
- counting_semaphore.c

## Comparison
Mutexes provide simple mutual exclusion by allowing only one thread to access a critical section at a time.

Binary semaphores can also be used for mutual exclusion, while counting semaphores are more flexible because they allow multiple threads to access a limited number of resources simultaneously.

Counting semaphores are useful in resource pools such as printers, databases, and connection pools.

---

# Practical Session 4: Shared Memory Programming

## Objective
Implement inter-process communication using shared memory.

## Steps Performed
1. Created a shared memory segment using `shmget()`.
2. Attached memory using `shmat()` in both parent and child processes.
3. Wrote data from one process and read it from another.
4. Used semaphores to synchronize access to shared memory.
5. Cleaned up using `shmdt()` and `shmctl(IPC_RMID)`.

## Applications
Shared memory is commonly used in database servers, web servers, scientific computing, and real-time systems.# Operating-System-Practicals
