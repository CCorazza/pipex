/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:50:59 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 21:39:48 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			c;
	unsigned char	*str;
	unsigned char	*str2;

	c = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str[c] != '\0' && str2[c] != '\0' && c < (n - 1))
	{
		if (str[c] != str2[c])
			return (str[c] - str2[c]);
		c++;
	}
	return (str[c] - str2[c]);
}
