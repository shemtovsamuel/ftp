/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/select.h>

typedef struct info_s {
    char command[10];
    char arg[200];
    bool auth;
    int sClient;
    int port;
    char *path;
    char user[10];
    char pass[10];
} info_t;

bool str_is_digit(char *str);
bool check_command(info_t *info);
int check_args(int argc, char *argv[]);
int handle_client(info_t *info);
void print_c(int socketClient, char *str);
void help_cmd(int s);
void noop(info_t *info);
void pwd(info_t *info);
void cwd(info_t *info);
void dele(info_t *info);
void cdup(info_t *info);
void pasv(info_t *info);
void port(info_t *info);
info_t init_info(char *argv[]);
info_t init_command(void);
info_t *reset_command(info_t *info);
info_t *reset_command(info_t *info);
info_t *user(info_t *info);
info_t *pass(info_t *info);
info_t *quit(info_t *info);
info_t *cmp_command1(info_t *info);
info_t *cmp_command2(info_t *info);
info_t *cmp_command3(info_t *info);
info_t *cmp_command4(info_t *info);
info_t *command(info_t *info);
info_t *execute_command(info_t *info);
info_t *parthing( info_t *info, char *str);

#endif
