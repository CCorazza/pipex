/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:54:36 by ccorazza          #+#    #+#             */
/*   Updated: 2013/12/30 21:52:11 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4200

/*
** Structure for ft_strsplit
*/
typedef struct	s_split
{
	char		**tab;
	char		*str;
	int			i;
	int			d;
}				t_split;

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

/*
** Other useful functions
*/
char		*ft_get_path(char **envp, char *exec);
void		ft_manage_errors(char *command, char **envp);
void		ft_do_fork(char *path, char **envp, char **command);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putstr_fd(char const *s, int fd);
char		ft_strsub(char const *s, unsigned int start, size_t len);
static int	ft_words(char const *s, char c);
static int	ft_letters(char const *s, char c);
char		**ft_strsplit(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);

#endif /* !FT_PIPEX_H */
