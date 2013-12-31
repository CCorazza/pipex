/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
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

=======
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:11:26 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 21:40:32 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				d++;
		}
		i++;
	}
	return (d + 1);
}

static int	ft_letters(char const *s, char c)
{
	char	*str;

	str = ft_strchr(s, c);
	if (str == NULL)
		return (ft_strlen(s));
	return ((int)(str - s));
}

char		**ft_strsplit(char const *s, char c)
{
	t_split	spt;

	spt.i = 0;
	spt.d = 0;
	spt.tab = (char **)malloc(sizeof(char *) * (ft_words(s, c)));
	if (spt.tab == NULL)
		return (NULL);
	while (s[spt.i] != '\0')
	{
		if (s[spt.i] == c)
			spt.i++;
		else
		{
			spt.str = ft_strnew(ft_letters((s + spt.i), c));
			if (spt.str == NULL)
				return (NULL);
			ft_strncpy(spt.str, (s + spt.i), ft_letters((s + spt.i), c));
			spt.i += ft_letters((s + spt.i), c);
			spt.tab[spt.d] = spt.str;
			spt.d++;
		}
	}
	spt.tab[spt.d] = '\0';
	return (spt.tab);
}
>>>>>>> cbedb4133633e9e96172343805063eb18a989783
