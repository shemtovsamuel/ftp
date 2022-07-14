/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

void pwd(info_t *info)
{
    char pwd[256];

    getcwd(pwd, sizeof(pwd));
    write(info->sClient, "257 ", strlen("257 "));
    write(info->sClient, pwd, strlen(pwd));
    print_c(info->sClient, " created.");
}
