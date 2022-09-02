/**
 * @file ui.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief source file for menu
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <ctype.h>

#include "../include/data.h"


extern struct planlist todos[SIZE];

extern unsigned char length;


/**
 * @brief show the options of app
 * 
 * @return char :the choice of user
 */
char show_options(void)
{
    char choice;
    printf("Type 'A' to add, 'D' to delete & 'C' to mark complete or 'Q' to quit\n>>");
    choice = getchar();
    getchar();
    choice = toupper(choice);
    return choice;
}


/**
 * @brief show the menu of app
 * 
 */
void print_todos_info(void)
{
    puts("+----+-------------------------------------+--------------+-------------+");
    puts("| ID |               Plans                 |  Created at  |  Completed  |");
    puts("+----+-------------------------------------+--------------+-------------+");

    for (unsigned char i = 0; i < length; ++i) {
        if (todos[i].is_completed)
            printf("\033[38;5;83m");
        else
            printf("\033[38;5;196m");
        printf("|%3d | %-35s | %-12s | %-12s |\n", i + 1, todos[i].plans, todos[i].create_time,
               (!todos[i].is_completed) ? " ❌  No  " : " ✅  Yes ");
        printf("\033[38;5;226m");
        puts("+----+-------------------------------------+--------------+-------------+");
    }
}