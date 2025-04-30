/*
** EPITECH PROJECT, 2025
** handman
** File description:
** game
*/

#include "my.h"

void process_message(int signal)
{
    if (signal == ERROR) {
        if (fprintf(stderr, "%s\n", ERROR_INPUT) < 0)
            exit(84);
    }
    if (signal == WIN) {
        if (printf("%s\n", WIN_MESSAGE) < 0)
            exit(84);
    }
    if (signal == LOSS) {
        if (printf("%s\n", LOSS_MESSAGE) < 0)
            exit(84);
    }
    if (signal == ASK_LETTER) {
        if (printf("%s", ASK_MESSAGE) < 0)
            exit(84);
    }
}

bool process_error(char *line)
{
    if (strlen(line) > 2) {
        process_message(ERROR);
        return true;
    }
    return false;
}

void process_stdin(char *name, char *hide, int *tries)
{
    char *line = NULL;
    size_t len = 0;
    bool check = false;

    process_message(ASK_LETTER);
    if (getline(&line, &len, stdin) < 0)
        exit(84);
    if (process_error(line))
        return;
    for (int i = 0; name[i]; i++) {
        if (name[i] == line[0]) {
            hide[i] = name[i];
            check = true;
        }
    }
    if (check)
        return;
    if (printf("%c: is not in this word\n", line[0]) < 0)
        exit(84);
    *tries -= 1;
}

static void annunce_game(char *hide, int tries)
{
    if (printf("%s\nTries: %d\n\n", hide, tries) < 0)
        exit(84);
}

void process_handman(char *name, int tries)
{
    char *hide = strdup(name);

    if (!hide)
        exit(84);
    for (int i = 0; hide[i]; i++)
        hide[i] = '*';
    annunce_game(hide, tries);
    while (tries != 0) {
        process_stdin(name, hide, &tries);
        if (printf("%s\nTries: %d\n\n", hide, tries) < 0)
            exit(84);
        if (strcmp(name, hide) == 0) {
            process_message(WIN);
            return;
        }
    }
    process_message(LOSS);
}

void process_game(int ac, char **av)
{
    int tries = 10;
    node_t *dest = NULL;
    char *name = NULL;

    if (ac == 3) {
        tries = atoi(av[2]);
        if (tries == 0 && strcmp(av[2], "0") != 0)
            exit(84);
    }
    dest = create_dictionary(av[1]);
    if (!dest)
        exit(84);
    name = choose_word(dest);
    if (!name)
        exit(84);
    name[strlen(name) - 1] = '\0';
    process_handman(name, tries);
}
