/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

info_t init_info(char *argv[])
{
    info_t info = {
        .command = {0},
        .arg = {0},
        .auth = false,
        .sClient = 0,
        .port = atoi(argv[1]),
        .path = argv[2],
        .user = {0},
        .pass = {'a'},
        };
    return info;
}

void help(int argc, char *argv[])
{
    if (argc == 2 && strcmp("-help", argv[1]) == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport is the port number no which the server socket ");
        printf("listens\n\tpath is the path ");
        printf("to the home directory for the Anonymous user\n");
        exit(EXIT_SUCCESS);
    }
}

int check_args(int argc, char *argv[])
{
    help(argc, argv);
    if (argc != 3) {
        fprintf(stderr, "Wrongs arguments.\n");
        return 84;
    }
    if (atoi(argv[1]) <= 0) {
        fprintf(stderr, "Incorrect port.\n");
        return 84;
    }
    if (opendir(argv[2]) == NULL) {
        fprintf(stderr, "Incorrect path.\n");
        return 84;
    }
    return (0);
}
