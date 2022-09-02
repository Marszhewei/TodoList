/**
 * @file frame.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief main frame of todolist app
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/data.h"
#include "../include/operate.h"
#include "../include/ui.h"

extern struct planlist todos[SIZE];

extern unsigned char length;


#define DATABASE_CORRUPTION false

/**
 * @brief read data from database
 * 
 * @param fp file point for database
 * @return true :read data successfully
 * @return false :failed to read data
 */
static bool read_from_database(FILE* fp)
{
    fp = fopen("database/db.bin", "rb");
    if (NULL != fp) {
        fseek(fp, 0L, SEEK_END);
        unsigned long int size = ftell(fp);
        fseek(fp, 0L, SEEK_SET);
        length = (unsigned char)(size / sizeof(struct planlist));

        for (unsigned char i = 0; i < length; ++i)
            fread(&todos[i], sizeof(struct planlist), 1, fp);
        fclose(fp);
    }
    else {
        puts("Maybe your database is corrupted!?");
        return DATABASE_CORRUPTION;
    }
    return true;
}


#define SAVE_ERROR false

/**
 * @brief save data to databse
 * 
 * @param fp file point for database
 */
static bool save_todo(FILE *fp)
{
    fp = fopen("database/db.bin", "wb");
    if (NULL == fp) {
        puts("Can't save your todo");
        return SAVE_ERROR;
    }
    else {
        for (unsigned char i = 0; i < length; ++i)
            fwrite(&todos[i], sizeof(struct planlist), 1, fp);
        fclose(fp);
        return true;
    }
}




/**
 * @brief create a database object
 * 
 * @param fp The file point for database
 * @return true :create successfully
 * @return false :failed to create
 */
bool create_database(FILE *fp)
{
    puts("This is your first time using todolist app");
    fp = fopen("database/db.bin", "wb");
    if (NULL == fp) {
        puts("Create database error");
        fclose(fp);
        return false;
    }
    fclose(fp);
    return true;
}



/**
 * @brief some base opreates in todolist app
 * 
 * @param fp the file point for database
 */
void operate(FILE *fp)
{
    bool is_read = read_from_database(fp);
    if (!is_read) {
        puts("The app is going down \n.......");
        exit_app();
    }
    print_todos_info();
    char choice = show_options();
    switch (choice) {
        case 'A':
            add_plan(); 
            break;
        case 'D':
            delete_plan();
            break;
        case 'C':
            complete_plan();
            break;
        case 'Q':
            exit_app();
            break;
        default:
            puts("Command not found 😓");
            break;
    }
    bool is_save =  save_todo(fp);
    if (!is_save) {
        puts("The app is going down \n.......");
        exit_app();
    }
    operate(fp);
}