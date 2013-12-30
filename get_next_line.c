/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgermain <dgermain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 12:42:05 by dgermain          #+#    #+#             */
/*   Updated: 2013/12/30 14:13:27 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_check_n(char **rest, char *str, char **line)
{
	int		c;

	c = 0;
	*rest = ft_strdup(ft_strchr(str, '\n') + 1);
	if (*rest == NULL)
		return (-1);
	while (str[c] != '\n')
		c++;
	str[c] = '\0';
	*line = str;
	return (1);
}

static int	ft_read_buf(int const fd, char **buf, int *ret)
{
		*buf = ft_strnew(BUFF_SIZE);
		if (*buf == NULL)
			return (-1);
		*ret = read(fd, *buf, BUFF_SIZE);
		if (*ret == -1)
			return (-1);
		(*buf)[*ret] = '\0';
		return (*ret);
}

static int	ft_test_rest(char **rest, char **str, char **buf)
{
	char	*temp;

	if (*rest == NULL)
	{
		temp = *str;
		*str = ft_strjoin(temp, *buf);
		if (*str == NULL)
			return (-1);
		ft_memdel((void **)buf);
		ft_memdel((void **)&temp);
	}
	else
	{
		temp = *rest;
		ft_memdel((void **)str);
		*str = ft_strjoin(temp, *buf);
		if (*str == NULL)
			return (-1);
		ft_memdel((void **)rest);
		ft_memdel((void **)buf);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buf;
	char		*str;
	static char	*rest;

	ret = 1;
	str = ft_strnew(BUFF_SIZE);
	if (str == NULL)
		return (-1);
	while (ret > 0)
	{
		if (ft_read_buf(fd, &buf, &ret) == -1)
			return (-1);
		if (ft_test_rest(&rest, &str, &buf) == -1)
			return (-1);
		if (ft_strchr(str, '\n') != NULL)
			return (ft_check_n(&rest, str, line));
		ft_memdel((void **)&buf);
	}
	*line = str;
	if (*line != NULL && **line != '\0')
		return (1);
	return (0);
}
