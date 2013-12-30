/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:54:36 by ccorazza          #+#    #+#             */
/*   Updated: 2013/12/30 14:13:04 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4200

/*
** Useful Functions for GetNextLine
*/
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
char		*ft_strnew(size_t size);
void		ft_memdel(void **ap);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);

/*
** GetNextLine Functions
*/

static int	ft_check_n(char **rest, char *str, char **line);
static int	ft_read_buf(int const fd, char **buf, int *ret);
static int	ft_test_rest(char **rest, char **str, char **buf);
int			get_next_line(int const fd, char **line);

#endif /* !FT_PIPEX_H */
