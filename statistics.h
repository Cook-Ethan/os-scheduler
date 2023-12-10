/*
 * COMP 3500: Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * statistics.h: a header file for statistics.c
 */

#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "types.h"

int compute_stats(task_t task_list[], u_int task_size, stats_t *stat_info);

int print_stats(stats_t stat_info);

#endif