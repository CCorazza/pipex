/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 12:50:51 by ccorazza          #+#    #+#             */
/*   Updated: 2013/12/30 21:33:05 by dgermain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/*Penser a gerer les erreurs pour argc (trop/pas assez d'arguments)*/
int		main(int argc, char **argv, char **envp)
{
	char	*path;
	char	**command;

	path = NULL;
	get_next_line(0, &path);
	command = /*fonction qui separe fichiers et commandes...*/;
	path = ft_get_path(envp, command[0]);
	command[0] = path;
	ft_do_fork(path, envp, command);
	return (0);
}

/*
** Gets the path and returns it if existing, readable AND executable
*/
char	*ft_get_path(char **envp, char *exec)
{
	int		c;
	char	*cpy;
	char	**path;

	c = 0;
	exec = ft_strjoin("/", exec);
	while (envp[c])
	{
		if (ft_strncmp("PATH=", envp[c], 5) == 0)
			cpy = ft_strdup(envp[c]);
		c++;
	}
	path = ft_strsplit(cpy, ':');
	c = 0;
	while (path[c])
	{
		cpy = ft_strjoin(path[c], exec);
		if (access(cpy, F_OK) == 0 && access(cpy, X_OK) == 0
			&& access(cpy, R_OK) == 0)
			return (cpy);
		c++;
	}
	exec = ft_strsub(exec, 1, (ft_strlen(exec) - 1));
	ft_manage_errors(exec, envp);
	return (NULL);
}

/*
** If command is not found in env, sends an error message
*/
void	ft_manage_errors(char *command, char **envp)
{
	int		c;

	c = 0;
	while (envp[c])
	{
		if (ft_strcmp(command, envp[c]) != 0)
		{
			ft_putstr_fd("zsh: command not found: ", 2);
			ft_putendl_fd(command, 2);
			return ;
		}
		c++;
	}
	return ;
}

void	ft_do_fork(char *path, char **envp, char **command)
{
	pid_t	pid;
	int		pipefd[2]; /* a-t-on le droit? > NORME*/

	pid = fork();
	if (pipe(pipefd) == -1)
	{
		ft_putstr_fd("Error: pipe went wrong.\n", 2);
		return (-1);
	}
	if (pid < 0)
	{
		ft_putstr_fd("Error: fork went wrong.\n", 2);
		return (-1);
	}
	else if (pid == 0)
	{
		close(pipefd[1]);
		execve(path, command, envp); /*execute la commande >> a changer pour executer les deux*/
		return (0);
	}
	else
		wait(NULL);
	return ;
}
