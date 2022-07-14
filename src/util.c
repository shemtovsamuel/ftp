/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

void print_c(int sClient, char *str)
{
    write(sClient, str, strlen(str));
    write(sClient, "\r\n", 2);
}

info_t *reset_command(info_t *info)
{
    for (int i = 0; i < 10; i++)
        info->command[i] = '\0';
    for (int i = 0; i < 200; i++)
        info->arg[i] = '\0';
    return info;
}

bool str_is_digit(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (isdigit(str[i]) == 0)
            return false;
    return true;
}
