/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42wolfsburg.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 10:55:19 by imicovic          #+#    #+#             */
/*   Updated: 2024/07/29 20:54:09 by igormic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

void	tab_free(char **ptr);
void	output(char *cmd);
int		command_check(int argc, char *argv[], char *envp[]);
int		command_check(int argc, char *argv[], char *envp[]);
char	**set_env(char *envp[]);

#endif
