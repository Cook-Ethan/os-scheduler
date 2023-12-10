/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * cmdparser.h: a header file for cmdparser.c
*/

#ifndef _CMDPARSER_H_
#define _CMDPARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"

int parse_command(int argc, char *argv[], char **filename, policy_t *policy, int *quantum);

#endif