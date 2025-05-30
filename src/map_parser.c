/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albcamac <albcamac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:55:17 by albcamac          #+#    #+#             */
/*   Updated: 2025/05/29 17:36:58 by albcamac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(const char *path)
{
	int		fd;
	char	*buf;
	char	*content;
	ssize_t	bytes;
	char	tmp[1025];

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening the file");
		return (NULL);
	}
	content = ft_strdup("");
	bytes = read(fd, tmp, 1024);
	while (bytes > 0)
	{
		tmp[bytes] = '\0';
		buf = content;
		content = ft_strjoin(buf, tmp);
		free(buf);
		bytes = read(fd, tmp, 1024);
	}
	close(fd);
	return (content);
}

char	**parse_map(const char *path)
{
	char	*raw;
	char	**map;

	raw = read_file(path);
	if (!raw)
		return (NULL);
	map = ft_split(raw, '\n');
	free(raw);
	if (!map)
		return (NULL);
	if (has_empty_or_whitespace_line(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
