/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:40:51 by nhanafi           #+#    #+#             */
/*   Updated: 2022/08/14 01:01:41 by nhanafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// char	*ft_strdup(char *src)
// {
// 	int		l;
// 	char	*cpy;
// 	int		i;

// 	i = 0;
// 	l = ft_strlen(src);
// 	cpy = (char *)malloc(sizeof(char) * (l + 1));
// 	if (cpy == NULL)
// 		return (NULL);
// 	while (src[i])
// 	{
// 		cpy[i] = src[i];
// 		i++;
// 	}
// 	cpy[i] = '\0';
// 	return (cpy);
// }

// char    *ft_substr(char *s, int start, int len)
// {
//     char   *ptr;
//     int    i;

//     if (!s)
//         return (NULL);
//     if(len == -1)
//         len = ft_strlen(s);
//     i = 0;
//     if (start > ft_strlen(s))
//         return (ft_strdup(""));
//     else if (ft_strlen(s) < len)
//         ptr = (char) malloc(sizeof(char) * ft_strlen(s) + 1);
//     else
//         ptr = (char )malloc(sizeof(char) len + 1);
//     if (!ptr)
//         return (NULL);
//     while (s[start] && i < len)
//     {
//         ptr[i] = s[start];
//         i++;
//         start++;
//     }
//     ptr[i] = '\0';
//     return (ptr);
// }