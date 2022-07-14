/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

void dele(info_t *info)
{
    if (remove(info->arg) == 0)
        print_c(info->sClient, "250 Requested file action okay, completed.");
    else
        print_c(info->sClient, "550 Requested action not taken.");
}
