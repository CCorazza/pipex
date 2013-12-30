/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:13:27 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 14:13:44 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			count;

	count = 0;
	str = (unsigned char *)b;
	while (count < len)
	{
		str[count] = (unsigned char)c;
		count++;
	}
	return (b);
}
