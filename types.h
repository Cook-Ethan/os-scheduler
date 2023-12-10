/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * types.h: declares types needed for scheduling.
 * 
 * MAX_TASK_NUM: maximum number of tasks able to schedule.
 * 
 * u_int: unsigned integer.
 * 
 * task_t: task datatype.
 * 
 * policy_t: policy datatype.
 * 
 * stats_t: stats datatype.
 */

#ifndef _TYPES_H_
#define _TYPES_H_

#define MAX_TASK_NUM 64

typedef unsigned int u_int;

typedef struct task {
    u_int pid;
    u_int arrival_time;
    u_int burst_time;
    u_int start_time;
    u_int remaining_time;
    u_int finish_time;
} task_t;

typedef enum policy {
    FCFS,
    RR,
    SRTF
} policy_t;

typedef struct stats {
    float avg_waiting_time;
    float avg_response_time;
    float avg_turnaround_time;
    float cpu_usage;
} stats_t;

#endif