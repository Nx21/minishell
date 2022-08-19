#include "minishell.h"

int check_error(char *str)
{
    int i;

    i = 0;
    while (str[i++] == ' ')
    if (str[i] == '|' || str[i] == '&')
        return(0);
    while(str[i])
    {
        if (str[i] == '|' || str[i] == '&')
            return(check_error(str + i));
    }
    return(1);
}