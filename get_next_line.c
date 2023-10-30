/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:07:37 by davioliv          #+#    #+#             */
/*   Updated: 2023/08/31 18:24:11 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*c;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = read_line(fd, c);
	if (!c)
		return (NULL);
	line = insert_line(c);
	c = reset_line(c);
	return (line);
}

/*int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	printf("%s", get_next_line(fd));
	return (0);
}*/
