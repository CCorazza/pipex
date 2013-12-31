/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcourtin <vcourtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 02:14:50 by vcourtin          #+#    #+#             */
/*   Updated: 2013/11/29 02:14:52 by vcourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		countstring(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int		countletters(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char		*createstring(int size)
{
	char	*str;

	str = (char *)malloc(size);
	return (str);
}

static int		ft_strsplit_part2(char **tbl, int i2, char const *s, char c)
{
	int		i;
	int		i3;

	i = 0;
	i3 = 0;
	while (s[i] != '\0')
	{		
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tbl[i2 + 1] = createstring(countletters(s, c));
			tbl[i2++][i3++] = s[i++];
			tbl[i2 - 1][i3] = '\0';
			i3 = 0;

		}
		else if (s[i] != c)
			tbl[i2][i3++] = s[i++];
		else if (s[i] == c)
			i++;
	}
	return (i2);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i2;
	char	**tbl;

	i2 = 0;
	tbl = (char **)malloc(countstring(s, c) + 1);
	tbl[0] = createstring(countletters(s, c));
	i2 = ft_strsplit_part2(tbl, i2, s, c);
	tbl[i2] = '\0';
	return (tbl);
}

