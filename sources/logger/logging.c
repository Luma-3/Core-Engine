/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:55:04 by jbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 17:57:56 by jbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "logging.h"

int	*__get_logger_fd(void)
{
	static int	__fd_logger = -1;

	return (&__fd_logger);
}

int	__init_logger(void)
{
	int	*fd;

	fd = __get_logger_fd();
	*fd = open(LOGFILE, O_CREAT | O_WRONLY | LOGFLAGS, LOGFILE_MODE);
	if (*fd == -1)
	{
		ft_putendl_fd("Error: could not open logfile", 2);
		return (-1);
	}
	return (*fd);
}

void	__close_logfile(void)
{
	int	*fd;

	fd = __get_logger_fd();
	if (*fd != -1)
		close(*fd);
}
