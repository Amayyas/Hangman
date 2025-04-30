/*
** EPITECH PROJECT, 2025
** struct
** File description:
** struct
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct node_s {
    char *name;
    int idx;
    struct node_s *next;
} node_t;

#endif
