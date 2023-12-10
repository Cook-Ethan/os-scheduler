/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * policies.h: header file for policies.c
 */

#ifndef _POLICIES_H_
#define _POLICIES_H_

#include <stdio.h>
#include <stdlib.h>

#include "types.h"

task_t *queue[MAX_TASK_NUM];



void init_policy(policy_t policy, int quantum);
void enqueue_policy(task_t *task);
task_t* peek_policy();
void dequeue_policy();


#endif