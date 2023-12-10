/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * coordinator.h: a header file to coordinator.c
*/

#ifndef _COORDINATOR_H_
#define _COORDINATOR_H_

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "policies.h"

int coordinate(task_t task_list[], u_int task_size, policy_t policy, int quantum);

#endif