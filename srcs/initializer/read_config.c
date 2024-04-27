/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 00:40:23 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 01:19:39 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_engine.h"
#include <fcntl.h>

static int	open_config_file(void)
{
	int	fd;

	fd = open(CONFIG_FILE, O_RDONLY);
	logdebug(__FILE__, __LINE__, "Opening config file");
	if (fd == -1)
	{
		logerror(__FILE__, __LINE__, "open() failed");
		return (FAILURE);
	}
	return (fd);
}

static t_list	**read_config_file(int fd)
{
	char	*raw_line;
	t_list	**config;
	t_list	*node;

	config = ft_calloc(1, sizeof(t_list *));
	if (!config)
	{
		logerror(__FILE__, __LINE__, "ft_calloc() failed");
		return (NULL);
	}
	while (true)
	{
		raw_line = get_next_line(fd);
		logdebug(__FILE__, __LINE__, "Reading config file...");
		logdebug(__FILE__, __LINE__, raw_line);
		if (!raw_line)
			break ;
		node = ft_lstnew(raw_line);
		if (!node)
		{
			logerror(__FILE__, __LINE__, "ft_lstnew() failed");
			return (NULL);
		}
		ft_lstadd_back(config, node);
	}
	return (config);
}

int	read_config(t_engine *engine)
{
	int		fd;
	t_list	**config;

	fd = open_config_file();
	if (fd == FAILURE)
		return (FAILURE);
	config = read_config_file(fd);
	if (config == NULL)
	{
		close(fd);
		return (FAILURE);
	}
	if (parse_config(engine, config) == FAILURE)
	{
		close(fd);
		ft_lstclear(config, free);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}
