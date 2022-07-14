/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../../include/my.h"

void port(info_t *info)
{
    if (str_is_digit(info->arg) == true && strlen(info->arg) > 0)
        print_c(info->sClient, "200 Command okay.");
    else
        print_c(info->sClient, "555 Wrong arguments.");
}
