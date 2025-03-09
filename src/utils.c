/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:48:30 by imicovic          #+#    #+#             */
/*   Updated: 2024/07/30 16:16:27 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	tab_free(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

char	**set_env(char *envp[])
{
	int		i;
	char	*s;
	char	**env;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
	s = ft_strtrim(envp[i], "PATH=");
	env = ft_split(s, ':');
	i = -1;
	while (env[++i])
		ft_strlcat(env[i], "/", ft_strlen(env[i]) + 2);
	free(s);
	return (env);
}

void	output(char *cmd)
{
	ft_putstr_fd("pipex: no such command: ", 2);
	ft_putendl_fd(cmd, 2);
}

int	access_check(char *env[], char *cmd)
{
	int		i;
	char	*s;

	i = -1;
	while (env[++i])
	{
		s = ft_strjoin(env[i], cmd);
		if (access(s, F_OK) == 0)
		{
			free(s);
			return (0);
		}
		free(s);
	}
	return (1);
}

int	command_check(int argc, char *argv[], char *envp[])
{
	char	**env;
	char	**cmd;
	int		flag;
	int		i;

	env = set_env(envp);
	flag = 0;
	i = 1;
	while (++i < argc)
	{
		cmd = ft_split(argv[i], ' ');
		if (access_check(env, cmd[0]))
		{
			flag = 1;
			output(cmd[0]);
		}
		tab_free(cmd);
	}
	tab_free(env);
	return (flag);
}
