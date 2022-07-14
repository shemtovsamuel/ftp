/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

void cdup(info_t *s)
{
    if (chdir("..") == 0)
        print_c(s->sClient, "250 Requested file action okay, completed.");
    else
        print_c(s->sClient, "550 Requested action not taken.");
}
