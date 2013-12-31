/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:37:36 by dgermain          #+#    #+#             */
/*   Updated: 2013/11/29 10:45:17 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				count;
	unsigned char	*str;
	unsigned char	*str2;

	count = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str[count] != '\0' && str2[count] != '\0')
	{
		if (str[count] != str2[count])
			return (str[count] - str2[count]);
		count++;
	}
	return (str[count] - str2[count]);
}
