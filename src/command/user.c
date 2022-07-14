/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

info_t *user(info_t *info)
{
    if (info->auth == true) {
        print_c(info->sClient, "501 reauthentification not supported.");
        return info;
    }
    print_c(info->sClient, "331 User name okay, need password.");
    strcpy(info->user, info->arg);
    return info;
}
