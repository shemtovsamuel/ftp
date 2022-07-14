/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

int handle_client(info_t *info)
{
    char buf[256];
    int len = 0;

    print_c(info->sClient, "220 Service ready for new user.");
    while ((len = read(info->sClient, buf, sizeof(buf))) > 0) {
        write(1, buf, len);
        info = parthing(info, buf);
    }
    if (len == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
