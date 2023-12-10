/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * Notes:
 * Apart from C documentation and Dr. Xiao Qin's sample source code, I used no outside help to complete this project.
 * This project took me a long time to finish, so I am emotionally attached to it. Just thought you should know.
 * 
 * scheduler.c: a simulation of a CPU scheduler that selects a job according to a given scheduling policy.
 * 
 * Compilation: In order to compile this project, the make command must be run in the path this file is in.
 * 
 * Command line usage: "./scheduler <task_list_file> [FCFS|RR|SRTF] [time_quantum]"
 * 
 * Task Information and input file:
 * task_list_file must be in the format "pid arrival_time burst_time"
 *      All fields are integer type where
 *          -pid is a unique numeric process ID
 *          -arrival_time is the time instance at which a task arrives
 *          -burst_time is the CPU time requested by a task
 *      The unit of arrival_time and burst_time is milliseconds.
 * 
 * Scheduling policies:
 *          First Come, First Serve (FCFS)
 *          Round Robin (RR)
 *          Shortest Remaining Time First (SRTF)
 * 
 * Policies can be added or modified in policies.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "cmdparser.h"
#include "taskbuilder.h"
#include "coordinator.h"
#include "statistics.h"


int main (int argc, char *argv[]) {
    char *task_list_file;
    task_t task_list[MAX_TASK_NUM];
    policy_t policy;
    int quantum;
    stats_t stat_info;

    int error_code;
    u_int task_size;

    error_code = parse_command(argc, argv, &task_list_file, &policy, &quantum);
    if (error_code != 0)
        return EXIT_FAILURE;

    error_code = build_task_list(task_list_file, &task_size, task_list);
    if (error_code != 0)
        return EXIT_FAILURE;

    printf("================================================\n");

    error_code = coordinate(task_list, task_size, policy, quantum);
    if (error_code != 0)
        return EXIT_FAILURE;

    printf("================================================\n");
    

    error_code = compute_stats(task_list, task_size, &stat_info);
    if (error_code != 0)
        return EXIT_FAILURE;

    error_code = print_stats(stat_info);
    if (error_code != 0)
        return EXIT_FAILURE;

    printf("================================================\n");

    return EXIT_SUCCESS;
}