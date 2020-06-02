/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** prompt.c
*/

#include "mysh.h"
#include "my.h"

char *parsing_env(env_t *list, char *str)
{
    int pos = 0;

    pos = env_getpos(&list, str);
    if (pos != -1)
        return (env_getvalue(&list, pos));
    return ("[Error 404]");
}

void search_prompt(cargo_t *cg)
{
    char hostname[] = "HOSTNAME";
    char pwd[] = "PWD";
    char user[] = "USER";

    cg->prompt->hostname = parsing_env(cg->env_list, hostname);
    cg->prompt->pwd = parsing_env(cg->env_list, pwd);
    cg->prompt->user = parsing_env(cg->env_list, user);
}

void draw_prompt(cargo_t *cg)
{
    search_prompt(cg);
    my_fwr(1, "╭─");
    my_fwr(0, GREEN_BRIGHT);
    my_fwr(1, cg->prompt->user);
    my_fwr(1, "@");
    my_fwr(1, del_from(cg->prompt->hostname, "."));
    my_fwr(0, NORMAL_BRIGHT);
    my_fwr(1, " ");
    my_fwr(0, BLUE_BRIGHT);
    my_fwr(1, replace_in(cg->prompt->pwd, get_home(cg->env_list), "~"));
    cg->led ? my_fwr(0, GREEN_BRIGHT) : my_fwr(0, RED_BRIGHT);
    my_fwr(1, " ▲");
    my_fwr(0, YELLOW_BRIGHT);
    my_fwr(1, "▼");
    my_fwr(0, NORMAL_BRIGHT);
    my_fwr(1, "\n");
    my_fwr(1, "╰─$ ");
    cg->led = 1;
}