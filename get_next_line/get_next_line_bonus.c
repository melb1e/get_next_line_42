/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:16:55 by mmarcele          #+#    #+#             */
/*   Updated: 2022/01/03 13:36:35 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_epilogue(char *files)
{
	size_t	i;
	size_t	j;
	char	*output;

	i = 0;
	j = 0;
	if (!files)
		return (NULL);
	while (files[i] && files[i] != '\n')
		i++;
	if (files[i] == '\0')
		return (ft_free(files));
	i += ft_islf(files[i]);
	output = malloc(sizeof(char) * (ft_strlen(files) - i + 1));
	if (!output)
		return (NULL);
	while (files[i])
	{
		output[j] = files[i];
		i++;
		j++;
	}
	output[j] = '\0';
	ft_free(files);
	return (output);
}

static char	*ft_fill(char *files)
{
	size_t	length;
	char	*output;

	length = 0;
	if (!files || !files[0])
		return (NULL);
	while (files[length] && files[length] != '\n')
		length++;
	length += ft_islf(files[length]);
	output = malloc(sizeof(char) * (length + 1));
	if (!output)
		return (0);
	length = 0;
	while (files[length] && files[length] != '\n')
	{
		output[length] = files[length];
		length++;
	}
	if (files[length] == '\n')
	{
		output[length] = files[length];
		length++;
	}
	output[length] = '\0';
	return (output);
}

static int	ft_has_lf(char *files)
{
	size_t	i;

	i = 0;
	if (!files)
		return (0);
	while (files[i])
	{
		if (files[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*files[OPEN_MAX];
	char		*buff_str;
	char		*line;
	int			read_value;

	read_value = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff_str)
		return (NULL);
	while (!ft_has_lf(files[fd]) && read_value != 0)
	{
		read_value = read(fd, buff_str, BUFFER_SIZE);
		if (read_value == -1)
			return (ft_free(buff_str));
		buff_str[read_value] = '\0';
		files[fd] = ft_strjoin(files[fd], buff_str);
	}
	ft_free(buff_str);
	line = ft_fill(files[fd]);
	files[fd] = ft_epilogue(files[fd]);
	return (line);
}
