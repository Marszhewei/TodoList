/**
 * @file operate.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief four main operate of app
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "../include/data.h"


extern struct planlist todos[SIZE];

extern unsigned char length;


/**
 * @brief add plans to the database
 * 
 */
void add_plan(void)
{
    char user_input[SIZE];
    printf("Type your todo \n >>");
    scanf("%[^\n]s", user_input);
    getchar();
    strncpy(todos[length].plans, user_input, SIZE);

    char todo_time[SIZE];
    struct tm at_time;
    time_t times = time(NULL);
    localtime_r(&times, &at_time);
    snprintf(todo_time, SIZE, "%i/%i %i:%i", at_time.tm_mday, at_time.tm_mon+1, 
             at_time.tm_hour, at_time.tm_min);
    strcpy(todos[length].create_time, todo_time);

    todos[length].is_completed = false;
    length++;
}


/**
 * @brief remove plans from the database
 * 
 */
void delete_plan(void)
{
    int todo_id;
    printf("Enter the ID of plans \n>>");
    scanf("%d", &todo_id);
    getchar();
    if (todo_id < 0 || todo_id > length)
        puts("Invalid todo id 😑");
    else {
        todo_id--;
        memmove(todos + todo_id, todos + todo_id + 1, (length - todo_id - 1) * sizeof(*todos));
        length--;
        puts("Your todo has been deleted 😵");
    }
}


/**
 * @brief mark the plans as complete
 * 
 */
void complete_plan(void)
{
    int todo_id;
    printf("Enter the ID of plans \n>>");
    scanf("%d", &todo_id);
    todo_id--;
    getchar();
    if (todo_id < 0 || todo_id > length)
        puts("Invalid todo id 😑");
    else {
        todos[todo_id].is_completed = true;
        puts("Plan is completed");
    }
}


/**
 * @brief exit app
 * 
 */
void exit_app(void)
{
    exit(0);
}