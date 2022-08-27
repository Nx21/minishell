
#include "minishell.h"

int	ft_isdigit(int str)
{
	if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}

int	is_numeric(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int     how_many_arg(char **str)
{
   int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int    ft_exit(char **str)
{
	printf("exit\n");
	if (how_many_arg(str) < 2)
		exit (0);
    else if (how_many_arg(str) > 2)
        printf("too many arguments \n");
	else if (!is_numeric(str[1]))
	{
		printf("%s: numeric argument required\n", str[1]);
		exit(1);
	}
    return (0);
}




int main()
{
    char *tmp[] = {"exit","5", NULL};
    ft_exit(tmp);
}
    