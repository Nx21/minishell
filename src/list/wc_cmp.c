/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 01:08:53 by nhanafi           #+#    #+#             */
/*   Updated: 2022/09/03 07:23:22 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

char	*wc_substr(char *s, int start, int len)
{
	char	*ptr;
	int	i;
	int j = 0;
	char c = 0;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[start + j] &&  j < len)
	{
		if(c == s[start + j])
			c = 0;
		else if(!c && (s[start + j] == '\'' || s[start + j] == '\"'))
			c = s[start + j];
		else
			ptr[i++] = s[start + j];
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int 	wc_strchr(char *s, char ch)
{
	int i = 0;
	char c= 0;

	while(s[i])
	{
		if(c == s[i])
			c = 0;
		else if(s[i] == '\'' || s[i] == '\"')
			c = s[i];
		else if(!c && s[i] == ch)
			return i;
		i++;
	}
	return i;
}

int	wc_cmpf(char **s1, char **s2)
{
	char c = 0;

	while(**s2 && (c || **s2 != '*'))
	{
		if(c == **s2)
			c = 0;
		else if(**s2 == '\'' || **s2 == '\"')
			c = **s2;
		else if(**s1 != **s2)
			return 1;
		else
			(*s1)++;
		(*s2)++;
	}
	if(!**s2)
	{
		if(**s1)
			return 1;
		return 2;
	}
	return 0;
}

int wc_cmpl(char *s1, char *s2)
{
	char c;

	c = 0;
	while (*s1)
		s1++;
	s2--;
	s1--;
	while(*s2 && (c || *s2 != '*'))
	{
		if(c == *s2)
			c = 0;
		else if(*s2 == '\'' || *s2 == '\"')
			c = *s2;
		else if(*s1 != *s2)
			return 0;
		else
			s1--;
		s2--;
	}
	return 1;
}

int wc_cmp(char *s1, char *s2)
{
	int	i;
	int	len;
	char *tmp;

	i = wc_cmpf(&s1,&s2);
	if(i)
		return i - 1;
	while(*(s2))
	{
		if(*s2 != '*')
		{
			len = wc_strchr(s2, '*');
			tmp = wc_substr(s2, 0 , len);
			i = 0;
			s1 = ft_strstr(s1, tmp);
			free(tmp);
			if(!s1)
				return 0;
			s2 += len - 1; 
		}
		s2++;
	}
	return wc_cmpl(s1,s2);
}