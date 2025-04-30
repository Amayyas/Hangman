/*
** EPITECH PROJECT, 2025
** hangman game
** File description:
** Main file for hangman game
*/

#include "my.h"

static void display_invalid_file_error(void)
{
    if (fprintf(stderr, "Invalid file\n") < 0)
        exit(84);
}

static int has_spaces(const char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] == ' ')
            return 1;
    return 0;
}

static void clean_up(FILE *file, char *line)
{
    free(line);
    fclose(file);
}

static int verify_file_content(const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        exit(84);
    while (getline(&line, &len, file) != -1) {
        if (line == NULL || has_spaces(line)) {
            display_invalid_file_error();
            clean_up(file, line);
            exit(84);
        }
    }
    clean_up(file, line);
    return 0;
}

static int validate_tries_count(const char *tries_arg)
{
    int tries_count = atoi(tries_arg);

    if (tries_count == 0 && strcmp(tries_arg, "0") != 0) {
        if (fprintf(stderr, "Invalid value\n") < 0)
            exit(84);
        return 84;
    }
    if (tries_count < 0) {
        if (fprintf(stderr, "number must be positive\n") < 0)
            exit(84);
        return 84;
    }
    return 0;
}

static int verify_arguments(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return 84;
    if (argc == 3)
        return validate_tries_count(argv[2]);
    return 0;
}

int main(int argc, char **argv)
{
    if (verify_arguments(argc, argv) == 84)
        return 84;
    verify_file_content(argv[1]);
    process_game(argc, argv);
    return 0;
}
