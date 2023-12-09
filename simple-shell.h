#ifndef SIMPLE-SHELL_H
#define SIMPLE-SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <dirent.h>
#include <math.h>

#define READ_B_SIZE 1024
#define WRITE_B_SIZE 1024
#define B_FLUSH -1
#define R_FLAG 0
#define O_FLAG 1
#define A_FLAG 2
#define C_FLAG 3
#define MAXIMUM_COUNT 100
#define CVT_LOWER 1
#define CVT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HISTORY_NAME ".simple-shell_history"
#define HISTORY_MAX 4096
#define SETTING_INFO				       \
{							\
NULL, NULL, NULL, 0, 0, 0, 0,		\
NULL, NULL, NULL, NULL, NULL,		\
0, 0, NULL, 0, 0, 0				\
}

extern char **environment;

/**
* ListNode - a singly linked list
* @nom: field of numbers
* @str: a string
* @nxt: pointer to the next node
*/
typedef struct ListNode
{
int nom;
char *str;
struct ListNode *nxt;
} list_s;

/**
* InformationNode - function that has arguments for a pointer
* @arg: argument
* @argv: argument string
* @argc: number of arguments
* @paths: the path of the command
* @err_nom: number of errors
* @err_code: the error code
* @history_lines: lines in the history
* @program_name: the programs name
* @flag: checks whether the line is conted or not
* @environment: variables in environent
* @envt: copy of the environment
* @history: history
* @status: status
* @changed_envt: show whether environment is changed
* @s_buffer: pointer to buffer
* @s_buffer_type: type of command
* @desc: descriptor for reading lines
*/
typedef struct InformationNode
{
char *arg;
char *paths;
char **argv;
int argc;
int flag;
size_t err_nom;
int err_code;
int history_lines;
char **s_buffer:
int s_buffer_type;
int desc;
int status;
char **envt;
int changed_envt;
char *program_name;
list_s *environment;
list_s *history;
list_s *alias;
} info_s;

/**
* built-in - function that has builtin strings
* @type: flag
* @funct: function
*/
typedef struct built-in
{
char *type;
int (*funct)(info_s*);
} builtin_commands;
#endif 
