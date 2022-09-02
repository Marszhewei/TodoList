/**
 * @file data.h
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief define macro and data struct
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _DATA_H_
#define _DATA_H_

#include <stdbool.h>
#include <stdio.h>

#define SIZE 50

/* data struct of plans list */
struct planlist {
    char plans[SIZE];
    char create_time[SIZE];
    bool is_completed;
};

extern bool create_database(FILE *fp);

extern void operate(FILE *fp);

#endif
