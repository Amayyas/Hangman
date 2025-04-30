/*
** EPITECH PROJECT, 2025
** linked_list
** File description:
** linked_list
*/

#include "my.h"

node_t *create_node(char *name, int idx)
{
    node_t *nw_node = NULL;

    if (!name)
        return NULL;
    nw_node = malloc(sizeof(node_t));
    if (!nw_node)
        return NULL;
    nw_node->name = strdup(name);
    nw_node->idx = idx;
    nw_node->next = NULL;
    return nw_node;
}

void add_node(node_t **head, char *name, int idx)
{
    node_t *nw_node = NULL;

    if (!name)
        return;
    if (!(*head)) {
        (*head) = create_node(name, idx);
        return;
    }
    nw_node = create_node(name, idx);
    nw_node->next = (*head);
    (*head) = nw_node;
}

void show_list(node_t *head)
{
    node_t *offset = head;

    while (offset) {
        printf("name :%s\n", offset->name);
        offset = offset->next;
    }
}

int count_words(node_t *head)
{
    node_t *offset = head;
    int count = 0;

    if (!head || !offset)
        return 0;
    while (offset) {
        count++;
        offset = offset->next;
    }
    return count;
}

void free_list(node_t *list)
{
    if (!list)
        return;
    while (list) {
        if (list->name)
            free(list->name);
        list = list->next;
    }
    free(list);
}
