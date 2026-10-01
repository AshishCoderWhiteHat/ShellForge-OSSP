#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/shell.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"

int main(void)
{
    char *line;
    char **tokens;

    printf("=====================================\n");
    printf("ShellForge Version 5.0\n");
    printf("=====================================\n");

    while (1) {
        printf("myshell> ");
        line = read_line();

        /* If EOF or empty input */
        if (line == NULL) {
            break;
        }

        tokens = parse_line(line);

        /* Only proceed if a command was actually entered */
        if (tokens[0] != NULL) {
            /* If it is not a built-in command, run it as an external process */
            if (execute_builtin(tokens) == 0) {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");
    return 0;
}
