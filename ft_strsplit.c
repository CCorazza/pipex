/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
