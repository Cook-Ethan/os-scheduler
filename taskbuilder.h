/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * taskbuilder.h: header file to taskbuilder.c
*/

#ifndef _TASKBUILDER_H_
#define _TASK_BUILDER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

int build_task_list(char *task_list_file, u_int *task_count, task_t task_list[MAX_TASK_NUM]);

#endif