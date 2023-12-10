/*
 * COMP 3500: Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * statistics.c: computes statistical information on a completed task list.
 * 
 * compute_stats
 * Arguments:
 *          task_t task_list[]: An array of completed tasks and their data. (input)
 *          u_int task_size: The size of task_list[]. (input)
 *          stats_t *stat_info: The computed stats info of a completed task list. (output)
 * 
 * print_stats
 * Arguments:
 *          stats_t *stat_info: The computed stats info of a completed task list. (input)
 */

#include "statistics.h"

int compute_stats(task_t task_list[], u_int task_size, stats_t *stat_info) {
    int i;
    u_int sim_end_time = 0;

    stat_info->avg_waiting_time = 0;
    stat_info->avg_response_time = 0;
    stat_info->avg_turnaround_time = 0;
    stat_info->cpu_usage = 0;

    for (i = 0; i < task_size; i++) {
        stat_info->avg_waiting_time += (task_list[i].finish_time - task_list[i].arrival_time - task_list[i].burst_time);
        stat_info->avg_response_time += (task_list[i].start_time - task_list[i].arrival_time);
        stat_info->avg_turnaround_time += (task_list[i].finish_time - task_list[i].arrival_time);
        stat_info->cpu_usage += (task_list[i].burst_time);
        if (sim_end_time < task_list[i].finish_time)
            sim_end_time = task_list[i].finish_time;
    }

    stat_info->avg_waiting_time = stat_info->avg_waiting_time / task_size;
    stat_info->avg_response_time = stat_info->avg_response_time / task_size;
    stat_info->avg_turnaround_time = stat_info->avg_turnaround_time / task_size;
    stat_info->cpu_usage = stat_info->cpu_usage / sim_end_time * 100;
    
    return EXIT_SUCCESS;
}

int print_stats(stats_t stat_info) {
    printf("Average waiting time: \t\t%.2f\n", stat_info.avg_waiting_time);
    printf("Average response time: \t\t%.2f\n", stat_info.avg_response_time);
    printf("Average turnaround time: \t%.2f\n", stat_info.avg_turnaround_time);
    printf("Overall CPU Usage: \t\t%.2f\%\n", stat_info.cpu_usage);

    return EXIT_SUCCESS;
}