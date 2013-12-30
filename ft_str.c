/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 11:35:42 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 14:13:59 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	c;
	size_t	d;

	len = (ft_strlen(s1) + ft_strlen(s2));
	str = ft_strnew(len);
	c = 0;
	d = 0;
	if (str == NULL)
		return (NULL);
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	while (s2[d] != '\0')
	{
		str[c] = s2[d];
		c++;
		d++;
	}
	str[c] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*cpy;

	count = 0;
	cpy = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s1[count] != '\0')
	{
		cpy[count] = s1[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}

char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	c = (char)c;
	while (s[count] != '\0')
	{
		if (s[count] == c)
			return ((char *)s + count);
		count++;
	}
	if (c == '\0')
		return ((char *)s + count);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s != '\0')
	{
		s++;
		n++;
	}
	return (n);
}

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (size + 1));
	return (str);
}
