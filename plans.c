/**
 * @file plans.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief todo list app
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <unistd.h>
#include <stdlib.h>

#include "include/data.h"

/* data structure for storing plans */
struct planlist todos[SIZE];

/* the number of plans */
unsigned char length = 0;

#define ERROR_EXIT -1

int main(int argc, char** argv)
{
    system("clear||@cls");
    printf("\033[38;5;226m");

    FILE *fp = NULL;
    if (access("database/db.bin", F_OK) == -1) {
        bool is_created = create_database(fp);
        if (!is_created) {
            puts("The todolist app is crash!");
            return ERROR_EXIT;
        }
    }
    operate(fp);
    
    return 0;
}