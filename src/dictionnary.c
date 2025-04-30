/*
** EPITECH PROJECT, 2025
** dictionnary
** File description:
** dictionnary
*/

#include "my.h"

node_t *create_dictionary(char *filename)
{
    FILE *fd = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    int idx = 0;
    node_t *dest = NULL;

    if (!fd)
        exit(84);
    while (getline(&line, &len, fd) != -1) {
        if (!line)
            exit(84);
        add_node(&dest, line, idx);
        idx++;
    }
    return dest;
}

char *choose_word(node_t *head)
{
    node_t *dictionary = head;
    int len = 0;
    int idx = 0;
    char *name = NULL;

    if (!dictionary)
        return NULL;
    len = count_words(dictionary);
    idx = rand() % len;
    if (idx < 0)
        exit(84);
    while (dictionary) {
        if (dictionary->idx == idx) {
            name = strdup(dictionary->name);
            free_list(head);
            return name;
        }
        dictionary = dictionary->next;
    }
    return NULL;
}
