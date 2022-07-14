/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

void cwd(info_t *info)
{
    if (chdir(info->arg) == 0) {
        print_c(info->sClient, "250 Requested file action okay, completed.");
        printf("Change working directory\n");
    }
    else
        print_c(info->sClient, "550 Requested action not taken.");
}
