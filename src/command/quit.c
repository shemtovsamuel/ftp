/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

info_t *quit(info_t *info)
{
    print_c(info->sClient, "221 Service closing control connection.");
    shutdown(info->sClient, SHUT_RDWR);
    close(info->sClient);
    return info;
}
