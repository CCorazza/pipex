/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:58:18 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 21:41:36 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*str;

	c = 0;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (s[c] != '\0' && c < len)
	{
		str[c] = s[c + start];
		c++;
	}
	str[c] = '\0';
	return (str);
}
