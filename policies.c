/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * policies.h: sets up ready queue depending upon policy
 * 
 * init_policy
 * Arguments:
 *          policy_t policy: the policy to use. (input)
 *          int quantum: the quantum number to use. (input)
 * 
 * enqueue_policy: adds a task to the ready queue.
 * Arguments:
 *          task_t *task: a pointer to the task to add to the ready queue. (input)
 * 
 * fcfs_sort: sorts the ready queue based on FCFS
 * Arguments:
 *          none.
 * 
 * rr_sort: sorts the ready queue based on RR.
 * Arguments:
 *          none.
 * 
 * srtf_sort: sorts the ready queue based on SRTF.
 * Arguments:
 *          none.
 * 
 * peek_policy: returns the first task in the sorted ready queue.
 * Arguments:
 *          none.
 * 
 * dequeue_policy: deleted the first task in the ready queue.
 * Arguments:
 *          none.
 */

#include "policies.h"

policy_t p;
int q;
int size;
int q_i;

void init_policy(policy_t policy, int quantum) {
    p = policy;
    q = quantum;
    
    size = -1;
    q_i = 0;
}

void enqueue_policy(task_t *task) {
    size++;
    queue[size] = task;
}

void fcfs_sort() {
    return;
}

void rr_sort() {
    if (q_i - q == 0) {
        enqueue_policy(queue[0]);
        dequeue_policy();
        q_i = 0;
    }
    q_i++;
}

void srtf_sort() {
    u_int shortest_remaining_time = (*queue[0]).remaining_time;
    task_t *temp;
    int index = 0;
    int i;
    for (i = 1; i < size+1; i++) {
        if ((*queue[i]).remaining_time < shortest_remaining_time) {
            shortest_remaining_time = (*queue[i]).remaining_time;
            index = i;
        }
    }
    temp = queue[0];
    queue[0] = queue[index];
    queue[index] = temp;
}

task_t* peek_policy() {
    if (size < 0)
        return NULL;

    switch (p)
    {
    case FCFS:
        fcfs_sort();
        break;
    
    case RR:
        rr_sort();
        break;

    case SRTF:
        srtf_sort();
        break;

    default:
        break;
    }

    return queue[0];
}

void dequeue_policy() {
    int i;
    for (i = 0; i < size; i++)
        queue[i] = queue[i+1];

    q_i = 0;
    size--;
}