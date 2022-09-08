
#include <stdio.h>
#include <stdlib.h>
// int	ft_strlen(char *str)
// {
// 	int	len;

// 	if(!str)
// 		return 0;
// 	len = 0;
// 	while(str && str[len])
// 		len++;
// 	return (len);	
// }
// int    ft_strcmp(char *str1, char *str2)
// {
//     size_t            i;
//     unsigned char    *s1;
//     unsigned char    *s2;

//     s1 = (unsigned char *)str1;
//     s2 = (unsigned char *)str2;
//     i = 0;
//     while (s1[i] || s2[i])
//     {
//         if (s1[i] != s2[i])
//             return (s1[i] - s2[i]);
//         i++;
//     }
//     return (0);
// }
// char	*ft_strdup(char *src)
// {
// 	int		l;
// 	char	*cpy;
// 	int		i;

// 	if(!src)
// 		return NULL;
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
// char	*ft_join(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		len1;
// 	int		len2;

// 	len1 = ft_strlen(s1);
// 	len2 = ft_strlen(s2);
// 	str = (char *)malloc(len1 + len2 + 1);
// 	i = 0;
// 	while (s1 && s1[i])
// 	{
// 		str[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 && s2[i - len1])
// 	{
// 		str[i] = s2[i - len1];
// 		i++;
// 	}
// 	if(s1)
// 		free(s1);
// 	str[i] = 0;
// 	return (str);
// }
// char	*ft_substr(char *s, int start, int len)
// {
// 	char	*ptr;
// 	int	i;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	else if (ft_strlen(s) < len)
// 		ptr = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
// 	else
// 		ptr = (char *)malloc(sizeof(char) * len + 1);
// 	if (!ptr)
// 		return (NULL);
// 	while (s[start] && i < len)
// 	{
// 		ptr[i] = s[start];
// 		i++;
// 		start++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
  struct stat info;

  if (stat("test.py", &info) != 0)
    perror("stat() error");
  else {
    puts("stat() returned the following information about root f/s:");
    printf("  inode:   %d\n",   (int) info.st_flags);
    printf(" dev id:   %d\n",   (int) info.st_dev);
    printf("   mode:   %08x\n",       info.st_mode);
    printf("  links:   %d\n",         info.st_nlink);
    printf("    uid:   %d\n",   (int) info.st_uid);
    printf("    gid:   %d\n",   (int) info.st_gid);
  }
}
