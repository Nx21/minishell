#include "./include/utils.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int			i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char    **get_path(char **s)
{
    char *str;
    char **paths;

    while(ft_strncmp("PATH", *s, 4))
        s++;
        str = (*s+5);
    paths = ft_split(str,':');
    return(paths);
}
char		*get_command(char **paths, char *command)
{
	char	*join_path;
	char	*get;
	int		res;
	while(*paths)
	{
		join_path = ft_join(*paths,"/");
		get = ft_join(join_path,command);
		// free(join_path);
		res = access(get,X_OK);
		if(!res)
			break;
		// free(get);
		paths++;
	}
	if(*paths == NULL)
		return(0);
	return(get);
}

#include<stdio.h>
int main(int ac, char **av, char **env)
{ 
	(void)av;
	(void)ac;
    char **path = get_path(env);
    char *cmd = get_command(path,"ca");
	printf("%s\n",cmd);
}