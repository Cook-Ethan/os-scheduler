/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * cmdparser.c: parses command line arguments.
 * 
 * Arguments:
 *          int argc: argument count. (intput)
 *          char *argv[]: argument list in the form: "scheduler <task_list_file> [FCFS|RR|SRTF] [time_quantum]". (input)
 *          char **filename: pointer to filename string. (output)
 *          policy_t *policy: pointer to policy to use. (output)
 *          int *quantum: pointer to quantum number to use. (output)
*/

#include "cmdparser.h"

int parse_command(int argc, char *argv[], char **filename, policy_t *policy, int *quantum) {
    if (argc == 1 || argc > 4) {
        printf("Usage: scheduler <task_list_file> [FCFS|RR|SRTF] [time_quantum]\n");
        return EXIT_FAILURE;
    }

    *filename = argv[1];

    if (strcmp(argv[2], "FCFS") == 0)
        *policy = FCFS;
    else if (strcmp(argv[2], "RR") == 0) {
        if (argc == 4) {
            *policy = RR;
            *quantum = atoi(argv[3]);
            if (*quantum <= 0) {
                printf("Time_quantum is invalid\n");
                return EXIT_FAILURE;
            }
        }
        else {
            printf("Please enter time_quantum for the RR policy!\n");
            return EXIT_FAILURE;
        }
    }
    else if (strcmp(argv[2], "SRTF") == 0)
        *policy = SRTF;
    else {
        printf("Sheduling policy not found\n");
        return EXIT_FAILURE;
    }

    printf("Scheduling policy: %s\n", argv[2]);

    return EXIT_SUCCESS;
}