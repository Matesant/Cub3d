/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:30:02 by almarcos          #+#    #+#             */
/*   Updated: 2024/07/31 02:33:04 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*replace(char *line);
static int	count_tabs(char *line);

void	replace_tabs_for_spaces(char *raw_data[])
{
	int		line;
	char	*to_free;

	line = -1;
	while (raw_data[++line])
	{
		if (count_tabs(raw_data[line]) > 0)
		{
			to_free = raw_data[line];
			raw_data[line] = replace(raw_data[line]);
			free(to_free);
		}
	}
}

static int	count_tabs(char *line)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == '\t')
			count++;
		line++;
	}
	return (count);
}

static char	*replace(char *line)
{
	int		replaced_len;
	char	*replaced;
	int		i;
	int		j;

	replaced_len = ft_strlen(line) + (count_tabs(line) * 4);
	replaced = ft_calloc(replaced_len, sizeof(char *));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			ft_memset(replaced + j, ' ', 4);
			j += 4;
			i++;
			continue ;
		}
		replaced[j] = line[i];
		i++;
		j++;
	}
	return (replaced);
}
