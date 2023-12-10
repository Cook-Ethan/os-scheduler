/*
 * COMP 3500: Project 5 Scheduling
 * Ethan Cook
 * November, 2023
 * 
 * taskbuilder.c: builds task_list array from task_list_file.
 * 
 * Arguments:
 *          char *task_list_file: name of file with task list. (input)
 *          u_int *task_count: pointer to number of tasks in the file. (output)
 *          task_t task_list: list of tasks in the file. (output)
 */

#include "taskbuilder.h"

int build_task_list(char *task_list_file, u_int *task_count, task_t task_list[MAX_TASK_NUM]) {
    FILE *fp;
    u_int i;
    u_int count;

    /* Open task list file */
    if (!(fp = fopen(task_list_file, "r"))) {
        printf("File %s cannot be opened. Please retry ...\n", task_list_file);
        return EXIT_FAILURE;
    }

    /* Read task list file */
    count = 0;
    while (fscanf(fp, "%u %u %u", &task_list[count].pid, &task_list[count].arrival_time, &task_list[count].burst_time) != EOF) {
        count++;
    }
    *task_count = count;

    printf("There are %u tasks loaded from \"%s\". ", count, task_list_file);

    printf("Press any key to continue ...\n");
    getchar();

    fclose(fp);
    return EXIT_SUCCESS;
}