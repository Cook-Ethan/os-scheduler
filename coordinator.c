/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * coordinator.c: coordinates new scheduled tasks and scheduling policies
 * 
 * Arguments:
 *          task_t task_list[]: An array of tasks and its data. (input/output)
 *          u_int task_size: the size of task_list[]. (input)
 *          policy_t policy: the policy to use. (input)
 *          int quantum: the quantum number to use. (input)
 */

#include "coordinator.h"

int coordinate(task_t task_list[], u_int task_size, policy_t policy, int quantum) {
    init_policy(policy, quantum);

    task_t finish_task_list[MAX_TASK_NUM];
    task_t *running_task;

    int future_tasks_removed = 0;
    int finished_tasks_count = 0;
    int clock = 0;
    int i;

    while (finished_tasks_count != task_size) {
        for (i = future_tasks_removed; i < task_size; i++) {
            if (task_list[i].arrival_time > clock)
                break;
            task_list[i].remaining_time = task_list[i].burst_time;
            enqueue_policy(&task_list[i]);
            future_tasks_removed++;
        }

        if (future_tasks_removed > 0) {
            running_task = peek_policy();
            if (running_task == NULL) {
                printf("<time %d> idle\n", clock);
                clock++;
                continue;
            }
            printf("<time %d> process %u is running\n", clock, running_task->pid);

            if (running_task->remaining_time == running_task->burst_time)
                running_task->start_time = clock;

            running_task->remaining_time--;
            clock++;

            if (running_task->remaining_time == 0) {
                running_task->finish_time = clock;
                dequeue_policy();
                finish_task_list[finished_tasks_count++] = *running_task;
                printf("<time %d> process %u is finished...\n", clock, running_task->pid);
            }
        } else {
            clock++;
        }

        if (clock > 10000) {
            printf("Time expired ...\n");
            return EXIT_FAILURE;
        }
    }

    printf("<time %d> All processes finished.....\n", clock);

    return EXIT_SUCCESS;
}