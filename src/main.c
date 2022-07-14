/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Project
*/

#include "../include/my.h"

static int loop(info_t info, int socketServer)
{
    int sClient;

    while (1) {
        sClient = accept(socketServer, NULL, NULL);
        pid_t pid = fork();
        if (pid == 0 && sClient != -1) {
            info.sClient = sClient;
            return handle_client(&info);
        }
        if (pid == -1 && sClient != -1) {
            perror("fork");
            return EXIT_FAILURE;
        }
        if (sClient == -1 && pid == 0) {
            perror("accept");
            return EXIT_FAILURE;
        }
    }
}

static void check_listen(int socketServer)
{
    if (listen(socketServer, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

static int init_socket_server(int socketServer)
{
    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if (socketServer == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    return socketServer;
}

int main(int argc, char *argv[])
{
    struct sockaddr_in addr;
    int socketServer = 0;
    int return_value = 0;
    info_t info;

    if (check_args(argc, argv) == 84)
        return 84;
    info = init_info(argv);
    socketServer = init_socket_server(socketServer);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(info.port),
    addr.sin_addr.s_addr = 0;
    if (bind(socketServer, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }
    check_listen(socketServer);
    return_value = loop(info, socketServer);
    return return_value;
}
