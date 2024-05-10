/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 01:05:58 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/10 15:53:21 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static int	hook_width(t_engine *engine, char *line)
{
	char	*key;

	key = ft_strchr(line, '=');
	if (!key)
	{
		logerror(__FILE__, __LINE__, "Invalid config key");
		return (FAILURE);
	}
	engine->width = ft_atoi(key + 1);
	if (engine->width == 0)
	{
		logerror(__FILE__, __LINE__, "Invalid width value");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	hook_height(t_engine *engine, char *line)
{
	char	*key;

	key = ft_strchr(line, '=');
	if (!key)
	{
		logerror(__FILE__, __LINE__, "Invalid config key");
		return (FAILURE);
	}
	engine->height = ft_atoi(key + 1);
	if (engine->height == 0)
	{
		logerror(__FILE__, __LINE__, "Invalid height value");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	hook_title(t_engine *engine, char *line)
{
	char	*key;

	key = ft_strchr(line, '=');
	if (!key)
	{
		logerror(__FILE__, __LINE__, "Invalid config key");
		return (FAILURE);
	}
	engine->title = ft_strdup(key + 1);
	if (!engine->title)
	{
		logerror(__FILE__, __LINE__, "ft_strdup() failed");
		return (FAILURE);
	}
	return (SUCCESS);
}

static int	take_data(t_engine *engine, char *line)
{
	if (ft_strncmp(line, "width", 5) == 0)
		hook_width(engine, line);
	else if (ft_strncmp(line, "height ", 6) == 0)
		hook_height(engine, line);
	else if (ft_strncmp(line, "title ", 5) == 0)
		hook_title(engine, line);
	else
	{
		logerror(__FILE__, __LINE__, "Unknown config key");
		return (SUCCESS);
	}
	return (SUCCESS);
}

int	parse_config(t_engine *engine, t_list *config)
{
	char	*line;

	while (config)
	{
		line = ft_strtrim(config->content, " \t\n\r\v\f");
		logdebug(__FILE__, __LINE__, "Parsing config file...");
		if (line == NULL)
			break ;
		if (line[0] == '#' || line[0] == '\0')
		{
			free(line);
			config = config->next;
			continue ;
		}
		if (take_data(engine, line) == FAILURE)
		{
			free(line);
			return (FAILURE);
		}
		free(line);
		config = config->next;
	}
	return (SUCCESS);
}
