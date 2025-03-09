/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:55:01 by imicovic          #+#    #+#             */
/*   Updated: 2024/07/30 16:16:07 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>

int		file_check(char *name);
void	set_pipe(char *arg, char *envp[]);
void	execute(char *cmd, char *envp[]);
char	*find_path(char *cmd, char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		i;

	if (argc != 5)
		exit(0);
	i = 1;
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit(file_check(argv[1]));
	if (command_check(argc - 1, argv, envp))
		exit(127);
	outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (outfile == -1)
		file_check(argv[4]);
	dup2(infile, STDIN_FILENO);
	while (++i < argc - 2)
		set_pipe(argv[i], envp);
	pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
}

void	set_pipe(char *arg, char *envp[])
{
	pid_t	pid;
	int		pipfd[2];

	if (pipe(pipfd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(pipfd[0]);
		dup2(pipfd[1], STDOUT_FILENO);
		close(pipfd[1]);
		execute(arg, envp);
	}
	else
	{
		close(pipfd[1]);
		dup2(pipfd[0], STDIN_FILENO);
		close(pipfd[0]);
	}
}

void	execute(char *arg, char *envp[])
{
	char	**cmd;
	char	*path;

	cmd = ft_split(arg, ' ');
	path = find_path(cmd[0], envp);
	if (execve(path, cmd, envp) == -1)
		perror("execve");
}

char	*find_path(char *cmd, char *envp[])
{
	int		i;
	char	*s;
	char	**env;

	i = -1;
	env = set_env(envp);
	while (env[++i])
	{
		s = ft_strjoin(env[i], cmd);
		if (!access(s, F_OK))
		{
			tab_free(env);
			return (s);
		}
		free(s);
	}
	tab_free(env);
	return (NULL);
}

int	file_check(char *name)
{
	if (errno == ENOENT)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(name, 2);
	}
	else
	{
		ft_putstr_fd("pipex: permission denied: ", 2);
		ft_putendl_fd(name, 2);
	}
	exit(1);
}
