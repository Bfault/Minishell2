/*
** EPITECH PROJECT, 2019
** PSU_minishell_2019
** File description:
** main.c
*/

#include "mysh.h"

int display_msg(int flux, char *msg)
{
    my_fwr(flux, msg);
    if (flux == 2)
        return (0);
    return (1);
}

void print_exit(char *buffer)
{
    if (buffer == NULL || strc(buffer, "exit")) {
        my_fwr(1, "exit");
        my_fwr(1, "\n");
    }
}

int main(int ac, char **av, char **envp)
{
    cargo_t cg;
    char *buffer = prefix_del(word_array_to_str(av), "./mysh ");
    int arg = (ac > 1) ? 1 : 0;
    cg.led = 1;

    signal(SIGINT, SIG_IGN);
    cg.prompt = my_malloc(sizeof(prompt_t));
    copy_env(&cg, envp);
    update_env(&cg);
    do {
        if (!arg) draw_prompt(&cg);
        if (!arg || buffer == NULL) {
            free(buffer);
            buffer = get_stdin();
        }
        if (strc(buffer, "exit")) break;
        engine_process(&cg, buffer);
    } while (buffer != NULL && !arg);
    print_exit(buffer);
    free_all(&cg, buffer);
    return (0);
}