/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:52:08 by rjaanit           #+#    #+#             */
/*   Updated: 2022/08/18 02:17:51 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check1(char const *str, char c)
{
	int		i;
	int		count;
	int		j;
    char    s;

	j = 0;
	i = 0;
	count = 0;
    s = 0;
	while (str[i] != '\0')
	{
        if(str[i] == s)
			s = 0;
		else if(!s && ft_instr("\"\'", str[i]) >= 0)
			s = str[i];
		else if(!s && ft_instr("(", str[i]) >= 0)
			s = str[i] + 1;
		if (str[i] != c && j == 0)
		{
			count++;
			j = 1;
		}
		if (!s && str[i] == c && j == 1)
			j = 0;
		i++;
	}
	return (count);
}

static int	check2(char const *str, char c)
{
	int		count;
    char    s;

	count = 0;
    s = 0;
	if (*str == c)
		str++;
	while (*str != '\0')
	{   
        if(!s && *str == c)
            break;
        if(*str == s)
			s = 0;
		else if(!s && ft_instr("\"\'", *str) >= 0)
			s = *str;
		else if(!s && ft_instr("(", *str) >= 0)
			s = *str + 1;
		count++;
		str++;
	}
	return (count);
}

char	*ft_free(int i, char **s)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**ptr;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	len = check1(s, c);
	ptr = (char **)malloc(sizeof(char *) * (check1(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		while (*s == c && *s)
			s++;
		j = check2(s, c);
		ptr[i] = ft_substr(s, 0, j);
		if (!ptr)
			ft_free(i, ptr);
		s = s + j;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}