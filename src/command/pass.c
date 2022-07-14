/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

info_t *pass(info_t *info)
{
    if (info->auth == true) {
        print_c(info->sClient, "501 reauthentification not supported.");
        return info;
    }
    if ((strcmp(info->arg, "") == 0) && ((strcmp(info->user, "Anonymous") == 0))) {
        print_c(info->sClient, "230 User logged in, proceed.");
        strcpy(info->pass, "");
        info->auth = true;
        return info;
    }
    if (strcmp(info->user, "") == 0) {
        print_c(info->sClient, "332 Need account for login.");
        return info;
    }
    print_c(info->sClient, "530 Not logged in.");
    return info;
}
