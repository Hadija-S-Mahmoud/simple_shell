#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

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
#define INFO_SETTER				       \
{							\
NULL, NULL, NULL, 0, 0, 0, 0,		\
NULL, NULL, NULL, NULL, NULL,		\
0, 0, NULL, 0, 0, 0				\
}

extern char **envt;

/**
* struct ListNode - a singly linked list
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
* struct InformationNode - function that has arguments for a pointer
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
* @alias: node for alias
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
char **s_buffer;
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
* struct builtin - function that has builtin strings
* @type: flag
* @funct: function
*/
typedef struct builtin
{
char *type;
int (*funct)(info_s *);
} builtin_cmds;

int main_sshell(info_s *info, char **a);
int char_writer(char z, int fdesc);
int chars_writer(char *strng, int fdesc);
int str_lent(char *c);
int str_cmp(char *d1, char *d2);
int putchar_error(char);
int _putchar(char);
int _isalphanum(int);
int _atoi(char *);
int error_number(char *);
int exit_handlr(info_s *);
int cd_handlr(info_s *);
int help_handlr(info_s *);
int history_handlr(info_s *);
int alias_handlr(info_s *);
int get_line(info_s *, char **, size_t *);
int print_environment(info_s *);
int setenvt_checker(info_s *);
int unsetenvt_checker(info_s *);
int _unsetenvt(info_s *, char *);
int _setenvt(info_s *, char *, char *);
int builtin_handler(info_s *);
int hsh_loop(char **);
int freeb(void **);
int frm_term(info_s *);
int dec_printer(int, int);
int gather_environment(info_s *);
int hist_creator(info_s *info);
int hist_reader(info_s *info);
int hist_updater(info_s *info, char *buffr, int lncnt);
int hist_renum(info_s *info);
int deleting_node(list_s **, unsigned int);
int alias_changer(info_s *);
int v_changer(info_s *);
int string_changer(char**, char *);
int wrd_cnt(char *str, char *sep, unsigned int *array);
ssize_t node_index_getter(list_s *, list_s *);
ssize_t input_getter(info_s *);
size_t list_printer(const list_s *);
size_t list_lent(const list_s *);
size_t str_list_printer(const list_s *);
bool chain(info_s *info, char *buffr, size_t *h);
bool delimiter(char a, char *delimiters);
bool executable(info_s *, char *);
list_s *add_start_node(list_s **headr, const char *str, int nom);
list_s *add_end_node(list_s **headr, const char *str, int nom);
list_s *str_node_starter(list_s *, char *, char);
char *str_cat(char *, char *);
char *str_copy(char *, char *);
char *str_dup(const char *);
char *strn_copy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_char(char *, char);
char *memory_set(char *, char, unsigned int);
char *_getenvt(info_s *, const char *);
char *starter(const char *, const char *);
char *chars_dups(char *, int, int);
char *file_checker(info_s *info, char *pstr, char *cmnd);
char *base_changer(long int, int, int);
char *history_reading(info_s *info);
char **get_environment(info_s *);
char **str_towr(char *, char *);
char **vector_list(list_s *);
char *strd_up(const char *str);
char **string_splitter(char *str, char *sep, size_t *wrd_cnt);
void command_checker(info_s *);
void *real_loct(void *p, unsigned int sz_old, unsigned int sz_new);
void process_creator(info_s *);
void sigint_handler(int);
void info_clearer(info_s *);
void info_setter(info_s *, char **);
void fr_information(info_s *, int);
void fr_vector(char **);
void err_printer(info_s *, char *);
void comment_handler(char *);
void fr_list(list_s **);
void chain_checker(info_s *info, char *buffr, size_t *h,
size_t m, size_t lent);
void puts_error(char *);
void c_puts(char *);
void zero_setter(unsigned int *array, size_t sz);
void null_setter(char *array, size_t sz);
#endif
