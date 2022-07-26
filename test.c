#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <string.h>


int main() {
    while (1) {
        char *buf;
        buf = readline("minishell-1.0$ ");
        printf("Length of string a = %lu",strlen(buf));
        if (!buf[0])
            return 0;

        free(buf);
    }
}