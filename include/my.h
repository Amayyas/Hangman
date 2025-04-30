/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include "struct.h"

    #define ERROR 0
    #define WIN 1
    #define LOSS 2
    #define ASK_LETTER 3
    #define ERROR_INPUT "You must put only one character\n"
    #define WIN_MESSAGE "Congratulations!"
    #define LOSS_MESSAGE "You lost!"
    #define ASK_MESSAGE "Your letter: "

//linked_list
void add_node(node_t **head, char *name, int idx);
void show_list(node_t *head);
int count_words(node_t *head);
void free_list(node_t *list);

//file parsing
node_t *create_dictionary(char *filename);
char *choose_word(node_t *head);

//handman
void process_game(int ac, char **av);

#endif
