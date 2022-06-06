/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:11:46 by mmarcele          #+#    #+#             */
/*   Updated: 2022/01/03 13:29:59 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	length;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	length = (ft_strlen(s1) + ft_strlen(s2) + 1);
	output = malloc(sizeof(char) * length);
	if (!output)
		return (NULL);
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		output[i++] = s2[j++];
	output[i] = '\0';
	ft_free((char *)s1);
	return (output);
}

char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

int	ft_islf(char ch)
{
	if (ch == '\n')
		return (1);
	return (0);
}
