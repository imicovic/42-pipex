/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicovic <imicovic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:41:06 by imicovic          #+#    #+#             */
/*   Updated: 2024/07/28 10:59:59 by imicovic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	get_start(const char *s1, const char *set)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == s1[start])
		{
			start++;
			i = 0;
			continue ;
		}
		i++;
	}
	return (start);
}

static int	get_end(const char *s1, const char *set)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(s1) - 1;
	while (set[i])
	{
		if (set[i] == s1[end])
		{
			end--;
			i = 0;
			continue ;
		}
		i++;
	}
	return (end);
}

static int	ft_strnlen(const char *s1, size_t maxlen)
{
	size_t	len;

	len = 0;
	while (s1[len] && len <= maxlen)
		len++;
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		end;
	int		start;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	str = malloc(ft_strnlen(&s1[start], end - start) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
