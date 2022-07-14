/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

info_t *cmp_command1(info_t *info)
{
    if (strcmp(info->command, "USER") == 0) {
        info = user(info);
        return info;
    }
    if (strcmp(info->command, "PASS") == 0) {
        info = pass(info);
        return info;
    }
    if (strcmp(info->command, "QUIT") == 0) {
        info = quit(info);
        return info;
    }
    return info;
}

info_t *cmp_command2(info_t *info)
{
    if (strcmp(info->command, "HELP") == 0) {
        help_cmd(info->sClient);
        return info;
    }
    if (strcmp(info->command, "NOOP") == 0) {
        noop(info);
        return info;
    }
    if (strcmp(info->command, "CWD") == 0) {
        cwd(info);
        return info;
    }
    return info;
}

info_t *cmp_command3(info_t *info)
{
    if (strcmp(info->command, "PWD") == 0) {
        pwd(info);
        return info;
    }
    if (strcmp(info->command, "DELE") == 0) {
        dele(info);
        return info;
    }
    if (strcmp(info->command, "CDUP") == 0) {
        cdup(info);
        return info;
    }
    return info;
}

info_t *cmp_command4(info_t *info)
{
    if (strcmp(info->command, "PASV") == 0) {
        pasv(info);
        return info;
    }
    if (strcmp(info->command, "PORT") == 0) {
        port(info);
        return info;
    }
    if (strcmp(info->command, "") == 0)
        return info;
    return info;
}
