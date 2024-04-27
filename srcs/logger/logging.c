/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:55:04 by jbrousse          #+#    #+#             */
/*   Updated: 2024/04/28 00:34:55 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "logging.h"

int	*get_logger_fd(void)
{
	static int	__fd_logger = -1;

	return (&__fd_logger);
}

int	init_logger(void)
{
	int	*fd;

	fd = get_logger_fd();
	*fd = open(LOGFILE, O_CREAT | O_WRONLY | LOGFLAGS, LOGFILE_MODE);
	if (*fd == -1)
	{
		ft_putendl_fd("Error: could not open logfile", 2);
		return (-1);
	}
	return (*fd);
}

void	close_logfile(void)
{
	int	*fd;

	fd = get_logger_fd();
	if (*fd != -1)
		close(*fd);
}
