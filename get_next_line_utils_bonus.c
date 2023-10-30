/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:26:16 by davioliv          #+#    #+#             */
/*   Updated: 2023/10/30 11:15:02 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*add_line(char *buf, char *c)
{
	char	*add;
	int		i;
	int		l;

	if (!c)
	{
		c = malloc(1 * sizeof(char));
		if (!c)
			return (NULL);
		c[0] = '\0';
	}
	if (!c || !buf)
		return (NULL);
	add = malloc(sizeof(char) * (ft_strlen(buf) + ft_strlen(c) + 1));
	if (!add)
		return (NULL);
	i = -1;
	l = 0;
	while (c[++i] != '\0')
		add[i] = c[i];
	while (buf[l] != '\0')
		add[i++] = buf[l++];
	add[ft_strlen(buf) + ft_strlen(c)] = '\0';
	free(c);
	return (add);
}

char	*ft_isnewline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *c)
{
	char	*buf;
	int		line_len;

	line_len = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_isnewline(c) && line_len != 0)
	{
		line_len = read(fd, buf, BUFFER_SIZE);
		if (line_len == -1)
		{
			free(buf);
			free(c);
			return (NULL);
		}
		buf[line_len] = '\0';
		c = add_line(buf, c);
	}
	free(buf);
	return (c);
}

char	*insert_line(char *c)
{
	char	*str;
	int		i;

	i = 0;
	if (!c[i])
		return (NULL);
	while (c[i] && c[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
	{
		str[i] = c[i];
		i++;
	}
	if (c[i] == '\n')
	{
		str[i] = c[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*reset_line(char *c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c[i] != '\n' && c[i] != '\0')
		i++;
	if (!c[i])
	{
		free(c);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(c) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (c[i] != '\0')
		str[j++] = c[i++];
	str[j] = '\0';
	free(c);
	return (str);
}
