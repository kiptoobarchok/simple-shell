#ifndef SHELL_H

#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024

extern char **environ;

/*Helper functions*/
void _puts(const char *str);
char *_getenv(const char *name);
size_t _strlen(const char *str);
char *_strdup(const char *str);
char *_strcpy(char *dst, const char *src);
int _strcmp(const char *str1, const char *str2);
char *_strcat(char *dest, const char *src);
int _putchar(char c);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strtok(char *str, const char *delim);
int _strncmp(const char *str1, const char *str2, size_t n);

/*other function declarations*/

char *search_path_for_executable(char **args, char *path);
char *get_environment_variable(const char *var);
void display_prompt(void);
char *read_input_line(void);
int is_whitespace(char character);
char **split_input_line(char *input_line);
int count_tokens(char *string);
char *find_executable_path(char **args, char *path_var);
int exec_builtin_command(char **args, char *input_line, int *last_exit_status);
int execute_external_command(char **args, char *full_path);
void display_environment_variables(void);
void run_shell(void);
void free_args(char **args);
int change_directory(char *new_dir);



#endif
