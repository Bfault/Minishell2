/*
** EPITECH PROJECT, 2019
** PSU_minishell_2019
** File description:
** mysh.h
*/

#ifndef _MYSH_H_
#define _MYSH_H_

#define SIGHUP  1   /* Hangup the process       */ 
#define SIGINT  2   /* Interrupt the process    */ 
#define SIGQUIT 3   /* Quit the process         */ 
#define SIGILL  4   /* Illegal instruction.     */ 
#define SIGTRAP 5   /* Trace trap.              */ 
#define SIGABRT 6   /* Abort.                   */

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef void (*sighandler_t)(int);

typedef struct env
{
    char *name;
    char *value;
    struct env *next;
} env_t;

typedef struct prompt
{
    char *hostname;
    char *pwd;
    char *user;
} prompt_t;

typedef struct cargo
{
    int led;
    char **envp;
    env_t *env_list;
    prompt_t *prompt;
} cargo_t;

void    draw_prompt         (cargo_t *);
int     engine_process      (cargo_t *, char *);
void    fill_env            (cargo_t *);
void    copy_env            (cargo_t *, char **);
void    update_env          (cargo_t *);
void    print_env           (env_t **, int *);
int     env_len             (env_t **);
void    env_free            (env_t **);
env_t * env_create          (char *, char *);
env_t * env_append          (env_t **, char *, char *, int);
env_t * env_rm              (env_t **, int);
char *  env_getvalue        (env_t **, int);
int     env_getpos          (env_t **, char *);
void    env_modify          (env_t **, char *, int);
int     command_builtin     (cargo_t *, char **);
int     command_exec        (cargo_t *, char **);
void    command_cd          (cargo_t *, char **);
char ** parse_path          (cargo_t *);
void    free_cell           (env_t *);
void    free_my_child       (char **, char *, char **);
void    free_all            (cargo_t *, char *);
int     display_msg         (int , char *);
char *  get_home            (env_t *);
void    check_segfault      (int);
int     check_exec_error    (char *);
void    display_cd_error    (cargo_t *, char *);

#endif