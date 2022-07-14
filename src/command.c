/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

bool check_command(info_t *s)
{
    char *opts[] = {"USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "",
        "PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};

    for (int i = 0; i < 13; i++)
        if (strcmp(opts[i], s->command) == 0)
            return true;
    print_c(s->sClient, "500 Syntax error, command unrecognized.");
    return false;
}

info_t *command(info_t *info)
{
    if (check_command(info) == false)
        return info;
    info = cmp_command1(info);
    info = cmp_command2(info);
    info = cmp_command3(info);
    info = cmp_command4(info);
    return info;
}

info_t *execute_command(info_t *s)
{
    if (check_command(s) == false)
        return s;
    if (strcmp(s->command, "USER") != 0 && strcmp(s->command, "PASS") != 0
        && strcmp(s->command, "NOOP") != 0 && strcmp(s->command, "QUIT") != 0
        && strcmp(s->command, "HELP") != 0 && strcmp(s->command, "") != 0
        &&  s->auth == false)
        print_c(s->sClient, "530 Not logged in.");
    else
        s = command(s);
    return s;
}

info_t *parthing( info_t *info, char *str)
{
    info = reset_command(info);
    sscanf(str, "%[a-zA-Z] %[^\r\n]", info->command, info->arg);
    for (int i = 0; i < 256; i++)
        str[i] = '\0';
    info = execute_command(info);
    return info;
}
