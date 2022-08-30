#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
typedef struct  s_var
{
	char *s;
	struct  s_var *next;
}t_var;


int	ft_strlen(char *str)
{
	int	len;

	if(!str)
		return 0;
	len = 0;
	while(str && str[len])
		len++;
	return (len);	
}

char    *ft_strstr(const char *str, const char *ch1)
{
    size_t    i;
    size_t    j;

    j = 0;
    i = 0;
    if (ch1[j] == '\0' )
        return ((char *)(str));
    while (str[i])
    {
        j = 0;
        while (ch1[j] && ch1[j] == str[i + j])
        {
            if (ch1[j + 1] == '\0' || ch1[j + 1] == '*')
                return ((char *) &str[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[i - len1])
	{
		str[i] = s2[i - len1];
		i++;
	}
	if(s1)
		// free(s1);
	str[i] = 0;
	return (str);
}
char	*ft_strdup(char *src)
{
	int		l;
	char	*cpy;
	int		i;

	i = 0;
	l = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * (l + 1));
	if (cpy == NULL)
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}


int wc_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(*s2 && *s2 != '*')
	{
		if(*s1 != *s2)
			return 0;
		s1++;
		s2++;
	}
	if(!*s2)
	{
		if(*s1)
			return 0;
		return 1;
	}
	while(*(s2))
	{
		if(*s2 != '*')
		{
			i = 0;
			s1 = ft_strstr(s1, s2);
			if(!s1)
				return 0;
		}
		s2++;
	}
	while (*s1)
		s1++;
	while(*s2 != '*')
	{
		if(*s1 != *s2)
			return 0;
		s2--;
		s1--;
	}
	return 1;
}

t_var *wc_creat(char *path, char *name)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->s = NULL;
	if (path && path[ft_strlen(path) - 1] != '/')
	{
		var->s = ft_join(path, "/");
		var->s = ft_join(var->s, name);
	}
	else
		var->s = ft_join(path, name);
	var->next = NULL;
	return var;
}

t_var *wc_append(t_var *head, t_var	*var)
{
	t_var *node;

	
	if(!head)
		return var;
	node = head;
	while(node->next)
		node = node->next;
	node->next = var; 
	return head;
}



t_var *wc_all(char *str, char *path)
{
	t_var *head;
	DIR *dp;
    struct dirent *dirp;

	head = NULL;
	dp = opendir(".");
	if(path)
		dp = opendir(path);
	if(!dp)
		return NULL;
	while ((dirp = readdir(dp)) != NULL)
	{
		if(dirp->d_name[0] != '.' && wc_cmp(dirp->d_name, str))
			head = wc_append(head, wc_creat(path, dirp->d_name));
	}
	// free(path);
	return head;
}

t_var *wc_dir(char *str, char *path)
{
	t_var *head;
	DIR *dp;
    struct dirent *dirp;

	head = NULL;
	dp = opendir(".");
	if(path)
		dp = opendir(path);
	if(!dp)
		return (NULL);
	while ((dirp = readdir(dp)) != NULL)
	{
		if(dirp->d_type == 4 && dirp->d_name[0] != '.' && wc_cmp(dirp->d_name, str))
			head = wc_append(head, wc_creat(path, dirp->d_name));
	}
	// free(path);
	return head;
}

char	*ft_substr(char *s, int start, int len)
{
	char	*ptr;
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	else if (ft_strlen(s) < len)
		ptr = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[start] && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}


t_var *wc_handler(char *str, char *path)
{
	int i;
	char	path_backup;
	t_var *head;
	t_var *node;
	t_var *sub;

	i = 0;
	sub = NULL;
	if(str && *str == '/')
		return wc_handler(str + 1, ft_join(path, "/"));
	while(str && str[i] && str[i] != '/')
		i++;
	if(!str[i])
	{
		printf("her %s    %s\n\n", path, str);
		// return NULL;
		return wc_all(str, path);
	}
	head = wc_dir(ft_substr(str , 0 , i), path);
	node = head;
	// if(path)
	// 	path = ft_join(path, "/");
	// if(*(str + i + 1))
	// 	printf("%s", str + i+ 1);

	while(node)
	{
		sub = wc_append(sub, wc_handler(str + i + 1, node->s));
		node = node->next;
	}
	// free(path);
	return sub;
}



int main(int argc, char *argv[])
{
	/* code */
	t_var *var;
	if(argc != 2)
		return 0;
	// var = wc_all("*" , "//");
	var = wc_handler((char *) argv[1], NULL);
	while(var)
	{
		printf("%s\n", var->s);
		var = var->next;
	}
	return 0;
}
